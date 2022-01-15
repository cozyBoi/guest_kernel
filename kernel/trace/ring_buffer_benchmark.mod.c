#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x28950ef1, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x6d044c26, __VMLINUX_SYMBOL_STR(param_ops_uint) },
	{ 0x838b13e7, __VMLINUX_SYMBOL_STR(ring_buffer_free) },
	{ 0x42f90a31, __VMLINUX_SYMBOL_STR(kthread_stop) },
	{ 0x889c0220, __VMLINUX_SYMBOL_STR(set_user_nice) },
	{ 0xaeb3fda3, __VMLINUX_SYMBOL_STR(sched_setscheduler) },
	{ 0xc35e4b4e, __VMLINUX_SYMBOL_STR(kthread_create_on_node) },
	{ 0xf4fc2d6c, __VMLINUX_SYMBOL_STR(__ring_buffer_alloc) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0x7b0f1ab3, __VMLINUX_SYMBOL_STR(ring_buffer_free_read_page) },
	{ 0x6a6cafd2, __VMLINUX_SYMBOL_STR(ring_buffer_read_page) },
	{ 0x4aadeb9a, __VMLINUX_SYMBOL_STR(ring_buffer_alloc_read_page) },
	{ 0x9062c322, __VMLINUX_SYMBOL_STR(ring_buffer_consume) },
	{ 0xc0a3d105, __VMLINUX_SYMBOL_STR(find_next_bit) },
	{ 0x930484aa, __VMLINUX_SYMBOL_STR(cpu_online_mask) },
	{ 0xfe7c4287, __VMLINUX_SYMBOL_STR(nr_cpu_ids) },
	{ 0x4b06d2e7, __VMLINUX_SYMBOL_STR(complete) },
	{ 0xf0fdf6cb, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0xd62c833f, __VMLINUX_SYMBOL_STR(schedule_timeout) },
	{ 0xc72e1233, __VMLINUX_SYMBOL_STR(__trace_bprintk) },
	{ 0xd9ecb670, __VMLINUX_SYMBOL_STR(ring_buffer_overruns) },
	{ 0x4e109192, __VMLINUX_SYMBOL_STR(ring_buffer_entries) },
	{ 0xa1c76e0a, __VMLINUX_SYMBOL_STR(_cond_resched) },
	{ 0x918ad429, __VMLINUX_SYMBOL_STR(ring_buffer_lock_reserve) },
	{ 0xd87601cc, __VMLINUX_SYMBOL_STR(ring_buffer_unlock_commit) },
	{ 0x54efb5d6, __VMLINUX_SYMBOL_STR(cpu_number) },
	{ 0x9621849f, __VMLINUX_SYMBOL_STR(ring_buffer_event_data) },
	{ 0x4f68e5c9, __VMLINUX_SYMBOL_STR(do_gettimeofday) },
	{ 0xb1e25684, __VMLINUX_SYMBOL_STR(__trace_bputs) },
	{ 0x6d0aba34, __VMLINUX_SYMBOL_STR(wait_for_completion) },
	{ 0xe65cdceb, __VMLINUX_SYMBOL_STR(wake_up_process) },
	{ 0xddd58dc0, __VMLINUX_SYMBOL_STR(ring_buffer_reset) },
	{ 0xf432dd3d, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0xb3f7646e, __VMLINUX_SYMBOL_STR(kthread_should_stop) },
	{ 0x1000e51, __VMLINUX_SYMBOL_STR(schedule) },
	{ 0xb8c7ff88, __VMLINUX_SYMBOL_STR(current_task) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "7B4DF46C3BF9CD1C6FC9021");
MODULE_INFO(rhelversion, "7.9");
#ifdef RETPOLINE
	MODULE_INFO(retpoline, "Y");
#endif
#ifdef CONFIG_MPROFILE_KERNEL
	MODULE_INFO(mprofile, "Y");
#endif
