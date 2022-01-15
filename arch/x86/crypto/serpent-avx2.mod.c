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
	{ 0x606a8162, __VMLINUX_SYMBOL_STR(serpent_cbc_dec_8way_avx) },
	{ 0xa84ea33d, __VMLINUX_SYMBOL_STR(serpent_ecb_enc_8way_avx) },
	{ 0x39f27759, __VMLINUX_SYMBOL_STR(crypto_unregister_algs) },
	{ 0x6c0dae5, __VMLINUX_SYMBOL_STR(__kernel_fpu_end) },
	{ 0x488fd678, __VMLINUX_SYMBOL_STR(crypto_ablkcipher_type) },
	{ 0x6854463d, __VMLINUX_SYMBOL_STR(lrw_crypt) },
	{ 0x45449b56, __VMLINUX_SYMBOL_STR(boot_cpu_data) },
	{ 0x61709b02, __VMLINUX_SYMBOL_STR(glue_xts_crypt_128bit) },
	{ 0x5ddb33e9, __VMLINUX_SYMBOL_STR(__serpent_encrypt) },
	{ 0xcd875857, __VMLINUX_SYMBOL_STR(serpent_setkey) },
	{ 0xcdb7d12, __VMLINUX_SYMBOL_STR(__kernel_fpu_begin) },
	{ 0x19383bc5, __VMLINUX_SYMBOL_STR(glue_ctr_crypt_128bit) },
	{ 0x92b37a60, __VMLINUX_SYMBOL_STR(crypto_blkcipher_type) },
	{ 0xc5a8af6, __VMLINUX_SYMBOL_STR(serpent_xts_dec_8way_avx) },
	{ 0xff3c26d, __VMLINUX_SYMBOL_STR(serpent_xts_dec) },
	{ 0x9311e089, __VMLINUX_SYMBOL_STR(__ablk_encrypt) },
	{ 0x3afba169, __VMLINUX_SYMBOL_STR(xts_serpent_setkey) },
	{ 0x8a1a99ad, __VMLINUX_SYMBOL_STR(__serpent_decrypt) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xeb03c833, __VMLINUX_SYMBOL_STR(ablk_exit) },
	{ 0x1ac7ad48, __VMLINUX_SYMBOL_STR(glue_cbc_decrypt_128bit) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0x9ae34b2f, __VMLINUX_SYMBOL_STR(serpent_xts_enc) },
	{ 0x86aaec45, __VMLINUX_SYMBOL_STR(lrw_serpent_exit_tfm) },
	{ 0x9f99663c, __VMLINUX_SYMBOL_STR(serpent_ctr_8way_avx) },
	{ 0x8780a368, __VMLINUX_SYMBOL_STR(ablk_encrypt) },
	{ 0x3f52702d, __VMLINUX_SYMBOL_STR(ablk_init) },
	{ 0xf0fdf6cb, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x79ff0b7a, __VMLINUX_SYMBOL_STR(serpent_ecb_dec_8way_avx) },
	{ 0x2e29fe4, __VMLINUX_SYMBOL_STR(ablk_set_key) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0x8db43fe6, __VMLINUX_SYMBOL_STR(glue_ecb_crypt_128bit) },
	{ 0xec98e95c, __VMLINUX_SYMBOL_STR(crypto_register_algs) },
	{ 0xfd726f0f, __VMLINUX_SYMBOL_STR(glue_cbc_encrypt_128bit) },
	{ 0x539cefed, __VMLINUX_SYMBOL_STR(lrw_serpent_setkey) },
	{ 0x73dd54eb, __VMLINUX_SYMBOL_STR(irq_fpu_usable) },
	{ 0x16a957f, __VMLINUX_SYMBOL_STR(serpent_xts_enc_8way_avx) },
	{ 0x9e018632, __VMLINUX_SYMBOL_STR(__serpent_crypt_ctr) },
	{ 0xca9f0fe5, __VMLINUX_SYMBOL_STR(ablk_decrypt) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=serpent-avx-x86_64,lrw,glue_helper,serpent_generic,ablk_helper";


MODULE_INFO(srcversion, "D1AB330AC2296C5E860138A");
MODULE_INFO(rhelversion, "7.9");
#ifdef RETPOLINE
	MODULE_INFO(retpoline, "Y");
#endif
#ifdef CONFIG_MPROFILE_KERNEL
	MODULE_INFO(mprofile, "Y");
#endif
