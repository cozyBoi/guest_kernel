#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x28950ef1, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x6c0dae5, __VMLINUX_SYMBOL_STR(__kernel_fpu_end) },
	{ 0xcdb7d12, __VMLINUX_SYMBOL_STR(__kernel_fpu_begin) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0x647abcf8, __VMLINUX_SYMBOL_STR(crypto_unregister_shash) },
	{ 0x426216a6, __VMLINUX_SYMBOL_STR(crypto_register_shash) },
	{ 0x765ff474, __VMLINUX_SYMBOL_STR(crc_t10dif_generic) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0x73dd54eb, __VMLINUX_SYMBOL_STR(irq_fpu_usable) },
	{ 0xbec30d05, __VMLINUX_SYMBOL_STR(x86_match_cpu) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=crct10dif_common";

MODULE_ALIAS("x86cpu:vendor:*:family:*:model:*:feature:*0081*");

MODULE_INFO(srcversion, "CAE2C070200828C8D81C280");
MODULE_INFO(rhelversion, "7.9");
#ifdef RETPOLINE
	MODULE_INFO(retpoline, "Y");
#endif
#ifdef CONFIG_MPROFILE_KERNEL
	MODULE_INFO(mprofile, "Y");
#endif
