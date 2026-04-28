#include <stddef.h>

#define ENOSPC 28

struct domain;
struct evtchn;

#define EVTCHN_FIFO_EVENT_WORDS_PER_PAGE 1024
#define EVTCHN_FIFO_MAX_EVENT_ARRAY_PAGES 32

struct evtchn_fifo {
    unsigned int num_evtchns;
    void *event_array[EVTCHN_FIFO_MAX_EVENT_ARRAY_PAGES];
};

struct domain {
    struct evtchn_fifo *evtchn_fifo;
    struct vcpu **vcpu;
};

struct evtchn {
    unsigned int notify_vcpu_id;
    int pending;
};

static int map_guest_page(struct domain *d, unsigned long gfn, void **virt);
static int port_is_valid(struct domain *d, unsigned int port);
static struct evtchn *evtchn_from_port(struct domain *d, unsigned int port);
static void evtchn_fifo_set_pending(struct vcpu *vcpu, struct evtchn *evtchn);