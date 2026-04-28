#include <stdint.h>
#include <stdatomic.h>

typedef uint16_t domid_t;

#define XSM_TARGET 0

typedef struct spinlock {
    int dummy;
} spinlock_t;

struct unbound_info {
    domid_t remote_domid;
};

struct evtchn_u {
    struct unbound_info unbound;
};

struct evtchn {
    int state;
    void *xen_consumer;
    unsigned int notify_vcpu_id;
    struct evtchn_u u;
    spinlock_t lock;
};

struct domain {
    _Atomic int xen_evtchns;
    spinlock_t event_lock;
};

enum {
    ECS_UNBOUND
};

typedef void (*xen_event_channel_notification_t)(void);

void *get_xen_consumer(xen_event_channel_notification_t fn);
int get_free_port(struct domain *ld);
int xsm_evtchn_unbound(int target, struct domain *ld, struct evtchn *chn, domid_t remote_domid);
void check_free_port(struct domain *ld, int port);
struct evtchn *evtchn_from_port(struct domain *ld, int port);

static inline void spin_lock(spinlock_t *lock) { (void)lock; }
static inline void spin_unlock(spinlock_t *lock) { (void)lock; }
static inline void write_atomic(_Atomic int *ptr, int val) { *ptr = val; }