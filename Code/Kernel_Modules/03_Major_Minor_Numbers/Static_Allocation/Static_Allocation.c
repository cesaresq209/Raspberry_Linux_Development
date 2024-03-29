/***************************************************************************//**
*  \file       driver.c
*
*  \details    Simple linux driver (Statically allocating the Major and Minor number)
*
* *******************************************************************************/
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include <linux/fs.h>

/*
Using this module:
Insert using: sudo insmod Static_Allocation.ko
Remove Using: sudo rmmod Static_Allocation.ko
*/
//creating the dev with our custom major and minor number
dev_t dev = MKDEV(25, 0);

/*
** Module Init function
*/
static int __init hello_world_init(void)
{
    register_chrdev_region(dev, 1, "Cesar Static Major_Minor Driver");
    printk(KERN_INFO "Major = %d Minor = %d \n",MAJOR(dev), MINOR(dev));
    printk(KERN_INFO "Kernel Module Inserted Successfully...\n");
    return 0;
}

/*
** Module exit function
*/
static void __exit hello_world_exit(void)
{
    unregister_chrdev_region(dev, 1);
    printk(KERN_INFO "Kernel Module Removed Successfully...\n");
}
 
module_init(hello_world_init);
module_exit(hello_world_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Cesar Rodriguez");
MODULE_DESCRIPTION("Simple linux driver (Statically allocating the Major and Minor number)");
MODULE_VERSION("1.0");