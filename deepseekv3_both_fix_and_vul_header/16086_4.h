#include <stddef.h>

#define DOMID_SELF 0
#define ECS_UNBOUND 0
#define ECS_INTERDOMAIN 1
#define ESRCH 3
#define EINVAL 22
#define XSM_HOOK 0

typedef int domid_t;

struct domain {
    domid_t domain_id;
    void *event_lock;
};

struct evtchn {
    int state;
    union {
        struct {
            domid_t remote_domid;
        } unbound;
        struct {
            struct domain *remote_dom;
            int remote_port;
        } interdomain;
    } u;
    int notify_vcpu_id;
};

typedef struct {
    int remote_port;
    domid_t remote_dom;
    int local_port;
} evtchn_bind_interdomain_t;

struct current_info {
    struct domain *domain;
};

extern struct current_info *current;
extern struct domain *rcu_lock_domain_by_id(domid_t domid);
extern void rcu_unlock_domain(struct domain *d);
extern void spin_lock(void *lock);
extern void spin_unlock(void *lock);
extern int get_free_port(struct domain *d);
extern struct evtchn *evtchn_from_port(struct domain *d, int port);
extern int port_is_valid(struct domain *d, int port);
extern long xsm_evtchn_interdomain(int hook, struct domain *ld, struct evtchn *lchn, struct domain *rd, struct evtchn *rchn);
extern void double_evtchn_lock(struct evtchn *lchn, struct evtchn *rchn);
extern void double_evtchn_unlock(struct evtchn *lchn, struct evtchn *rchn);
extern void evtchn_port_init(struct domain *d, struct evtchn *chn);
extern void evtchn_port_set_pending(struct domain *d, int vcpu_id, struct evtchn *chn);

#define ERROR_EXIT(rc) do { rc = (rc); goto out; } while (0)
#define ERROR_EXIT_DOM(rc_val, dom) do { rc = (rc_val); goto out; } while (0)