#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct wait_queue_head {
    int dummy;
};

struct io_kiocb {
    struct io_ring_ctx *ctx;
    unsigned int flags;
    struct {
        void *files;
    } work;
    struct list_head inflight_entry;
};

struct io_ring_ctx {
    int inflight_lock;
    struct wait_queue_head inflight_wait;
};

#define REQ_F_INFLIGHT (1U << 0)

static inline void spin_lock_irqsave(int *lock, unsigned long flags) { (void)lock; (void)flags; }
static inline void spin_unlock_irqrestore(int *lock, unsigned long flags) { (void)lock; (void)flags; }
static inline void list_del(struct list_head *entry) { (void)entry; }
static inline int waitqueue_active(struct wait_queue_head *wq) { (void)wq; return 0; }
static inline void wake_up(struct wait_queue_head *wq) { (void)wq; }