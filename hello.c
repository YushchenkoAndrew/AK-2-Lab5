#include <linux/init.h>
#include <linux/types.h>
#include <linux/module.h>
#include <linux/printk.h>

MODULE_AUTHOR("Andrew Yushchenko");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

static uint lines = 1;
module_param(lines, uint, S_IRUGO);
MODULE_PARM_DESC(lines, "Number of printed 'Hello world' lines");

static int __init hello_init(void)
{
	uint i = 0;

	if (!lines || (lines >= 5 && lines <= 10))
		printk(KERN_WARNING "%s", !lines ? "Lines equal to 0" : "Lines between 5 and 10");
	else
		if (lines > 10) {
			printk(KERN_ERR "ERROR: Lines value is too high");
			return -EINVAL;
		}

	for (i = 0; i < lines; i++)
		printk(KERN_INFO "Hello world\n");

	return 0;
}

static void __exit hello_exit(void)
{
	printk(KERN_ALERT "Remove module\n");
}

module_init(hello_init);
module_exit(hello_exit);
