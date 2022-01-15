cmd_arch/x86/purgatory/entry64.o := gcc -Wp,-MD,arch/x86/purgatory/.entry64.o.d  -nostdinc -isystem /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include -I./arch/x86/include -Iarch/x86/include/generated  -Iinclude -I./arch/x86/include/uapi -Iarch/x86/include/generated/uapi -I./include/uapi -Iinclude/generated/uapi -include ./include/linux/kconfig.h -D__KERNEL__  -D__ASSEMBLY__ -m64 -DCONFIG_AS_CFI=1 -DCONFIG_AS_CFI_SIGNAL_FRAME=1 -DCONFIG_AS_CFI_SECTIONS=1 -DCONFIG_AS_FXSAVEQ=1 -DCONFIG_AS_AVX=1 -DCONFIG_AS_AVX2=1 -DCONFIG_AS_AVX512=1 -DCONFIG_AS_SHA1_NI=1 -DCONFIG_AS_SHA256_NI=1  -gdwarf-2  -mfentry -DCC_USING_FENTRY         -c -o arch/x86/purgatory/entry64.o arch/x86/purgatory/entry64.S

source_arch/x86/purgatory/entry64.o := arch/x86/purgatory/entry64.S

deps_arch/x86/purgatory/entry64.o := \

arch/x86/purgatory/entry64.o: $(deps_arch/x86/purgatory/entry64.o)

$(deps_arch/x86/purgatory/entry64.o):
