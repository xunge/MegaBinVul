#include <stdlib.h>
#include <string.h>

struct pipe_buffer {
    void *data;
    unsigned int len;
    unsigned int offset;
};

struct pipe_inode_info {
    struct pipe_buffer *bufs;
    unsigned int ring_size;
    unsigned int max_usage;
    unsigned int head;
    unsigned int tail;
    struct {
        int lock;
    } rd_wait;
    struct {
        int dummy;
    } wr_wait;
};

#define GFP_KERNEL_ACCOUNT 0
#define __GFP_NOWARN 0
#define unlikely(x) (x)
#define ENOMEM 1
#define EBUSY 2

static inline unsigned int pipe_occupancy(unsigned int head, unsigned int tail)
{
    return head - tail;
}

static inline void *kcalloc(size_t n, size_t size, int flags)
{
    return calloc(n, size);
}

static inline void kfree(void *ptr)
{
    free(ptr);
}

static inline void spin_lock_irq(int *lock) { (void)lock; }
static inline void spin_unlock_irq(int *lock) { (void)lock; }
static inline void wake_up_interruptible(void *q) { (void)q; }