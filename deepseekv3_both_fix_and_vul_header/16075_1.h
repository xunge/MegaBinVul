#include <stddef.h>
#include <stdbool.h>

struct domain {
    struct domain *domain;
};
struct evtchn {
    unsigned long lock;
};
struct {
    struct domain *domain;
} *current;

#define unlikely(x) (x)
#define EINVAL 22

bool port_is_valid(struct domain *d, unsigned int port);
struct evtchn *evtchn_from_port(struct domain *d, unsigned int port);
void evtchn_port_unmask(struct domain *d, struct evtchn *evtchn);
void spin_lock_irqsave(unsigned long *lock, unsigned long flags);
void spin_unlock_irqrestore(unsigned long *lock, unsigned long flags);