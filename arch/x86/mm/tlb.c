#include <linux/init.h>

#include <linux/mm.h>
#include <linux/spinlock.h>
#include <linux/smp.h>
#include <linux/interrupt.h>
#include <linux/export.h>
#include <linux/cpu.h>

#include <asm/tlbflush.h>
#include <asm/mmu_context.h>
#include <asm/cache.h>
#include <asm/apic.h>
#include <asm/uv/uv.h>
#include <linux/debugfs.h>

DEFINE_PER_CPU_SHARED_ALIGNED(struct tlb_state, cpu_tlbstate)
			= { &init_mm, 0, };

/*
 *	Smarter SMP flushing macros.
 *		c/o Linus Torvalds.
 *
 *	These mean you can really definitely utterly forget about
 *	writing to user space from interrupts. (Its not allowed anyway).
 *
 *	Optimizations Manfred Spraul <manfred@colorfullife.com>
 *
 *	More scalable flush, from Andi Kleen
 *
 *	Implement flush IPI by CALL_FUNCTION_VECTOR, Alex Shi
 */

#ifdef CONFIG_SMP

struct flush_tlb_info {
	struct mm_struct *flush_mm;
	unsigned long flush_start;
	unsigned long flush_end;
};

/*
 * We cannot call mmdrop() because we are in interrupt context,
 * instead update mm->cpu_vm_mask.
 */
void leave_mm(int cpu)
{
	struct mm_struct *active_mm = this_cpu_read(cpu_tlbstate.active_mm);
	if (this_cpu_read(cpu_tlbstate.state) == TLBSTATE_OK)
		BUG();
	if (cpumask_test_cpu(cpu, mm_cpumask(active_mm))) {
		cpumask_clear_cpu(cpu, mm_cpumask(active_mm));
		load_cr3(swapper_pg_dir);
	}
}
EXPORT_SYMBOL_GPL(leave_mm);

#endif /* CONFIG_SMP */

void switch_mm(struct mm_struct *prev, struct mm_struct *next,
		struct task_struct *tsk)
{
	unsigned long flags;

	local_irq_save(flags);
	switch_mm_irqs_off(prev, next, tsk);
	local_irq_restore(flags);
}

void switch_mm_irqs_off(struct mm_struct *prev, struct mm_struct *next,
			struct task_struct *tsk)
{
	unsigned cpu = smp_processor_id();

	if (likely(prev != next)) {
#ifdef CONFIG_SMP
		this_cpu_write(cpu_tlbstate.state, TLBSTATE_OK);
		this_cpu_write(cpu_tlbstate.active_mm, next);
#endif
		cpumask_set_cpu(cpu, mm_cpumask(next));

#ifndef CONFIG_PREEMPT_RCU
		spec_ctrl_ibpb_if_different_creds(tsk);
#else
		spec_ctrl_ibpb();
#endif

		/*
		 * Re-load page tables.
		 *
		 * This logic has an ordering constraint:
		 *
		 *  CPU 0: Write to a PTE for 'next'
		 *  CPU 0: load bit 1 in mm_cpumask.  if nonzero, send IPI.
		 *  CPU 1: set bit 1 in next's mm_cpumask
		 *  CPU 1: load from the PTE that CPU 0 writes (implicit)
		 *
		 * We need to prevent an outcome in which CPU 1 observes
		 * the new PTE value and CPU 0 observes bit 1 clear in
		 * mm_cpumask.  (If that occurs, then the IPI will never
		 * be sent, and CPU 0's TLB will contain a stale entry.)
		 *
		 * The bad outcome can occur if either CPU's load is
		 * reordered before that CPU's store, so both CPUs must
		 * execute full barriers to prevent this from happening.
		 *
		 * Thus, switch_mm needs a full barrier between the
		 * store to mm_cpumask and any operation that could load
		 * from next->pgd.  TLB fills are special and can happen
		 * due to instruction fetches or for no reason at all,
		 * and neither LOCK nor MFENCE orders them.
		 * Fortunately, load_cr3() is serializing and gives the
		 * ordering guarantee we need.
		 *
		 */
		load_cr3(next->pgd);

		/* Stop flush ipis for the previous mm */
		cpumask_clear_cpu(cpu, mm_cpumask(prev));

		/* Load the LDT, if the LDT is different:
		 * never set context.ldt to NULL while the mm still
		 * exists.  That means that next->context.ldt !=
		 * prev->context.ldt, because mms never share an LDT.
		*/
		if (unlikely(prev->context.ldt != next->context.ldt))
			load_mm_ldt(next);
	}
#ifdef CONFIG_SMP
	  else {
		this_cpu_write(cpu_tlbstate.state, TLBSTATE_OK);
		BUG_ON(this_cpu_read(cpu_tlbstate.active_mm) != next);

		if (!cpumask_test_cpu(cpu, mm_cpumask(next))) {
			/*
			 * On established mms, the mm_cpumask is only changed
			 * from irq context, from ptep_clear_flush() while in
			 * lazy tlb mode, and here. Irqs are blocked during
			 * schedule, protecting us from simultaneous changes.
			 */
			cpumask_set_cpu(cpu, mm_cpumask(next));

			/*
			 * We were in lazy tlb mode and leave_mm disabled
			 * tlb flush IPI delivery. We must reload CR3
			 * to make sure to use no freed page tables.
			 *
			 * As above, load_cr3() is serializing and orders TLB
			 * fills with respect to the mm_cpumask write.
			 */
			load_cr3(next->pgd);
			load_mm_ldt(next);
		}
	}
#endif
}

#ifdef CONFIG_SMP

/*
 * The flush IPI assumes that a thread switch happens in this order:
 * [cpu0: the cpu that switches]
 * 1) switch_mm() either 1a) or 1b)
 * 1a) thread switch to a different mm
 * 1a1) set cpu_tlbstate to TLBSTATE_OK
 *	Now the tlb flush NMI handler flush_tlb_func won't call leave_mm
 *	if cpu0 was in lazy tlb mode.
 * 1a2) update cpu active_mm
 *	Now cpu0 accepts tlb flushes for the new mm.
 * 1a3) cpu_set(cpu, new_mm->cpu_vm_mask);
 *	Now the other cpus will send tlb flush ipis.
 * 1a4) change cr3.
 * 1a5) cpu_clear(cpu, old_mm->cpu_vm_mask);
 *	Stop ipi delivery for the old mm. This is not synchronized with
 *	the other cpus, but flush_tlb_func ignore flush ipis for the wrong
 *	mm, and in the worst case we perform a superfluous tlb flush.
 * 1b) thread switch without mm change
 *	cpu active_mm is correct, cpu0 already handles flush ipis.
 * 1b1) set cpu_tlbstate to TLBSTATE_OK
 * 1b2) test_and_set the cpu bit in cpu_vm_mask.
 *	Atomically set the bit [other cpus will start sending flush ipis],
 *	and test the bit.
 * 1b3) if the bit was 0: leave_mm was called, flush the tlb.
 * 2) switch %%esp, ie current
 *
 * The interrupt must handle 2 special cases:
 * - cr3 is changed before %%esp, ie. it cannot use current->{active_,}mm.
 * - the cpu performs speculative tlb reads, i.e. even if the cpu only
 *   runs in kernel space, the cpu could load tlb entries for user space
 *   pages.
 *
 * The good news is that cpu_tlbstate is local to each cpu, no
 * write/read ordering problems.
 */

/*
 * TLB flush funcation:
 * 1) Flush the tlb entries if the cpu uses the mm that's being flushed.
 * 2) Leave the mm if we are in the lazy tlb mode.
 */
static void flush_tlb_func(void *info)
{
	struct flush_tlb_info *f = info;

	inc_irq_stat(irq_tlb_count);

	if (f->flush_mm != this_cpu_read(cpu_tlbstate.active_mm))
		return;

	if (this_cpu_read(cpu_tlbstate.state) == TLBSTATE_OK) {
		if (f->flush_end == TLB_FLUSH_ALL)
			local_flush_tlb();
		else if (!f->flush_end)
			__flush_tlb_single(f->flush_start);
		else {
			unsigned long addr;
			addr = f->flush_start;
			while (addr < f->flush_end) {
				__flush_tlb_single(addr);
				addr += PAGE_SIZE;
			}
		}
	} else
		leave_mm(smp_processor_id());

}

void native_flush_tlb_others(const struct cpumask *cpumask,
				 struct mm_struct *mm, unsigned long start,
				 unsigned long end)
{
	struct flush_tlb_info info;
	info.flush_mm = mm;
	info.flush_start = start;
	info.flush_end = end;

	if (is_uv_system()) {
		unsigned int cpu;

		cpu = smp_processor_id();
		cpumask = uv_flush_tlb_others(cpumask, mm, start, end, cpu);
		if (cpumask)
			smp_call_function_many(cpumask, flush_tlb_func,
								&info, 1);
		return;
	}
	smp_call_function_many(cpumask, flush_tlb_func, &info, 1);
}

void flush_tlb_mm_range(struct mm_struct *mm, unsigned long start,
				unsigned long end, unsigned long vmflag)
{
	bool need_flush_others_all = true;
	unsigned long addr;
	unsigned act_entries, tlb_entries = 0;
	unsigned long nr_base_pages;

	preempt_disable();
	if (current->active_mm != mm) {
		/* Synchronize with switch_mm. */
		smp_mb();

		goto out;
	}

	if (!current->mm) {
		leave_mm(smp_processor_id());

		/* Synchronize with switch_mm. */
		smp_mb();

		goto out;
	}

	if (end == TLB_FLUSH_ALL || tlb_flushall_shift == -1
					|| vmflag & VM_HUGETLB) {
		local_flush_tlb();
		goto out;
	}

	/* In modern CPU, last level tlb used for both data/ins */
	if (vmflag & VM_EXEC)
		tlb_entries = tlb_lli_4k[ENTRIES];
	else
		tlb_entries = tlb_lld_4k[ENTRIES];

	/* Assume all of TLB entries was occupied by this task */
	act_entries = tlb_entries >> tlb_flushall_shift;
	act_entries = mm->total_vm > act_entries ? act_entries : mm->total_vm;
	nr_base_pages = (end - start) >> PAGE_SHIFT;

	/*
	 * Both branches below are implicit full barriers (MOV to CR or
	 * INVLPG) that synchronize with switch_mm.
	 */
	if (nr_base_pages > act_entries) {
		local_flush_tlb();
	} else {
		need_flush_others_all = false;
		/* flush range by one by one 'invlpg' */
		for (addr = start; addr < end;	addr += PAGE_SIZE)
			__flush_tlb_single(addr);
	}
out:
	if (need_flush_others_all) {
		start = 0UL;
		end = TLB_FLUSH_ALL;
	}
	if (cpumask_any_but(mm_cpumask(mm), smp_processor_id()) < nr_cpu_ids)
		flush_tlb_others(mm_cpumask(mm), mm, start, end);
	preempt_enable();
}

void flush_tlb_page(struct vm_area_struct *vma, unsigned long start)
{
	struct mm_struct *mm = vma->vm_mm;

	preempt_disable();

	if (current->active_mm == mm) {
		if (current->mm) {
			/*
			 * Implicit full barrier (INVLPG) that synchronizes
			 * with switch_mm.
			 */
			__flush_tlb_one(start);
		} else {
			leave_mm(smp_processor_id());

			/* Synchronize with switch_mm. */
			smp_mb();
		}
	}

	if (cpumask_any_but(mm_cpumask(mm), smp_processor_id()) < nr_cpu_ids)
		flush_tlb_others(mm_cpumask(mm), mm, start, 0UL);

	preempt_enable();
}

static void do_flush_tlb_all(void *info)
{
	__flush_tlb_all();
	if (this_cpu_read(cpu_tlbstate.state) == TLBSTATE_LAZY)
		leave_mm(smp_processor_id());
}

void flush_tlb_all(void)
{
	on_each_cpu(do_flush_tlb_all, NULL, 1);
}

static void do_kernel_range_flush(void *info)
{
	struct flush_tlb_info *f = info;
	unsigned long addr;

	/* flush range by one by one 'invlpg' */
	for (addr = f->flush_start; addr < f->flush_end; addr += PAGE_SIZE)
		__flush_tlb_single(addr);
}

void flush_tlb_kernel_range(unsigned long start, unsigned long end)
{
	unsigned act_entries;
	struct flush_tlb_info info;

	/* In modern CPU, last level tlb used for both data/ins */
	act_entries = tlb_lld_4k[ENTRIES];

	/* Balance as user space task's flush, a bit conservative */
	if (end == TLB_FLUSH_ALL || tlb_flushall_shift == -1 ||
		(end - start) >> PAGE_SHIFT > act_entries >> tlb_flushall_shift)

		on_each_cpu(do_flush_tlb_all, NULL, 1);
	else {
		info.flush_start = start;
		info.flush_end = end;
		on_each_cpu(do_kernel_range_flush, &info, 1);
	}
}
#endif /* CONFIG_SMP */

#ifdef CONFIG_DEBUG_TLBFLUSH
static ssize_t tlbflush_read_file(struct file *file, char __user *user_buf,
			     size_t count, loff_t *ppos)
{
	char buf[32];
	unsigned int len;

	len = sprintf(buf, "%hd\n", tlb_flushall_shift);
	return simple_read_from_buffer(user_buf, count, ppos, buf, len);
}

static ssize_t tlbflush_write_file(struct file *file,
		 const char __user *user_buf, size_t count, loff_t *ppos)
{
	char buf[32];
	ssize_t len;
	s8 shift;

	len = min(count, sizeof(buf) - 1);
	if (copy_from_user(buf, user_buf, len))
		return -EFAULT;

	buf[len] = '\0';
	if (kstrtos8(buf, 0, &shift))
		return -EINVAL;

	if (shift < -1 || shift >= BITS_PER_LONG)
		return -EINVAL;

	tlb_flushall_shift = shift;
	return count;
}

static const struct file_operations fops_tlbflush = {
	.read = tlbflush_read_file,
	.write = tlbflush_write_file,
	.llseek = default_llseek,
};

static int __init create_tlb_flushall_shift(void)
{
	debugfs_create_file("tlb_flushall_shift", S_IRUSR | S_IWUSR,
			    arch_debugfs_dir, NULL, &fops_tlbflush);
	return 0;
}
late_initcall(create_tlb_flushall_shift);
#endif
