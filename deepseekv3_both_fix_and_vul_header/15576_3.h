#include <stddef.h>

typedef struct {
    int lock;
} spinlock_t;

struct list_head {
    struct list_head *next, *prev;
};

struct Qdisc;
struct net_device;
struct qdisc_watchdog {
    int dummy;
};

struct cbs_sched_data {
    struct list_head cbs_list;
    struct net_device *dev;
    struct Qdisc *qdisc;
    struct qdisc_watchdog watchdog;
};

extern spinlock_t cbs_list_lock;

static inline void list_del(struct list_head *entry) {
    entry->next->prev = entry->prev;
    entry->prev->next = entry->next;
}

static inline void spin_lock(spinlock_t *lock) { lock->lock = 1; }
static inline void spin_unlock(spinlock_t *lock) { lock->lock = 0; }

static inline struct cbs_sched_data *qdisc_priv(struct Qdisc *sch) { return (void*)0; }
static inline struct net_device *qdisc_dev(struct Qdisc *sch) { return (void*)0; }
static inline void qdisc_watchdog_cancel(struct qdisc_watchdog *w) {}
static inline void cbs_disable_offload(struct net_device *dev, struct cbs_sched_data *q) {}
static inline void qdisc_put(struct Qdisc *q) {}