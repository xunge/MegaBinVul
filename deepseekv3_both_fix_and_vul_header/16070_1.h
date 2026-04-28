#include <stddef.h>
#include <stdbool.h>

struct domain;
struct pirq {
    int evtchn;
};
struct evtchn {
    int notify_vcpu_id;
    unsigned long lock;
};

extern bool is_hvm_domain(struct domain *d);
extern struct evtchn *evtchn_from_port(struct domain *d, int port);
extern void evtchn_port_set_pending(struct domain *d, int vcpu_id, struct evtchn *chn);
extern void BUG_ON(bool condition);

#ifdef CONFIG_SPINLOCK
#include <spinlock.h>
#else
#define spin_lock_irqsave(lock, flags) ((void)0)
#define spin_unlock_irqrestore(lock, flags) ((void)0)
#endif