#include <stddef.h>

#define EINVAL 22
#define EPERM 1
#define EEXIST 17
#define ENOMEM 12

#define BIND_PIRQ__WILL_SHARE (1 << 0)

typedef struct evtchn_bind_pirq_t {
    int pirq;
    int flags;
    int port;
} evtchn_bind_pirq_t;

struct evtchn {
    int state;
    int lock;
    union {
        struct {
            int irq;
        } pirq;
    } u;
};

struct domain {
    int nr_pirqs;
    struct vcpu **vcpu;
    int event_lock;
};

struct vcpu {
};

struct pirq {
    int evtchn;
};

extern struct {
    struct domain *domain;
} *current;
extern int is_hvm_domain(struct domain *d);
extern int pirq_access_permitted(struct domain *d, int pirq);
extern int pirq_to_evtchn(struct domain *d, int pirq);
extern int get_free_port(struct domain *d);
extern struct evtchn *evtchn_from_port(struct domain *d, int port);
extern struct pirq *pirq_get_info(struct domain *d, int pirq);
extern int pirq_guest_bind(struct vcpu *v, struct pirq *info, int will_share);
extern void pirq_cleanup_check(struct pirq *info, struct domain *d);
extern void link_pirq_port(int port, struct evtchn *chn, struct vcpu *v);
extern void evtchn_port_init(struct domain *d, struct evtchn *chn);
extern void arch_evtchn_bind_pirq(struct domain *d, int pirq);
extern void spin_lock(int *lock);
extern void spin_unlock(int *lock);

#define ECS_PIRQ 0
#define ERROR_EXIT(x) do { rc = (x); goto out; } while (0)