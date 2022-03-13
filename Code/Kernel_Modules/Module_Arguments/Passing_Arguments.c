/***************************************************************************//**
*  \file       Passing_Arguments.c
*
*  \details    Linux Kernel Module which has arguments
*
* *******************************************************************************/
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/moduleparam.h>

/*

Using this module:
Insert using: sudo insmod Passing_Arguments.ko valueETX=14 nameETX="Sample Text" arr_valueETX=100,102,104,106
Remove Using: sudo rmmod Passing_Arguments.ko
Modify variable: sudo sh -c "echo 13 > /sys/module/Passing_Arguments/parameters/cb_valueETX"


Permission Types:
- S_IWUSR: User Write
- S_IRUSR  User Read
- S_IXUSR: User Execute
- S_IRGRP: Group Read
- S_IWGRP: Group Write
- S_IXGRP: Group Execute

Module Parameter macros:

Variables are created in: /sys/module/module_name/parameters/variable
- module_param(name, type, perm): initialize module arguments
- module_param_array(name, type, num, perm):  initialize argument as array
- module_param_cb(name, ops, arg, perm):
*/

int valueETX, arr_valueETX[4];
char *nameETX;
int cb_valueETX = 0;

module_param(valueETX, int, S_IRUSR|S_IWUSR);                      //integer value
module_param(nameETX, charp, S_IRUSR|S_IWUSR);                     //String
module_param_array(arr_valueETX, int, NULL, S_IRUSR|S_IWUSR);      //Array of integers
 
/*----------------------Module_param_cb()--------------------------------*/
int notify_param(const char *val, const struct kernel_param *kp)
{
        int res = param_set_int(val, kp); // Use helper for write variable
        if(res==0) {
                printk(KERN_INFO "Call back function called...\n");
                printk(KERN_INFO "New value of cb_valueETX = %d\n", cb_valueETX);
                return 0;
        }
        return -1;
}
 
const struct kernel_param_ops my_param_ops = 
{
        .set = &notify_param, // Use our setter ...
        .get = &param_get_int, // .. and standard getter
};
 
module_param_cb(cb_valueETX, &my_param_ops, &cb_valueETX, S_IRUGO|S_IWUSR );
/*-------------------------------------------------------------------------*/
/*
** Module init function
*/
static int __init hello_world_init(void)
{
        int i;
        printk(KERN_INFO "ValueETX = %d  \n", valueETX);
        printk(KERN_INFO "cb_valueETX = %d  \n", cb_valueETX);
        printk(KERN_INFO "NameETX = %s \n", nameETX);
        for (i = 0; i < (sizeof arr_valueETX / sizeof (int)); i++) {
                printk(KERN_INFO "Arr_value[%d] = %d\n", i, arr_valueETX[i]);
        }
        printk(KERN_INFO "Kernel Module Inserted Successfully...\n");
    return 0;
}
/*
** Module Exit function
*/
static void __exit hello_world_exit(void)
{
    printk(KERN_INFO "Kernel Module Removed Successfully...\n");
}
 
module_init(hello_world_init);
module_exit(hello_world_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Cesar Rodriguez");
MODULE_DESCRIPTION("Module with input parameters");
MODULE_VERSION("1.0");