cmd_arch/x86/crypto/serpent-sse2-x86_64.o := ld -m elf_x86_64   -r -o arch/x86/crypto/serpent-sse2-x86_64.o arch/x86/crypto/serpent-sse2-x86_64-asm_64.o arch/x86/crypto/serpent_sse2_glue.o ; scripts/mod/modpost arch/x86/crypto/serpent-sse2-x86_64.o