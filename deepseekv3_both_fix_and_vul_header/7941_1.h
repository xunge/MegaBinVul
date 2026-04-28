#include <stddef.h>
#include <stdint.h>

#define __user
#define VERIFY_WRITE 1
#define EFAULT 14
#define E2BIG 7

struct sched_attr {
    unsigned int size;
};

static inline int access_ok(int type, const void *addr, unsigned long size) {
    return 1;
}

static inline int copy_to_user(void *to, const void *from, unsigned long n) {
    return 0;
}