cmd_arch/x86/crypto/sha512-mb/sha512-mb.o := ld -m elf_x86_64   -r -o arch/x86/crypto/sha512-mb/sha512-mb.o arch/x86/crypto/sha512-mb/sha512_mb.o arch/x86/crypto/sha512-mb/sha512_mb_mgr_flush_avx2.o arch/x86/crypto/sha512-mb/sha512_mb_mgr_init_avx2.o arch/x86/crypto/sha512-mb/sha512_mb_mgr_submit_avx2.o arch/x86/crypto/sha512-mb/sha512_x4_avx2.o ; scripts/mod/modpost arch/x86/crypto/sha512-mb/sha512-mb.o