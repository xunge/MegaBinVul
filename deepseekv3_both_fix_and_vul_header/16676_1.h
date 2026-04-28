#include <stdatomic.h>

struct completion {
    _Atomic int done;
};

struct io_ring_ctx {
    struct io_sq_data *sq_data;
    unsigned int flags;
};

struct io_sq_data {
    struct completion startup;
};

#define IORING_SETUP_R_DISABLED 0x1
#define IORING_SETUP_SQPOLL 0x2

static inline void complete(struct completion *x)
{
    atomic_store(&x->done, 1);
}