cmd_arch/x86/vdso/built-in.o :=  ld -m elf_x86_64   -r -o arch/x86/vdso/built-in.o arch/x86/vdso/vma.o arch/x86/vdso/vdso.o arch/x86/vdso/vdso32.o arch/x86/vdso/vdso32-setup.o arch/x86/vdso/vdso-syms.lds arch/x86/vdso/vdso32-syms.lds ; scripts/mod/modpost arch/x86/vdso/built-in.o
