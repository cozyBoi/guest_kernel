cmd_arch/x86/ia32/audit.o := gcc -Wp,-MD,arch/x86/ia32/.audit.o.d  -nostdinc -isystem /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include -I./arch/x86/include -Iarch/x86/include/generated  -Iinclude -I./arch/x86/include/uapi -Iarch/x86/include/generated/uapi -I./include/uapi -Iinclude/generated/uapi -include ./include/linux/kconfig.h -D__KERNEL__ -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -std=gnu89 -Werror -O2 -m64 -mno-mmx -mno-sse -mpreferred-stack-boundary=3 -mtune=generic -mno-red-zone -mcmodel=kernel -funit-at-a-time -maccumulate-outgoing-args -Wframe-larger-than=2048 -DCONFIG_AS_CFI=1 -DCONFIG_AS_CFI_SIGNAL_FRAME=1 -DCONFIG_AS_CFI_SECTIONS=1 -DCONFIG_AS_FXSAVEQ=1 -DCONFIG_AS_AVX=1 -DCONFIG_AS_AVX2=1 -DCONFIG_AS_AVX512=1 -DCONFIG_AS_SHA1_NI=1 -DCONFIG_AS_SHA256_NI=1 -pipe -Wno-sign-compare -fno-asynchronous-unwind-tables -mno-sse -mno-mmx -mno-sse2 -mno-3dnow -mno-avx -mindirect-branch=thunk-extern -mindirect-branch-register -DRETPOLINE -Wframe-larger-than=2048 -fstack-protector-strong -Wno-unused-but-set-variable -fno-omit-frame-pointer -fno-optimize-sibling-calls -g -pg -mfentry -DCC_USING_FENTRY -fno-inline-functions-called-once -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -DCC_HAVE_ASM_GOTO    -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(audit)"  -D"KBUILD_MODNAME=KBUILD_STR(audit)" -c -o arch/x86/ia32/.tmp_audit.o arch/x86/ia32/audit.c

source_arch/x86/ia32/audit.o := arch/x86/ia32/audit.c

deps_arch/x86/ia32/audit.o := \
  arch/x86/include/generated/uapi/asm/unistd_32.h \
  include/asm-generic/audit_dir_write.h \
  include/asm-generic/audit_change_attr.h \
  include/asm-generic/audit_write.h \
  include/asm-generic/audit_read.h \
  include/asm-generic/audit_signal.h \

arch/x86/ia32/audit.o: $(deps_arch/x86/ia32/audit.o)

$(deps_arch/x86/ia32/audit.o):
