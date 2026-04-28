#include <unistd.h>
#include <sys/uio.h>
#include <limits.h>
#include <sys/types.h>

#define MAX_RW_COUNT (INT_MAX & ~(4096-1))
#define EFAULT 14
#define unlikely(x) (x)
#define __user

struct kiocb {
    size_t ki_nbytes;
};

static inline int access_ok(int rw, const void *ptr, unsigned long size) {
    return 1;
}