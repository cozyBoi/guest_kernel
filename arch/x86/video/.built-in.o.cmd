cmd_arch/x86/video/built-in.o :=  ld -m elf_x86_64   -r -o arch/x86/video/built-in.o arch/x86/video/fbdev.o ; scripts/mod/modpost arch/x86/video/built-in.o
