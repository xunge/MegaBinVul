#include <stddef.h>
#include <stdint.h>

#define KVM_IOAPIC_NUM_PINS 24
#define EINVAL 22

#define KVM_IRQCHIP_PIC_MASTER 0
#define KVM_IRQCHIP_PIC_SLAVE 1
#define KVM_IRQCHIP_IOAPIC 2

#define KVM_IRQ_ROUTING_IRQCHIP 1
#define KVM_IRQ_ROUTING_MSI 2

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct hlist_head {
    struct hlist_node *first;
};

struct kvm_irq_routing_table {
    int chip[3][KVM_IOAPIC_NUM_PINS];
    struct hlist_head map[];
};

struct kvm_kernel_irq_routing_entry {
    struct hlist_node link;
    int gsi;
    int type;
    union {
        struct {
            int irqchip;
            int pin;
        } irqchip;
        struct {
            uint32_t address_lo;
            uint32_t address_hi;
            uint32_t data;
        } msi;
    };
    int (*set)(struct kvm_kernel_irq_routing_entry *e, void *kvm, int irq_source_id, int level);
};

struct kvm_irq_routing_entry {
    int gsi;
    int type;
    union {
        struct {
            int irqchip;
            int pin;
        } irqchip;
        struct {
            uint32_t address_lo;
            uint32_t address_hi;
            uint32_t data;
        } msi;
    } u;
};

#define hlist_for_each_entry(pos, n, head, member) \
    for (pos = NULL, n = (head)->first; n && \
        (pos = (struct kvm_kernel_irq_routing_entry *)((char *)n - offsetof(struct kvm_kernel_irq_routing_entry, member))); \
        n = n->next)

static inline void hlist_add_head(struct hlist_node *n, struct hlist_head *h) {
    n->next = h->first;
    if (h->first) h->first->pprev = &n->next;
    h->first = n;
    n->pprev = &h->first;
}

static int kvm_set_pic_irq(struct kvm_kernel_irq_routing_entry *e, void *kvm, int irq_source_id, int level) { return 0; }
static int kvm_set_ioapic_irq(struct kvm_kernel_irq_routing_entry *e, void *kvm, int irq_source_id, int level) { return 0; }
static int kvm_set_msi(struct kvm_kernel_irq_routing_entry *e, void *kvm, int irq_source_id, int level) { return 0; }