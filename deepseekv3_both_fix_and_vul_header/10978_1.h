#include <stdint.h>
#include <stddef.h>

typedef uint64_t u64;

struct task_group {
    struct cfs_bandwidth *cfs_b;
};

struct cfs_rq {
    struct task_group *tg;
    u64 runtime_remaining;
    int expires_seq;
    u64 runtime_expires;
};

struct cfs_bandwidth {
    u64 quota;
    u64 runtime;
    u64 runtime_expires;
    int expires_seq;
    int idle;
    void *lock;
};

#define RUNTIME_INF ((u64)~0ULL)

static inline u64 min(u64 a, u64 b) { return a < b ? a : b; }
static inline struct cfs_bandwidth *tg_cfs_bandwidth(struct task_group *tg) { return tg->cfs_b; }
static inline u64 sched_cfs_bandwidth_slice(void) { return 0; }
static inline void start_cfs_bandwidth(struct cfs_bandwidth *cfs_b) {}
static inline void raw_spin_lock(void *lock) {}
static inline void raw_spin_unlock(void *lock) {}