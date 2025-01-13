#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include "hello1.h"

MODULE_AUTHOR("Ostrykov Bogdan");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

static uint n = 1;
module_param(n, uint, 0444);
MODULE_PARM_DESC(n, "Number of times to print the message");

static int __init hello2_init(void)
{
	uint i;
	
	if (n == 0 || (n >= 5 && n <= 10)) {
		pr_warn("Warning! N is 0 or in range 5-10.\n");
	} else if (n > 10) {
		pr_err("Error: N is larger than 10.\n");
		return -EINVAL;
	}

	for (i = 0; i < n; i++) {
		print_hello();
	}

	return 0;
}

static void __exit hello2_exit(void)
{
	pr_info("Unloading hello2 module.\n");
}

module_init(hello2_init);
module_exit(hello2_exit);

