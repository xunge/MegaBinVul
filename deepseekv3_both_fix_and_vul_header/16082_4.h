#include <stdint.h>
#include <limits.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_VIRT_CPUS 64
#define BITS_PER_LONG 64
#define BITS_TO_LONGS(nr) (((nr) + BITS_PER_LONG - 1) / BITS_PER_LONG)
#define EVTCHNS_PER_BUCKET 64
#define min_t(type, x, y) ((x) < (y) ? (x) : (y))

#define ECS_RESERVED 1

static const char *event_lock = "event_lock";

struct evtchn {
    int state;
};

struct domain {
    unsigned int max_evtchn_port;
    struct evtchn *evtchn;
    unsigned int valid_evtchns;
    unsigned long *poll_mask;
    unsigned int max_vcpus;
    int active_evtchns;
};

void evtchn_2l_init(struct domain *d);
struct evtchn *alloc_evtchn_bucket(struct domain *d, int flags);
void free_evtchn_bucket(struct domain *d, struct evtchn *evtchn);
void spin_lock_init_prof(struct domain *d, const char *name);
int get_free_port(struct domain *d);
struct evtchn *evtchn_from_port(struct domain *d, unsigned int port);
void write_atomic(int *ptr, int val);
void *xzalloc_array(unsigned long, size_t);