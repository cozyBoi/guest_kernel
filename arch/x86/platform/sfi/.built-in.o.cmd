cmd_arch/x86/platform/sfi/built-in.o :=  ld -m elf_x86_64   -r -o arch/x86/platform/sfi/built-in.o arch/x86/platform/sfi/sfi.o ; scripts/mod/modpost arch/x86/platform/sfi/built-in.o
