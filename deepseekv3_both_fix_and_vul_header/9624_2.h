#include <stddef.h>

#define PG_BUSY 0
#define TASK_UNINTERRUPTIBLE 2
#define TASK_KILLABLE 1024

struct nfs_page {
    unsigned long wb_flags;
};

extern int nfs_wait_bit_uninterruptible(void *);
extern int nfs_wait_bit_killable(void *);
extern int out_of_line_wait_on_bit(unsigned long *, int, int (*)(void *), unsigned);
extern int test_bit(int nr, const volatile unsigned long *addr);
extern int wait_on_bit(unsigned long *, int, int (*)(void *), unsigned);