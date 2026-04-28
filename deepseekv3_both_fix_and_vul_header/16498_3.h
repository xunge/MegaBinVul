#include <stdbool.h>
#include <stdatomic.h>
#include <stdlib.h>
#include <pthread.h>

#define NBD_RT_BOUND 0
#define GFP_KERNEL 0
#define ENOMEM (-1)
#define EBUSY (-2)

struct nbd_device {
    struct nbd_config *config;
    void *task_setup;
    struct {
        void *queue;
    } *disk;
};

struct nbd_config {
    struct nbd_sock **socks;
    int num_connections;
    atomic_int live_connections;
    unsigned long runtime_flags;
};

struct nbd_sock {
    int fallback_index;
    bool dead;
    pthread_mutex_t tx_lock;
    struct socket *sock;
    void *pending;
    int sent;
    int cookie;
};

struct socket {
    int dummy;
};

static inline void mutex_init(pthread_mutex_t *mutex) {
    pthread_mutex_init(mutex, NULL);
}

static inline void atomic_inc(atomic_int *v) {
    (*v)++;
}

extern void *current;
extern struct socket *nbd_get_socket(struct nbd_device *nbd, unsigned long arg, int *err);
extern void blk_mq_freeze_queue(void *queue);
extern void blk_mq_unfreeze_queue(void *queue);
extern void sockfd_put(struct socket *sock);
extern void *kzalloc(size_t size, int flags);
extern void *krealloc(void *ptr, size_t size, int flags);
extern void kfree(void *ptr);
extern void dev_err(void *dev, const char *fmt, ...);
extern void *disk_to_dev(void *disk);
extern int test_bit(int nr, const volatile unsigned long *addr);