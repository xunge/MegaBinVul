#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <pthread.h>

struct kiocb {
    struct file *ki_filp;
};

struct file {
    void *private_data;
    int f_flags;
};

struct iov_iter;

struct rpmsg_eptdev {
    pthread_mutex_t ept_lock;
    void *ept;
};

struct rpmsg_endpoint;

#define GFP_KERNEL 0
#define ENOMEM 12
#define EFAULT 14
#define ERESTARTSYS 512
#define EPIPE 32

static inline void *kzalloc(size_t size, int flags) {
    return calloc(1, size);
}

static inline void kfree(void *ptr) {
    free(ptr);
}

static inline int mutex_lock_interruptible(pthread_mutex_t *lock) {
    return pthread_mutex_lock(lock);
}

static inline void mutex_unlock(pthread_mutex_t *lock) {
    pthread_mutex_unlock(lock);
}

static inline size_t iov_iter_count(struct iov_iter *i) {
    return 0;
}

static inline int copy_from_iter_full(void *to, size_t len, struct iov_iter *from) {
    return 1;
}

static inline int rpmsg_trysend(void *ept, void *data, size_t len) {
    return 0;
}

static inline int rpmsg_send(void *ept, void *data, size_t len) {
    return 0;
}