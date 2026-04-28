#include <stddef.h>
#include <stdint.h>

#define ESRCH 3
#define DOMID_SELF 0
#define ECS_UNBOUND 0
#define XSM_TARGET 0

typedef uint16_t domid_t;

struct unbound_info {
    domid_t remote_domid;
};

struct evtchn {
    int state;
    union {
        struct unbound_info unbound;
    } u;
    int lock;
};

struct domain {
    int domain_id;
    int event_lock;
};

typedef struct {
    domid_t dom;
    domid_t remote_dom;
    int port;
} evtchn_alloc_unbound_t;

struct task_struct {
    struct domain *domain;
};
extern struct task_struct *current;

void spin_lock(int *lock);
void spin_unlock(int *lock);
void spin_lock_irqsave(int *lock, unsigned long flags);
void spin_unlock_irqrestore(int *lock, unsigned long flags);
struct domain *rcu_lock_domain_by_any_id(domid_t dom);
void rcu_unlock_domain(struct domain *d);
int get_free_port(struct domain *d);
struct evtchn *evtchn_from_port(struct domain *d, int port);
int xsm_evtchn_unbound(int target, struct domain *d, struct evtchn *chn, domid_t remote_dom);
void evtchn_port_init(struct domain *d, struct evtchn *chn);
void check_free_port(struct domain *d, int port);
void ERROR_EXIT_DOM(int port, struct domain *d);