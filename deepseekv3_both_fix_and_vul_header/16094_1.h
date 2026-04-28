#include <stddef.h>
#include <stdbool.h>

#define unlikely(x) (x)
#define EINVAL 22

typedef struct spinlock {
    int lock;
} spinlock_t;

static inline void spin_lock(spinlock_t *lock) { (void)lock; }
static inline void spin_unlock(spinlock_t *lock) { (void)lock; }

struct vcpu;

struct domain {
    struct vcpu **vcpu;
};

enum evtchn_state {
    ECS_INTERDOMAIN,
    ECS_IPI, 
    ECS_UNBOUND
};

struct interdomain_info {
    struct domain *remote_dom;
    unsigned int remote_port;
};

struct evtchn {
    spinlock_t lock;
    enum evtchn_state state;
    union {
        struct interdomain_info interdomain;
    } u;
    unsigned int notify_vcpu_id;
};

typedef void (*xen_notification_fn_t)(struct vcpu *, unsigned int);

#define XSM_HOOK NULL

int port_is_valid(struct domain *ld, unsigned int lport);
struct evtchn *evtchn_from_port(struct domain *d, unsigned int port);
bool consumer_is_xen(struct evtchn *chn);
int xsm_evtchn_send(void *hook, struct domain *ld, struct evtchn *lchn);
xen_notification_fn_t xen_notification_fn(struct evtchn *chn);
void evtchn_port_set_pending(struct domain *d, unsigned int vcpu_id, struct evtchn *chn);