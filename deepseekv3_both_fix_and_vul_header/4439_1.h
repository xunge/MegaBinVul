#include <stddef.h>
#include <sys/types.h>

struct iovec {
    void *iov_base;
    size_t iov_len;
};

struct iov_iter {
    const struct iovec *iov;
    size_t iov_offset;
    unsigned long nr_segs;
};

#define likely(x) __builtin_expect(!!(x), 1)
#define min(a, b) ((a) < (b) ? (a) : (b))