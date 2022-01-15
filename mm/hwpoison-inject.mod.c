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
	{ 0x3cd32b71, __VMLINUX_SYMBOL_STR(simple_attr_release) },
	{ 0x57805a8e, __VMLINUX_SYMBOL_STR(simple_attr_write) },
	{  0x3d853, __VMLINUX_SYMBOL_STR(simple_attr_read) },
	{ 0xc821665c, __VMLINUX_SYMBOL_STR(generic_file_llseek) },
	{ 0x1829b9ed, __VMLINUX_SYMBOL_STR(hwpoison_filter_memcg) },
	{ 0x1f1988f7, __VMLINUX_SYMBOL_STR(hwpoison_filter_flags_value) },
	{ 0x227d6a64, __VMLINUX_SYMBOL_STR(debugfs_create_u64) },
	{ 0x1edc21cb, __VMLINUX_SYMBOL_STR(hwpoison_filter_flags_mask) },
	{ 0xae6eaf93, __VMLINUX_SYMBOL_STR(hwpoison_filter_dev_minor) },
	{ 0x117c7305, __VMLINUX_SYMBOL_STR(hwpoison_filter_dev_major) },
	{ 0x1d45035, __VMLINUX_SYMBOL_STR(debugfs_create_u32) },
	{ 0xae9bb4d4, __VMLINUX_SYMBOL_STR(debugfs_create_file) },
	{ 0x9f13414d, __VMLINUX_SYMBOL_STR(debugfs_create_dir) },
	{ 0x636c619f, __VMLINUX_SYMBOL_STR(debugfs_remove_recursive) },
	{ 0xd488791e, __VMLINUX_SYMBOL_STR(__lock_page) },
	{ 0x3a38dc65, __VMLINUX_SYMBOL_STR(memory_failure) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x334c1f75, __VMLINUX_SYMBOL_STR(put_page) },
	{ 0x5de75127, __VMLINUX_SYMBOL_STR(unlock_page) },
	{ 0xc1465552, __VMLINUX_SYMBOL_STR(hwpoison_filter) },
	{ 0xa1c76e0a, __VMLINUX_SYMBOL_STR(_cond_resched) },
	{ 0xcd8fc2d2, __VMLINUX_SYMBOL_STR(PageHuge) },
	{ 0xb1af6e85, __VMLINUX_SYMBOL_STR(shake_page) },
	{ 0x1e000879, __VMLINUX_SYMBOL_STR(hwpoison_filter_enable) },
	{ 0xdb0739f3, __VMLINUX_SYMBOL_STR(get_hwpoison_page) },
	{ 0x97651e6c, __VMLINUX_SYMBOL_STR(vmemmap_base) },
	{ 0x9f6e19ab, __VMLINUX_SYMBOL_STR(mem_section) },
	{ 0xb907513f, __VMLINUX_SYMBOL_STR(unpoison_memory) },
	{ 0xc6cbbc89, __VMLINUX_SYMBOL_STR(capable) },
	{ 0x8f763434, __VMLINUX_SYMBOL_STR(simple_attr_open) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "E6A4C038AFE0229AB26F2A8");
MODULE_INFO(rhelversion, "7.9");
#ifdef RETPOLINE
	MODULE_INFO(retpoline, "Y");
#endif
#ifdef CONFIG_MPROFILE_KERNEL
	MODULE_INFO(mprofile, "Y");
#endif
