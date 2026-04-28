#include <stddef.h>
#include <stdlib.h>

struct inode;
struct file {
    void *private_data;
};

struct snd_timer_read {
    int dummy;
};

struct snd_timer_user {
    void *qlock;
    void *qchange_sleep;
    void *ioctl_lock;
    void *tread_sem;
    unsigned int ticks;
    unsigned int queue_size;
    struct snd_timer_read *queue;
};

#define GFP_KERNEL 0
#define ENOMEM (-1)

static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline void spin_lock_init(void *lock) {}
static inline void init_waitqueue_head(void *wq) {}
static inline void mutex_init(void *mutex) {}
static inline int nonseekable_open(struct inode *inode, struct file *file) { return 0; }