cmd_arch/x86/hyperv/built-in.o :=  ld -m elf_x86_64   -r -o arch/x86/hyperv/built-in.o arch/x86/hyperv/hv_init.o arch/x86/hyperv/mmu.o ; scripts/mod/modpost arch/x86/hyperv/built-in.o
