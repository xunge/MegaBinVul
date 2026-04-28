#include <linux/types.h>
#include <linux/string.h>
#include <linux/kernel.h>
#include <linux/fs.h>

typedef unsigned long long ext3_fsblk_t;

#define KERN_ERR        3
#define ext3_msg(sb, level, fmt, ...) printk(fmt, ##__VA_ARGS__)

unsigned long simple_strtoul(const char *cp, char **endp, unsigned int base);