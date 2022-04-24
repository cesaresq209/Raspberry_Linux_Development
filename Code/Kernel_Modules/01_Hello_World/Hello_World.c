/***************************************************************************//**
*  \file       Hello_World.c
*
*  \details    Simple hello world driver
*
* *******************************************************************************/
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
 
/*
** Module Init function
*/
static int __init hello_world_init(void)
{
    printk(KERN_INFO "Hello World!\n");
    return 0;
}
/*
** Module Exit function
*/
static void __exit hello_world_exit(void)
{
    printk(KERN_INFO "Hello World Kernel Module Removed Successfully...\n");
    return;
}
 
module_init(hello_world_init);
module_exit(hello_world_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Cesar Rodriguez");
MODULE_DESCRIPTION("A simple hello world driver");
MODULE_VERSION("2:1.0");