#include <stdint.h>
#include <stdbool.h>

#define RUNTIME_INF (~0ULL)

typedef uint64_t u64;

struct cfs_bandwidth {
    int lock;
    bool slack_started;
    bool distribute_running;
    u64 quota;
    u64 runtime;
    u64 runtime_expires;
};

extern u64 sched_cfs_bandwidth_slice(void);
extern bool runtime_refresh_within(struct cfs_bandwidth *cfs_b, u64 min_expiration);
extern u64 distribute_cfs_runtime(struct cfs_bandwidth *cfs_b, u64 runtime, ...);
extern void lsub_positive(u64 *dst, u64 decr);
extern void raw_spin_lock_irqsave(int *lock, unsigned long flags);
extern void raw_spin_unlock_irqrestore(int *lock, unsigned long flags);

static u64 min_bandwidth_expiration;