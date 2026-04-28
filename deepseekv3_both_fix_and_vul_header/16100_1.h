#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#define printk printf

struct domain {
    int domain_id;
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

#define spin_lock(lock) ((void)0)
#define spin_unlock(lock) ((void)0)