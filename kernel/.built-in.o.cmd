cmd_kernel/built-in.o :=  ld -m elf_x86_64   -r -o kernel/built-in.o kernel/fork.o kernel/exec_domain.o kernel/panic.o kernel/printk.o kernel/cpu.o kernel/exit.o kernel/itimer.o kernel/time.o kernel/softirq.o kernel/resource.o kernel/sysctl.o kernel/sysctl_binary.o kernel/capability.o kernel/ptrace.o kernel/timer.o kernel/user.o kernel/signal.o kernel/sys.o kernel/kmod.o kernel/workqueue.o kernel/pid.o kernel/task_work.o kernel/rcupdate.o kernel/extable.o kernel/params.o kernel/posix-timers.o kernel/kthread.o kernel/wait.o kernel/sys_ni.o kernel/posix-cpu-timers.o kernel/mutex.o kernel/hrtimer.o kernel/rwsem.o kernel/nsproxy.o kernel/srcu.o kernel/semaphore.o kernel/notifier.o kernel/ksysfs.o kernel/cred.o kernel/async.o kernel/range.o kernel/groups.o kernel/lglock.o kernel/smpboot.o kernel/ucount.o kernel/rh_taint.o kernel/rh_kabi.o kernel/rh_shadowman.o kernel/usr_hypercall.o kernel/sched/built-in.o kernel/power/built-in.o kernel/cpu/built-in.o kernel/livepatch/built-in.o kernel/kcmp.o kernel/freezer.o kernel/profile.o kernel/stacktrace.o kernel/time/built-in.o kernel/futex.o kernel/futex_compat.o kernel/rtmutex.o kernel/dma.o kernel/smp.o kernel/spinlock.o kernel/qspinlock.o kernel/qrwlock.o kernel/qrwlock_gen.o kernel/osq_lock.o kernel/uid16.o kernel/system_keyring.o kernel/system_certificates.o kernel/module.o kernel/module_signing.o kernel/modsign_uefi.o kernel/kallsyms.o kernel/acct.o kernel/crash_core.o kernel/kexec_core.o kernel/kexec.o kernel/kexec_file.o kernel/compat.o kernel/cgroup.o kernel/cgroup_freezer.o kernel/cgroup_pids.o kernel/cpuset.o kernel/utsname.o kernel/user_namespace.o kernel/pid_namespace.o kernel/stop_machine.o kernel/audit.o kernel/auditfilter.o kernel/auditsc.o kernel/audit_watch.o kernel/audit_fsnotify.o kernel/audit_tree.o kernel/kprobes.o kernel/debug/built-in.o kernel/hung_task.o kernel/watchdog.o kernel/irq/built-in.o kernel/seccomp.o kernel/rcutree.o kernel/relay.o kernel/utsname_sysctl.o kernel/delayacct.o kernel/taskstats.o kernel/tsacct.o kernel/tracepoint.o kernel/elfcore.o kernel/trace/built-in.o kernel/irq_work.o kernel/bpf/built-in.o kernel/events/built-in.o kernel/user-return-notifier.o kernel/padata.o kernel/crash_dump.o kernel/jump_label.o kernel/context_tracking.o kernel/iomem.o kernel/memremap.o ; scripts/mod/modpost kernel/built-in.o