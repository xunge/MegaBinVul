#include <stddef.h>

#define __user

struct task_struct;
struct user_desc {
    int entry_number;
    unsigned int base_addr;
    unsigned int limit;
    unsigned int seg_32bit:1;
    unsigned int contents:2;
    unsigned int read_exec_only:1;
    unsigned int limit_in_pages:1;
    unsigned int seg_not_present:1;
    unsigned int useable:1;
};

#define GDT_ENTRY_TLS_MIN 12
#define GDT_ENTRY_TLS_MAX 14

#define EFAULT 14
#define EINVAL 22

extern int get_free_idx(void);
extern void set_tls_desc(struct task_struct *p, int idx, struct user_desc *info, int can_allocate);
extern int copy_from_user(void *to, const void *from, size_t n);
extern int put_user(int val, int *addr);