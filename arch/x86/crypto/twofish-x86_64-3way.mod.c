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
	{ 0xfcfd363f, __VMLINUX_SYMBOL_STR(xts_crypt) },
	{ 0x15692c87, __VMLINUX_SYMBOL_STR(param_ops_int) },
	{ 0x39f27759, __VMLINUX_SYMBOL_STR(crypto_unregister_algs) },
	{ 0x6854463d, __VMLINUX_SYMBOL_STR(lrw_crypt) },
	{ 0x5e752773, __VMLINUX_SYMBOL_STR(twofish_enc_blk) },
	{ 0x45449b56, __VMLINUX_SYMBOL_STR(boot_cpu_data) },
	{ 0x19383bc5, __VMLINUX_SYMBOL_STR(glue_ctr_crypt_128bit) },
	{ 0x92b37a60, __VMLINUX_SYMBOL_STR(crypto_blkcipher_type) },
	{ 0xcd074900, __VMLINUX_SYMBOL_STR(lrw_init_table) },
	{ 0xdc3c41a8, __VMLINUX_SYMBOL_STR(__crypto_memneq) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x1ac7ad48, __VMLINUX_SYMBOL_STR(glue_cbc_decrypt_128bit) },
	{ 0x6c3229bb, __VMLINUX_SYMBOL_STR(__twofish_setkey) },
	{ 0xb0aa812e, __VMLINUX_SYMBOL_STR(fips_enabled) },
	{ 0xf0fdf6cb, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x7f4c870e, __VMLINUX_SYMBOL_STR(twofish_setkey) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0x8db43fe6, __VMLINUX_SYMBOL_STR(glue_ecb_crypt_128bit) },
	{ 0x3864eb66, __VMLINUX_SYMBOL_STR(lrw_free_table) },
	{ 0xec98e95c, __VMLINUX_SYMBOL_STR(crypto_register_algs) },
	{ 0xfd726f0f, __VMLINUX_SYMBOL_STR(glue_cbc_encrypt_128bit) },
	{ 0x19dc7881, __VMLINUX_SYMBOL_STR(twofish_dec_blk) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=xts,lrw,twofish-x86_64,glue_helper,twofish_common";


MODULE_INFO(srcversion, "1646B07E4415128456E56A7");
MODULE_INFO(rhelversion, "7.9");
#ifdef RETPOLINE
	MODULE_INFO(retpoline, "Y");
#endif
#ifdef CONFIG_MPROFILE_KERNEL
	MODULE_INFO(mprofile, "Y");
#endif
