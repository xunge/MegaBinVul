#include <stddef.h>

struct domain;
struct evtchn;

struct domain {
    unsigned int max_evtchns;
};

struct evtchn {
    int pending;
};

struct shared_info {
    unsigned long evtchn_pending;
};

#define EVTCHN_FIFO_PRIORITY_DEFAULT 0
#define shared_info(d, field) ((struct shared_info *)0)->field

static inline int port_is_valid(struct domain *d, unsigned int port) { return 0; }
static inline struct evtchn *evtchn_from_port(struct domain *d, unsigned int port) { return NULL; }
static inline int guest_test_bit(struct domain *d, unsigned int port, unsigned long *addr) { return 0; }
static inline void evtchn_fifo_set_priority(struct domain *d, struct evtchn *evtchn, int priority) {}