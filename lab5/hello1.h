#ifndef HELLO1_H
#define HELLO1_H

#include <linux/ktime.h>
#include <linux/list.h>

struct hello_entry {
	struct list_head list;
	ktime_t time1;
	ktime_t time2;
};

void print_hello(void);

#endif

