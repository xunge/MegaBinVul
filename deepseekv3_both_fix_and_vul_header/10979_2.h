#include <stdint.h>

#define RUNTIME_INF ((uint64_t)~0ULL)

typedef int64_t s64;
typedef uint64_t u64;

struct list_head {
    struct list_head *next, *prev;
};

struct cfs_bandwidth {
    int lock;
    u64 quota;
    u64 runtime;
    u64 runtime_expires;
    struct list_head throttled_cfs_rq;
};

struct task_group;
struct cfs_rq {
    struct task_group *tg;
    s64 runtime_remaining;
    u64 runtime_expires;
};

extern struct cfs_bandwidth *tg_cfs_bandwidth(struct task_group *tg);
extern u64 sched_cfs_bandwidth_slice(void);
extern void start_cfs_slack_bandwidth(struct cfs_bandwidth *cfs_b);

static const s64 min_cfs_rq_runtime = 1;

static inline void raw_spin_lock(int *lock) { *lock = 1; }
static inline void raw_spin_unlock(int *lock) { *lock = 0; }
static inline int list_empty(struct list_head *head) { return head->next == head; }