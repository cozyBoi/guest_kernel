cmd_arch/x86/ia32/built-in.o :=  ld -m elf_x86_64   -r -o arch/x86/ia32/built-in.o arch/x86/ia32/ia32entry.o arch/x86/ia32/sys_ia32.o arch/x86/ia32/ia32_signal.o arch/x86/ia32/nosyscall.o arch/x86/ia32/syscall_ia32.o arch/x86/ia32/audit.o ; scripts/mod/modpost arch/x86/ia32/built-in.o
