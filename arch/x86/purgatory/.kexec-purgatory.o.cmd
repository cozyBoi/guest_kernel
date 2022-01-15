cmd_arch/x86/purgatory/kexec-purgatory.o := gcc -Wp,-MD,arch/x86/purgatory/.kexec-purgatory.o.d  -nostdinc -isystem /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include -I./arch/x86/include -Iarch/x86/include/generated  -Iinclude -I./arch/x86/include/uapi -Iarch/x86/include/generated/uapi -I./include/uapi -Iinclude/generated/uapi -include ./include/linux/kconfig.h -D__KERNEL__ -fno-strict-aliasing -Wall -Wstrict-prototypes -fno-zero-initialized-in-bss -fno-builtin -ffreestanding -c -MD -Os -mcmodel=large -m64    -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(kexec_purgatory)"  -D"KBUILD_MODNAME=KBUILD_STR(kexec_purgatory)" -c -o arch/x86/purgatory/.tmp_kexec-purgatory.o arch/x86/purgatory/kexec-purgatory.c

source_arch/x86/purgatory/kexec-purgatory.o := arch/x86/purgatory/kexec-purgatory.c

deps_arch/x86/purgatory/kexec-purgatory.o := \

arch/x86/purgatory/kexec-purgatory.o: $(deps_arch/x86/purgatory/kexec-purgatory.o)

$(deps_arch/x86/purgatory/kexec-purgatory.o):
