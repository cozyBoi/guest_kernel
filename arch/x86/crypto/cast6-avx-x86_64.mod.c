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
	{ 0x8f02ac4d, __VMLINUX_SYMBOL_STR(glue_xts_crypt_128bit_one) },
	{ 0x39f27759, __VMLINUX_SYMBOL_STR(crypto_unregister_algs) },
	{ 0x6c0dae5, __VMLINUX_SYMBOL_STR(__kernel_fpu_end) },
	{ 0x488fd678, __VMLINUX_SYMBOL_STR(crypto_ablkcipher_type) },
	{ 0x6854463d, __VMLINUX_SYMBOL_STR(lrw_crypt) },
	{ 0x45449b56, __VMLINUX_SYMBOL_STR(boot_cpu_data) },
	{ 0x61709b02, __VMLINUX_SYMBOL_STR(glue_xts_crypt_128bit) },
	{ 0xee83a4f3, __VMLINUX_SYMBOL_STR(cast_s4) },
	{ 0x8aa6fb7, __VMLINUX_SYMBOL_STR(cast_s1) },
	{ 0xcdb7d12, __VMLINUX_SYMBOL_STR(__kernel_fpu_begin) },
	{ 0x19383bc5, __VMLINUX_SYMBOL_STR(glue_ctr_crypt_128bit) },
	{ 0x92b37a60, __VMLINUX_SYMBOL_STR(crypto_blkcipher_type) },
	{ 0xcd074900, __VMLINUX_SYMBOL_STR(lrw_init_table) },
	{ 0xe39dd4b4, __VMLINUX_SYMBOL_STR(cast_s2) },
	{ 0x1291971c, __VMLINUX_SYMBOL_STR(__cast6_setkey) },
	{ 0xdc3c41a8, __VMLINUX_SYMBOL_STR(__crypto_memneq) },
	{ 0x9311e089, __VMLINUX_SYMBOL_STR(__ablk_encrypt) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x8f04034a, __VMLINUX_SYMBOL_STR(__cast6_encrypt) },
	{ 0xeb03c833, __VMLINUX_SYMBOL_STR(ablk_exit) },
	{ 0x1ac7ad48, __VMLINUX_SYMBOL_STR(glue_cbc_decrypt_128bit) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0xb0aa812e, __VMLINUX_SYMBOL_STR(fips_enabled) },
	{ 0x8780a368, __VMLINUX_SYMBOL_STR(ablk_encrypt) },
	{ 0x3f52702d, __VMLINUX_SYMBOL_STR(ablk_init) },
	{ 0xf0fdf6cb, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x2e29fe4, __VMLINUX_SYMBOL_STR(ablk_set_key) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0x8db43fe6, __VMLINUX_SYMBOL_STR(glue_ecb_crypt_128bit) },
	{ 0x3864eb66, __VMLINUX_SYMBOL_STR(lrw_free_table) },
	{ 0xec98e95c, __VMLINUX_SYMBOL_STR(crypto_register_algs) },
	{ 0xfd726f0f, __VMLINUX_SYMBOL_STR(glue_cbc_encrypt_128bit) },
	{ 0x73dd54eb, __VMLINUX_SYMBOL_STR(irq_fpu_usable) },
	{ 0x302dbe56, __VMLINUX_SYMBOL_STR(cast6_setkey) },
	{ 0xc5fbf8a, __VMLINUX_SYMBOL_STR(cast_s3) },
	{ 0xca9f0fe5, __VMLINUX_SYMBOL_STR(ablk_decrypt) },
	{ 0x1e2c961f, __VMLINUX_SYMBOL_STR(__cast6_decrypt) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=glue_helper,lrw,cast_common,cast6_generic,ablk_helper";


MODULE_INFO(srcversion, "1FEBC1C98C50293544F574F");
MODULE_INFO(rhelversion, "7.9");
#ifdef RETPOLINE
	MODULE_INFO(retpoline, "Y");
#endif
#ifdef CONFIG_MPROFILE_KERNEL
	MODULE_INFO(mprofile, "Y");
#endif
