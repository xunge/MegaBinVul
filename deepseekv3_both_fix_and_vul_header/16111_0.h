#include <stdbool.h>
#include <stddef.h>

struct domain;
struct evtchn;

#define ASSERT(cond) ((void)0)
#define likely(x) (x)

enum evtchn_state {
    ECS_INTERDOMAIN
};

struct evtchn {
    unsigned long lock;
    enum evtchn_state state;
    union {
        struct {
            struct domain *remote_dom;
            int remote_port;
        } interdomain;
    } u;
    int notify_vcpu_id;
};

bool port_is_valid(struct domain *ld, int lport);
struct evtchn *evtchn_from_port(struct domain *ld, int lport);
void spin_lock_irqsave(unsigned long *lock, unsigned long flags);
void spin_unlock_irqrestore(unsigned long *lock, unsigned long flags);
void evtchn_port_set_pending(struct domain *rd, int vcpu_id, struct evtchn *rchn);
bool consumer_is_xen(struct evtchn *chn);