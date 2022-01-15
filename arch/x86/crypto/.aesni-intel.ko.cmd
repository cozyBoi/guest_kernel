cmd_arch/x86/crypto/aesni-intel.ko := ld -r -m elf_x86_64 -T ./scripts/module-common.lds --build-id  -o arch/x86/crypto/aesni-intel.ko arch/x86/crypto/aesni-intel.o arch/x86/crypto/aesni-intel.mod.o
