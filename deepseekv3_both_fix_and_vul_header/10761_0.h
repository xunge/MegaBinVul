#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define unlikely(x) (x)
#define ASSERT(x) 
#define spin_is_locked(x) (1)
#define test_bit(bit, addr) (0)
#define GIC_IRQ_GUEST_ENABLED 0
#define GIC_DEBUG
#define XENLOG_DEBUG 0
#define gdprintk(level, fmt, ...) 

struct list_head {
    struct list_head *next, *prev;
};

struct pending_irq {
    unsigned long status;
    struct list_head lr_queue;
    int lr;
};

struct vgic_arch {
    int lock;
};

struct domain {
    int domain_id;
};

struct vcpu {
    struct domain *domain;
    int vcpu_id;
    struct {
        struct vgic_arch vgic;
    } arch;
};

extern struct vcpu *current;
struct pending_irq *irq_to_pending(struct vcpu *v, unsigned int irq);
void gic_update_one_lr(struct vcpu *v, int lr);