#include <stdint.h>

typedef uint64_t u64;
#define RUNTIME_INF ((u64)~0ULL)

struct list_head {
    struct list_head *next, *prev;
};

struct cfs_bandwidth {
    u64 quota;
    u64 runtime;
    u64 runtime_expires;
    int idle;
    int nr_periods;
    int nr_throttled;
    int distribute_running;
    struct list_head throttled_cfs_rq;
    unsigned long lock;
};

int list_empty(const struct list_head *head);
void __refill_cfs_bandwidth_runtime(struct cfs_bandwidth *cfs_b);
u64 distribute_cfs_runtime(struct cfs_bandwidth *cfs_b, u64 runtime, ...);
void lsub_positive(u64 *dst, u64 dec);
void raw_spin_unlock_irqrestore(unsigned long *lock, unsigned long flags);
void raw_spin_lock_irqsave(unsigned long *lock, unsigned long flags);