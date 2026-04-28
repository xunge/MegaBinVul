#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

struct guest;
struct evtchn {
    unsigned int notify_vcpu_id;
    unsigned long lock;
};

extern struct guest *guest;

bool port_is_valid(struct guest *g, unsigned int port);
struct evtchn *evtchn_from_port(struct guest *g, unsigned int port);
void evtchn_port_set_pending(struct guest *g, unsigned int vcpu_id, struct evtchn *chn);
void spin_lock_irqsave(unsigned long *lock, unsigned long flags);
void spin_unlock_irqrestore(unsigned long *lock, unsigned long flags);