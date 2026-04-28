#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define NR_VECTORS 256
#define FIRST_DYNAMIC_VECTOR 32
#define IRQ_GUEST (1 << 0)

struct irq_type {
    const char *typename;
};

struct irq_desc {
    struct irq_type *handler;
    struct irq_action *action;
    unsigned long status;
    struct {
        int vector;
    } arch;
    unsigned long lock;
    char *affinity;
};

struct irq_action {
    void (*handler)(void);
    struct irq_guest_action *guest_action;
};

struct irq_guest_action {
    int nr_guests;
    int in_flight;
    struct domain **guest;
};

typedef struct irq_guest_action irq_guest_action_t;

struct domain {
    int domain_id;
};

struct pirq {
    int evtchn;
    int masked;
};

struct evtchn {
};

static char keyhandler_scratch[1024];
static int nr_irqs;
static void *direct_apic_vector[NR_VECTORS];
static struct irq_type no_irq_type;

static int in_irq(void) { return 0; }
static char *xsm_show_irq_sid(int irq) { return NULL; }
static void spin_lock_irqsave(unsigned long *lock, unsigned long flags) {}
static void spin_unlock_irqrestore(unsigned long *lock, unsigned long flags) {}
static void xfree(void *ptr) {}
static void printk(const char *fmt, ...) {}
static void process_pending_softirqs(void) {}
static void dump_ioapic_irq_info(void) {}
static struct irq_desc *irq_to_desc(int irq) { return NULL; }
static int irq_desc_initialized(struct irq_desc *desc) { return 0; }
static int domain_irq_to_pirq(struct domain *d, int irq) { return 0; }
static struct pirq *pirq_info(struct domain *d, int pirq) { return NULL; }
static struct evtchn *evtchn_from_port(struct domain *d, int port) { return NULL; }
static int evtchn_port_is_pending(struct domain *d, struct evtchn *evtchn) { return 0; }
static int evtchn_port_is_masked(struct domain *d, struct evtchn *evtchn) { return 0; }
static int cpumask_scnprintf(char *buf, size_t size, char *mask) { return 0; }