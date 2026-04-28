#include <stdbool.h>
#include <limits.h>
#include <stdio.h>

#define AIO_BATCH_HASH_SIZE 16
#define EINVAL 22
#define EFAULT 14

typedef unsigned long aio_context_t;

struct kioctx {
    // dummy structure definition
    int dummy;
};

struct iocb {
    // dummy structure definition
    long aio_data;
    int aio_key;
};

struct hlist_head {
    void *first;
};

static inline struct kioctx* lookup_ioctx(aio_context_t ctx_id) {
    return NULL;
}

static inline int io_submit_one(struct kioctx *ctx, struct iocb *user_iocb,
                               struct iocb *tmp, struct hlist_head *batch_hash,
                               bool compat) {
    return 0;
}

static inline void aio_batch_free(struct hlist_head *hash) {}
static inline void put_ioctx(struct kioctx *ctx) {}

#define unlikely(x) (x)
#define VERIFY_READ 0
#define __user
#define pr_debug printf

static inline int access_ok(int type, const void *addr, unsigned long size) {
    return 1;
}

static inline int __get_user(void *val, const void *addr) {
    return 0;
}

static inline int copy_from_user(void *to, const void *from, unsigned long n) {
    return 0;
}