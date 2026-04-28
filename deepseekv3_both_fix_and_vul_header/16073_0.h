#include <stdint.h>
#include <stddef.h>

struct domain;
struct vcpu;
struct evtchn;

#define unlikely(x) (x)
#define ASSERT(x) 
#define virq_is_global(x) (1)

struct domain {
    struct vcpu **vcpu;
};

struct vcpu {
    unsigned long virq_lock;
    int *virq_to_evtchn;
};

struct evtchn {
    int notify_vcpu_id;
    unsigned long lock;
};

static inline void spin_lock_irqsave(unsigned long *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(unsigned long *lock, unsigned long flags) {}
static inline void spin_lock(unsigned long *lock) {}
static inline void spin_unlock(unsigned long *lock) {}
static inline struct evtchn *evtchn_from_port(struct domain *d, int port) { return NULL; }
static inline void evtchn_port_set_pending(struct domain *d, int vcpu_id, struct evtchn *chn) {}