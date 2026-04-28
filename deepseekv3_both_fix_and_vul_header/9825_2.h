#include <stddef.h>
#include <stdint.h>
#include <limits.h>

struct iovec {
    void *iov_base;
    size_t iov_len;
};

struct compat_iovec {
    uintptr_t iov_base;
    size_t iov_len;
};

typedef uintptr_t compat_uptr_t;
typedef size_t compat_size_t;
typedef size_t __kernel_size_t;

#define __user
#define EFAULT 14

static inline int get_user(size_t *val, const size_t *addr) {
    *val = *addr;
    return 0;
}

static inline void *compat_ptr(compat_uptr_t uptr) {
    return (void *)(uintptr_t)uptr;
}