#include <stddef.h>

struct task_struct;
struct user_regset;

struct user_desc {
    unsigned int entry_number;
    unsigned int base_addr;
    unsigned int limit;
    unsigned int flags;
};

#define GDT_ENTRY_TLS_ENTRIES 3
#define GDT_ENTRY_TLS_MIN 12
#define EINVAL 22
#define EFAULT 14

#define __user
extern int __copy_from_user(void *to, const void *from, unsigned long n);
extern void set_tls_desc(struct task_struct *target, int idx, const struct user_desc *info, int count);