cmd_arch/x86/purgatory/built-in.o :=  ld -m elf_x86_64   -r -o arch/x86/purgatory/built-in.o arch/x86/purgatory/kexec-purgatory.o ; scripts/mod/modpost arch/x86/purgatory/built-in.o
