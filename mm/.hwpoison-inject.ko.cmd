cmd_mm/hwpoison-inject.ko := ld -r -m elf_x86_64 -T ./scripts/module-common.lds --build-id  -o mm/hwpoison-inject.ko mm/hwpoison-inject.o mm/hwpoison-inject.mod.o
