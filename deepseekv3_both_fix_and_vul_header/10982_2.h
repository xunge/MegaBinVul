#include <stdint.h>
#include <stddef.h>

typedef uint64_t u64;
typedef int64_t s64;

struct list_head {
    struct list_head *next, *prev;
};

struct cfs_bandwidth {
    struct list_head throttled_cfs_rq;
};

struct cfs_rq {
    s64 runtime_remaining;
    u64 runtime_expires;
    struct list_head throttled_list;
};

struct rq;
struct rq_flags {
    unsigned long flags;
};

#define rcu_read_lock()
#define rcu_read_unlock()
#define list_for_each_entry_rcu(pos, head, member) \
    for (pos = NULL; pos != (typeof(*pos)*)(head); )

static inline struct rq *rq_of(struct cfs_rq *cfs_rq) { return NULL; }
static inline void rq_lock_irqsave(struct rq *rq, struct rq_flags *rf) {}
static inline void rq_unlock_irqrestore(struct rq *rq, struct rq_flags *rf) {}
static inline int cfs_rq_throttled(struct cfs_rq *cfs_rq) { return 0; }
static inline void unthrottle_cfs_rq(struct cfs_rq *cfs_rq) {}