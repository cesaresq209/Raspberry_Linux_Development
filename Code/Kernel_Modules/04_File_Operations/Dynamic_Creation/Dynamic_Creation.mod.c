#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xcaec5711, "module_layout" },
	{ 0x78770421, "device_destroy" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0xf0462214, "class_destroy" },
	{ 0x5d3eb04, "device_create" },
	{ 0x84e8af7f, "__class_create" },
	{ 0xc5850110, "printk" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "32A41EA4C400FBE1687B827");
