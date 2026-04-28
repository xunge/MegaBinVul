#include <stdint.h>

typedef uint16_t domid_t;
typedef void (*xen_event_channel_notification_t)(void);

struct domain {
    int event_lock;
    int xen_evtchns;
};

struct unbound_info {
    domid_t remote_domid;
};

struct evtchn {
    int lock;
    int state;
    void *xen_consumer;
    unsigned int notify_vcpu_id;
    union {
        struct unbound_info unbound;
    } u;
};

#define ECS_UNBOUND 0
#define XSM_TARGET 0

void spin_lock(int *lock);
void spin_unlock(int *lock);
void write_atomic(int *ptr, int val);
int get_free_port(struct domain *ld);
struct evtchn *evtchn_from_port(struct domain *ld, int port);
int xsm_evtchn_unbound(int target, struct domain *ld, struct evtchn *chn, domid_t remote_domid);
void *get_xen_consumer(xen_event_channel_notification_t notification_fn);
void check_free_port(struct domain *ld, int port);