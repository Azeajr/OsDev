/*
 * Introduction to Linux Kernel Modules
 */

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/hash.h>
#include <linux/gcd.h>
#include <linux/jiffies.h>
#include <asm/param.h>

int simple_init(void){
    printk(KERN_INFO "Loading Kernel Module\n");
    printk(KERN_INFO "%lu\n", GOLDEN_RATIO_PRIME);
    printk(KERN_INFO "jiffies: %lu\n", jiffies);
    printk(KERN_INFO "HZ: %d\n", HZ);
    return 0;
}

void simpe_exit(void){
    printk(KERN_INFO "Removing Kernel Module\n");
    printk(KERN_INFO "GCD of 3300 and 24 is %lu\n", gcd(3300, 24));
    printk(KERN_INFO "jiffies: %lu\n", jiffies);
}

module_init(simple_init);
module_exit(simpe_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");