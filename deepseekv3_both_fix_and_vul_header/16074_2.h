#include <stdint.h>
#include <stdbool.h>

typedef int spinlock_t;

struct domain {
    // dummy definition
};

struct evtchn {
    spinlock_t lock;
    // dummy definition
};

struct vcpu {
    spinlock_t virq_lock;
    struct domain *domain;
    int vcpu_id;
    int virq_to_evtchn[];
    // dummy definition
};

static inline void spin_lock_irqsave(spinlock_t *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(spinlock_t *lock, unsigned long flags) {}
static inline void spin_lock(spinlock_t *lock) {}
static inline void spin_unlock(spinlock_t *lock) {}

extern bool virq_is_global(uint32_t virq);
extern struct evtchn *evtchn_from_port(struct domain *d, int port);
extern void evtchn_port_set_pending(struct domain *d, int vcpu_id, struct evtchn *chn);

#define unlikely(x) (x)
#define ASSERT(x) do { if (!(x)) { } } while (0)