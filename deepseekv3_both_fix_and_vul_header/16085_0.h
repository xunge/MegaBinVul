#include <stdatomic.h>

#define ECS_FREE 0

struct domain {
    _Atomic int xen_evtchns;
    _Atomic int active_evtchns;
};

struct evtchn {
    int state;
    int notify_vcpu_id;
    int xen_consumer;
};

int consumer_is_xen(struct evtchn *chn);
void evtchn_port_clear_pending(struct domain *d, struct evtchn *chn);
void xsm_evtchn_close_post(struct evtchn *chn);