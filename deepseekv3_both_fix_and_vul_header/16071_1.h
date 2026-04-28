#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

#define printk printf
#define xfree free

#define ECS_FREE 0
#define ECS_UNBOUND 1
#define ECS_INTERDOMAIN 2
#define ECS_PIRQ 3
#define ECS_VIRQ 4

typedef struct spinlock {
    int lock;
} spinlock_t;

struct domain {
    int domain_id;
    int max_vcpus;
    unsigned long *poll_mask;
    spinlock_t event_lock;
};

struct evtchn {
    int state;
    int notify_vcpu_id;
    int xen_consumer;
    union {
        struct {
            int remote_domid;
        } unbound;
        struct {
            struct domain *remote_dom;
            int remote_port;
        } interdomain;
        struct {
            int irq;
        } pirq;
        int virq;
    } u;
};

static inline void spin_lock(spinlock_t *lock) { (void)lock; }
static inline void spin_unlock(spinlock_t *lock) { (void)lock; }
static inline int port_is_valid(struct domain *d, unsigned int port) { (void)d; (void)port; return 0; }
static inline struct evtchn *evtchn_from_port(struct domain *d, unsigned int port) { (void)d; (void)port; return NULL; }
static inline int evtchn_port_is_pending(struct domain *d, unsigned int port) { (void)d; (void)port; return 0; }
static inline int evtchn_port_is_masked(struct domain *d, unsigned int port) { (void)d; (void)port; return 0; }
static inline void evtchn_port_print_state(struct domain *d, const struct evtchn *chn) { (void)d; (void)chn; }
static inline int domain_pirq_to_irq(struct domain *d, int pirq) { (void)d; (void)pirq; return 0; }
static inline char *xsm_show_security_evtchn(struct domain *d, const struct evtchn *chn) { (void)d; (void)chn; return NULL; }