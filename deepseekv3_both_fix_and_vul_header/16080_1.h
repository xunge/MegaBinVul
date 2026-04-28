#include <stddef.h>
#include <stdint.h>

#define ESRCH 3
#define DOMID_SELF 0x7FF0
#define ECS_UNBOUND 1
#define XSM_TARGET 0

typedef uint16_t domid_t;

struct domain {
    int domain_id;
    void *event_lock;
};

struct evtchn {
    int state;
    void *lock;
    union {
        struct {
            domid_t remote_domid;
        } unbound;
    } u;
};

struct current_struct {
    struct domain *domain;
};

extern struct current_struct *current;

typedef struct {
    domid_t dom;
    domid_t remote_dom;
    int port;
} evtchn_alloc_unbound_t;

extern struct domain *rcu_lock_domain_by_any_id(domid_t dom);
extern void rcu_unlock_domain(struct domain *d);
extern int get_free_port(struct domain *d);
extern struct evtchn *evtchn_from_port(struct domain *d, int port);
extern long xsm_evtchn_unbound(int target, struct domain *d, struct evtchn *chn, domid_t remote_dom);
extern void evtchn_port_init(struct domain *d, struct evtchn *chn);

#define ERROR_EXIT_DOM(port, d) do { \
    spin_unlock(&(d)->event_lock); \
    rcu_unlock_domain(d); \
    return (port); \
} while (0)