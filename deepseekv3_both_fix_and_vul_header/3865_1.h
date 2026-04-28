#include <stddef.h>
#include <stdio.h>
#include <ctype.h>

struct ctl_table;
typedef long loff_t;
typedef unsigned long size_t;
#define __user
#define EFAULT (-1)

extern long cmm_timeout_pages;
extern long cmm_timeout_seconds;
extern void cmm_skip_blanks(char *str, char **end);
extern unsigned long simple_strtoul(const char *cp, char **endp, unsigned int base);
extern void cmm_set_timeout(long nr, long seconds);
extern int copy_from_user(void *to, const void __user *from, unsigned long n);
extern int copy_to_user(void __user *to, const void *from, unsigned long n);