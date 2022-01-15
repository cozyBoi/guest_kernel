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
	{ 0x85847527, __VMLINUX_SYMBOL_STR(shash_ahash_digest) },
	{ 0xcdb7d12, __VMLINUX_SYMBOL_STR(__kernel_fpu_begin) },
	{ 0xb77abc4a, __VMLINUX_SYMBOL_STR(crypto_shash_final) },
	{ 0xb2c3ef50, __VMLINUX_SYMBOL_STR(crypto_ahash_final) },
	{ 0x452de78d, __VMLINUX_SYMBOL_STR(crypto_ahash_digest) },
	{ 0x86fcd87a, __VMLINUX_SYMBOL_STR(cryptd_shash_desc) },
	{ 0xe5e91a82, __VMLINUX_SYMBOL_STR(crypto_register_ahash) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0x647abcf8, __VMLINUX_SYMBOL_STR(crypto_unregister_shash) },
	{ 0x426216a6, __VMLINUX_SYMBOL_STR(crypto_register_shash) },
	{ 0x2ea2c95c, __VMLINUX_SYMBOL_STR(__x86_indirect_thunk_rax) },
	{ 0x69ca3273, __VMLINUX_SYMBOL_STR(crypto_unregister_ahash) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0x1995a724, __VMLINUX_SYMBOL_STR(cryptd_ahash_child) },
	{ 0x5ee2ca83, __VMLINUX_SYMBOL_STR(crypto_ahash_setkey) },
	{ 0xd6377b34, __VMLINUX_SYMBOL_STR(shash_ahash_update) },
	{ 0x73dd54eb, __VMLINUX_SYMBOL_STR(irq_fpu_usable) },
	{ 0xe61d1c71, __VMLINUX_SYMBOL_STR(cryptd_alloc_ahash) },
	{ 0xf50afa94, __VMLINUX_SYMBOL_STR(cryptd_free_ahash) },
	{ 0xbec30d05, __VMLINUX_SYMBOL_STR(x86_match_cpu) },
	{ 0xdd14c2d3, __VMLINUX_SYMBOL_STR(crypto_ahash_type) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=cryptd";

MODULE_ALIAS("x86cpu:vendor:*:family:*:model:*:feature:*0081*");

MODULE_INFO(srcversion, "88E660519867E632EF9C070");
MODULE_INFO(rhelversion, "7.9");
#ifdef RETPOLINE
	MODULE_INFO(retpoline, "Y");
#endif
#ifdef CONFIG_MPROFILE_KERNEL
	MODULE_INFO(mprofile, "Y");
#endif
