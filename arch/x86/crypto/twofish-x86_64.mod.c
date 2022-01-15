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
	{ 0x7f4c870e, __VMLINUX_SYMBOL_STR(twofish_setkey) },
	{ 0x704808de, __VMLINUX_SYMBOL_STR(crypto_register_alg) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0x79084066, __VMLINUX_SYMBOL_STR(crypto_unregister_alg) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=twofish_common";


MODULE_INFO(srcversion, "597EF15F97C2754BEDBC89B");
MODULE_INFO(rhelversion, "7.9");
#ifdef RETPOLINE
	MODULE_INFO(retpoline, "Y");
#endif
#ifdef CONFIG_MPROFILE_KERNEL
	MODULE_INFO(mprofile, "Y");
#endif
