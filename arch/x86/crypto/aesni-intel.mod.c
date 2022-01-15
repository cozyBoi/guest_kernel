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
	{ 0xf39cbc24, __VMLINUX_SYMBOL_STR(crypto_attr_alg2) },
	{ 0x98ab5c8d, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0x8f02ac4d, __VMLINUX_SYMBOL_STR(glue_xts_crypt_128bit_one) },
	{ 0xe409b491, __VMLINUX_SYMBOL_STR(crypto_aes_decrypt_x86) },
	{ 0x7060bf0a, __VMLINUX_SYMBOL_STR(crypto_aes_encrypt_x86) },
	{ 0xd16712f3, __VMLINUX_SYMBOL_STR(crypto_check_attr_type) },
	{ 0x39f27759, __VMLINUX_SYMBOL_STR(crypto_unregister_algs) },
	{ 0x6c0dae5, __VMLINUX_SYMBOL_STR(__kernel_fpu_end) },
	{ 0x53c307c0, __VMLINUX_SYMBOL_STR(crypto_mod_put) },
	{ 0x488fd678, __VMLINUX_SYMBOL_STR(crypto_ablkcipher_type) },
	{ 0x6854463d, __VMLINUX_SYMBOL_STR(lrw_crypt) },
	{ 0xc500faef, __VMLINUX_SYMBOL_STR(blkcipher_walk_virt_block) },
	{ 0x45449b56, __VMLINUX_SYMBOL_STR(boot_cpu_data) },
	{ 0x61709b02, __VMLINUX_SYMBOL_STR(glue_xts_crypt_128bit) },
	{ 0x80fcbf7, __VMLINUX_SYMBOL_STR(crypto_unregister_template) },
	{ 0x7bf5692, __VMLINUX_SYMBOL_STR(cryptd_free_aead) },
	{ 0xcdb7d12, __VMLINUX_SYMBOL_STR(__kernel_fpu_begin) },
	{ 0x92b37a60, __VMLINUX_SYMBOL_STR(crypto_blkcipher_type) },
	{ 0xe8f49384, __VMLINUX_SYMBOL_STR(crypto_spawn_tfm) },
	{ 0xcd074900, __VMLINUX_SYMBOL_STR(lrw_init_table) },
	{ 0xd65a0e5c, __VMLINUX_SYMBOL_STR(crypto_aead_type) },
	{ 0xb903674c, __VMLINUX_SYMBOL_STR(scatterwalk_map_and_copy) },
	{ 0xdc3c41a8, __VMLINUX_SYMBOL_STR(__crypto_memneq) },
	{ 0x8810ad5e, __VMLINUX_SYMBOL_STR(crypto_xor) },
	{ 0xf432dd3d, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0x24aac4d9, __VMLINUX_SYMBOL_STR(crypto_aes_expand_key) },
	{ 0x8a2fea2a, __VMLINUX_SYMBOL_STR(crypto_alloc_ablkcipher) },
	{ 0xb8c7ff88, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x449ad0a7, __VMLINUX_SYMBOL_STR(memcmp) },
	{ 0x7e79a70c, __VMLINUX_SYMBOL_STR(crypto_register_template) },
	{ 0x15ddbdc, __VMLINUX_SYMBOL_STR(wait_for_completion_interruptible) },
	{ 0xeb03c833, __VMLINUX_SYMBOL_STR(ablk_exit) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0x8745af0c, __VMLINUX_SYMBOL_STR(crypto_drop_spawn) },
	{ 0x8edde706, __VMLINUX_SYMBOL_STR(retp_enabled_key) },
	{ 0x2f630f42, __VMLINUX_SYMBOL_STR(crypto_nivaead_type) },
	{ 0x2cddbb, __VMLINUX_SYMBOL_STR(ablk_init_common) },
	{ 0xb0aa812e, __VMLINUX_SYMBOL_STR(fips_enabled) },
	{ 0x8780a368, __VMLINUX_SYMBOL_STR(ablk_encrypt) },
	{ 0x3f52702d, __VMLINUX_SYMBOL_STR(ablk_init) },
	{ 0xf0fdf6cb, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x9d5e8c88, __VMLINUX_SYMBOL_STR(crypto_alloc_instance) },
	{ 0x2ea2c95c, __VMLINUX_SYMBOL_STR(__x86_indirect_thunk_rax) },
	{ 0xbfdcb43a, __VMLINUX_SYMBOL_STR(__x86_indirect_thunk_r11) },
	{ 0x8f944a92, __VMLINUX_SYMBOL_STR(crypto_destroy_tfm) },
	{ 0x2e29fe4, __VMLINUX_SYMBOL_STR(ablk_set_key) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0x41ec4c1a, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x3864eb66, __VMLINUX_SYMBOL_STR(lrw_free_table) },
	{ 0xb6244511, __VMLINUX_SYMBOL_STR(sg_init_one) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xec98e95c, __VMLINUX_SYMBOL_STR(crypto_register_algs) },
	{ 0x69acdf38, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x56886b19, __VMLINUX_SYMBOL_STR(scatterwalk_map) },
	{ 0x7a4497db, __VMLINUX_SYMBOL_STR(kzfree) },
	{ 0x2449abdb, __VMLINUX_SYMBOL_STR(blkcipher_walk_virt) },
	{ 0x424acc6d, __VMLINUX_SYMBOL_STR(scatterwalk_done) },
	{ 0x73dd54eb, __VMLINUX_SYMBOL_STR(irq_fpu_usable) },
	{ 0x46da197b, __VMLINUX_SYMBOL_STR(cryptd_aead_child) },
	{ 0x4b06d2e7, __VMLINUX_SYMBOL_STR(complete) },
	{ 0x7f31ba23, __VMLINUX_SYMBOL_STR(blkcipher_walk_done) },
	{ 0x45bf1ff3, __VMLINUX_SYMBOL_STR(crypto_inc) },
	{ 0xc8f658e9, __VMLINUX_SYMBOL_STR(cryptd_alloc_aead) },
	{ 0xca9f0fe5, __VMLINUX_SYMBOL_STR(ablk_decrypt) },
	{ 0xbec30d05, __VMLINUX_SYMBOL_STR(x86_match_cpu) },
	{ 0xfa1f4662, __VMLINUX_SYMBOL_STR(scatterwalk_start) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=glue_helper,lrw,cryptd,ablk_helper";

MODULE_ALIAS("x86cpu:vendor:*:family:*:model:*:feature:*0099*");

MODULE_INFO(srcversion, "900FF67222BA5BB76F24AED");
MODULE_INFO(rhelversion, "7.9");
#ifdef RETPOLINE
	MODULE_INFO(retpoline, "Y");
#endif
#ifdef CONFIG_MPROFILE_KERNEL
	MODULE_INFO(mprofile, "Y");
#endif
