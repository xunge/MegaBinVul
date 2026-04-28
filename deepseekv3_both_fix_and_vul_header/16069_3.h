#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define IRQ_GUEST (1 << 0)
#define FIRST_DYNAMIC_VECTOR 0x20
#define X86_NR_VECTORS 256
#define CPUMASK_PR(mask) (mask)

struct irq_type {
    const char *typename;
};

struct irq_handler {
    void (*handler)(void);
};

struct irq_desc {
    struct irq_type *handler;
    unsigned long status;
    struct {
        int vector;
        void *cpu_mask;
    } arch;
    struct irq_handler *action;
    void *lock;
    void *affinity;
};

struct domain {
    int domain_id;
};

struct pirq {
    int evtchn;
    bool masked;
};

struct evtchn {
    void *lock;
};

struct irq_guest_action {
    int in_flight;
    int nr_guests;
    struct domain **guest;
};

typedef struct irq_guest_action irq_guest_action_t;

extern unsigned int nr_irqs;
extern void (*direct_apic_vector[])(void);
extern struct irq_type no_irq_type;

void printk(const char *fmt, ...);
void process_pending_softirqs(void);
struct irq_desc *irq_to_desc(int irq);
int irq_desc_initialized(struct irq_desc *desc);
int in_irq(void);
char *xsm_show_irq_sid(int irq);
void spin_lock_irqsave(void *lock, unsigned long flags);
void spin_unlock_irqrestore(void *lock, unsigned long flags);
void local_irq_disable(void);
void local_irq_enable(void);
int spin_trylock(void *lock);
void spin_unlock(void *lock);
int domain_irq_to_pirq(struct domain *d, int irq);
const struct pirq *pirq_info(struct domain *d, int pirq);
struct evtchn *evtchn_from_port(struct domain *d, int port);
int evtchn_is_pending(struct domain *d, struct evtchn *evtchn);
int evtchn_is_masked(struct domain *d, struct evtchn *evtchn);
int evtchn_port_is_pending(struct domain *d, int port);
int evtchn_port_is_masked(struct domain *d, int port);
void xfree(void *ptr);
void dump_ioapic_irq_info(void);