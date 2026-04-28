#include <sys/types.h>
#include <limits.h>
#include <unistd.h>

#define MAX_RW_COUNT (INT_MAX & ~(4096-1))
#define unlikely(x) (x)
#define __user
#define EFAULT 14

struct kiocb;
struct iov_iter;

struct iovec {
    void *iov_base;
    size_t iov_len;
};

static inline int access_ok(int rw, const void *buf, size_t len) {
    return 1;
}

static inline void iov_iter_init(struct iov_iter *iter, int rw, 
                               struct iovec *iov, unsigned long nr_segs,
                               size_t count) {
}