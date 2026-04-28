#include <stdbool.h>
#include <stddef.h>

#define EINVAL 22
#define unlikely(x) (x)
#define BUG() do { } while (1)
#define BUG_ON(cond) do { if (cond) BUG(); } while (0)
#define spin_lock(lock) do { } while (0)
#define spin_unlock(lock) do { } while (0)
#define spin_lock_irqsave(lock, flags) do { (flags) = 0; } while (0)
#define spin_unlock_irqrestore(lock, flags) do { } while (0)
#define spin_barrier(lock) do { } while (0)
#define for_each_vcpu(d, v) for ((v) = NULL; (v) != NULL; (v) = NULL)

struct domain {
    int domain_id;
    struct vcpu **vcpu;
    void *event_lock;
    bool is_hvm;
};

struct vcpu {
    int *virq_to_evtchn;
    void *virq_lock;
};

struct evtchn {
    int state;
    int notify_vcpu_id;
    union {
        struct {
            int irq;
        } pirq;
        int virq;
        struct {
            struct domain *remote_dom;
            int remote_port;
        } interdomain;
        struct {
            int remote_domid;
        } unbound;
    } u;
    void *lock;
};

struct pirq {
    int pirq;
    int evtchn;
};

enum {
    ECS_FREE,
    ECS_RESERVED,
    ECS_UNBOUND,
    ECS_PIRQ,
    ECS_VIRQ,
    ECS_IPI,
    ECS_INTERDOMAIN
};

static inline bool port_is_valid(struct domain *d, int port) { return false; }
static inline struct evtchn *evtchn_from_port(struct domain *d, int port) { return NULL; }
static inline bool consumer_is_xen(struct evtchn *chn) { return false; }
static inline void evtchn_free(struct domain *d, struct evtchn *chn) { }
static inline struct pirq *pirq_info(struct domain *d, int irq) { return NULL; }
static inline void pirq_guest_unbind(struct domain *d, struct pirq *pirq) { }
static inline void pirq_cleanup_check(struct pirq *pirq, struct domain *d) { }
static inline void unlink_pirq_port(struct evtchn *chn, struct vcpu *v) { }
static inline int domain_pirq_to_irq(struct domain *d, int pirq) { return 0; }
static inline void unmap_domain_pirq_emuirq(struct domain *d, int pirq) { }
static inline bool get_domain(struct domain *d) { return false; }
static inline void put_domain(struct domain *d) { }
static inline unsigned long double_evtchn_lock(struct evtchn *chn1, struct evtchn *chn2) { return 0; }
static inline void double_evtchn_unlock(struct evtchn *chn1, struct evtchn *chn2, ...) { }
static inline bool is_hvm_domain(struct domain *d) { return d->is_hvm; }