#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define KEYHANDLER_SCRATCH_SIZE 1024

struct domain {
    unsigned int domain_id;
    unsigned int max_vcpus;
    unsigned long *poll_mask;
    unsigned int max_evtchns;
    int event_lock;
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

#define ECS_FREE 0
#define ECS_UNBOUND 1
#define ECS_INTERDOMAIN 2
#define ECS_PIRQ 3
#define ECS_VIRQ 4

char keyhandler_scratch[KEYHANDLER_SCRATCH_SIZE];

static inline void spin_lock(int *lock) { (void)lock; }
static inline void spin_unlock(int *lock) { (void)lock; }
static inline int port_is_valid(struct domain *d, unsigned int port) { (void)d; (void)port; return 0; }
static inline const struct evtchn *evtchn_from_port(struct domain *d, unsigned int port) { (void)d; (void)port; return NULL; }
static inline int evtchn_port_is_pending(struct domain *d, const struct evtchn *chn) { (void)d; (void)chn; return 0; }
static inline int evtchn_port_is_masked(struct domain *d, const struct evtchn *chn) { (void)d; (void)chn; return 0; }
static inline void evtchn_port_print_state(struct domain *d, const struct evtchn *chn) { (void)d; (void)chn; }
static inline int domain_pirq_to_irq(struct domain *d, int pirq) { (void)d; (void)pirq; return 0; }
static inline char *xsm_show_security_evtchn(struct domain *d, const struct evtchn *chn) { (void)d; (void)chn; return NULL; }
static inline void xfree(void *ptr) { (void)ptr; }
static inline void bitmap_scnlistprintf(char *buf, size_t size, unsigned long *bitmap, int nbits) { (void)buf; (void)size; (void)bitmap; (void)nbits; }
static inline void printk(const char *fmt, ...) { (void)fmt; }