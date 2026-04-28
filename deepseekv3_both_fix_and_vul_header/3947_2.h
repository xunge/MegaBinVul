#include <stdatomic.h>
#include <stdlib.h>

struct device;

struct mctp_dev {
    struct device *dev;
    _Atomic int refs;
    void *addrs;
};

static inline int refcount_dec_and_test(_Atomic int *r) {
    return atomic_fetch_sub(r, 1) == 1;
}

#define kfree free
#define dev_put(dev) (void)0
#define kfree_rcu(ptr, member) free(ptr)