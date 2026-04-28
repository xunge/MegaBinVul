#include <stddef.h>
#include <unistd.h>
#include <errno.h>

#define VERIFY_WRITE 1
#define __user

typedef struct ctl_table {
    int dummy;
} ctl_table;

struct file;
typedef long loff_t;

extern int svc_print_xprts(char *buf, size_t size);
extern int access_ok(int type, const void *addr, unsigned long size);
extern int __copy_to_user(void *to, const void *from, unsigned long n);