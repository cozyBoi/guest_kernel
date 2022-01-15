cmd_arch/x86/boot/compressed/mem_encrypt.o := gcc -Wp,-MD,arch/x86/boot/compressed/.mem_encrypt.o.d  -nostdinc -isystem /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include -I./arch/x86/include -Iarch/x86/include/generated  -Iinclude -I./arch/x86/include/uapi -Iarch/x86/include/generated/uapi -I./include/uapi -Iinclude/generated/uapi -include ./include/linux/kconfig.h -D__KERNEL__  -m64 -D__KERNEL__  -O2 -fno-strict-aliasing  -fPIE -DDISABLE_BRANCH_PROFILING -mcmodel=small -mno-mmx -mno-sse -ffreestanding -fno-stack-protector -D__ASSEMBLY__         -c -o arch/x86/boot/compressed/mem_encrypt.o arch/x86/boot/compressed/mem_encrypt.S

source_arch/x86/boot/compressed/mem_encrypt.o := arch/x86/boot/compressed/mem_encrypt.S

deps_arch/x86/boot/compressed/mem_encrypt.o := \
    $(wildcard include/config/amd/mem/encrypt.h) \
  include/linux/linkage.h \
  include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/kasan.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
    $(wildcard include/config/kprobes.h) \
  include/linux/stringify.h \
  include/linux/export.h \
    $(wildcard include/config/have/underscore/symbol/prefix.h) \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/modversions.h) \
    $(wildcard include/config/unused/symbols.h) \
  arch/x86/include/asm/linkage.h \
    $(wildcard include/config/x86/32.h) \
    $(wildcard include/config/x86/64.h) \
    $(wildcard include/config/x86/alignment/16.h) \
  arch/x86/include/asm/processor-flags.h \
    $(wildcard include/config/vm86.h) \
  arch/x86/include/uapi/asm/processor-flags.h \
  include/uapi/linux/const.h \
  include/linux/mem_encrypt.h \
    $(wildcard include/config/arch/has/mem/encrypt.h) \
  arch/x86/include/asm/msr.h \
    $(wildcard include/config/paravirt.h) \
    $(wildcard include/config/smp.h) \
  arch/x86/include/asm/msr-index.h \
    $(wildcard include/config/control.h) \
    $(wildcard include/config/tdp/nominal.h) \
    $(wildcard include/config/tdp/level/1.h) \
    $(wildcard include/config/tdp/level/2.h) \
    $(wildcard include/config/tdp/control.h) \
    $(wildcard include/config/tdp/level1.h) \
    $(wildcard include/config/tdp/level2.h) \
  arch/x86/include/asm/asm-offsets.h \
  include/generated/asm-offsets.h \

arch/x86/boot/compressed/mem_encrypt.o: $(deps_arch/x86/boot/compressed/mem_encrypt.o)

$(deps_arch/x86/boot/compressed/mem_encrypt.o):
