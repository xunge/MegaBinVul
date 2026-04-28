#include <stdint.h>
#include <stdbool.h>
#include <errno.h>
#include <stddef.h>

struct kvm {
    struct kvm_vcpu **vcpus;
    void *irq_srcu;
    void *irq_routing;
};

struct kvm_vcpu {
    int vcpu_id;
};

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct hlist_head {
    struct hlist_node *first;
};

struct kvm_kernel_irq_routing_entry {
    int type;
    unsigned int gsi;
    struct hlist_node link;
};

struct kvm_irq_routing_table {
    unsigned int nr_rt_entries;
    struct hlist_head *map;
};

struct kvm_lapic_irq {
    uint8_t vector;
};

struct vcpu_data {
    uint64_t pi_desc_addr;
    uint8_t vector;
};

#define IRQ_POSTING_CAP 1
#define KERN_INFO "<6>"
#define KVM_IRQ_ROUTING_MSI 1
#define __pa(x) ((uintptr_t)(x))

static inline int kvm_arch_has_assigned_device(struct kvm *kvm) { return 0; }
static inline int irq_remapping_cap(int cap) { return 0; }
static inline int kvm_vcpu_apicv_active(struct kvm_vcpu *vcpu) { return 0; }
static inline int srcu_read_lock(void *srcu) { return 0; }
static inline void *srcu_dereference(void *p, void *srcu) { return NULL; }
static inline void srcu_read_unlock(void *srcu, int idx) {}
static inline void BUG_ON(int condition) {}
#define hlist_for_each_entry(e, head, member) \
    for (e = (head)->first ? (struct kvm_kernel_irq_routing_entry *)((char *)((head)->first) - offsetof(struct kvm_kernel_irq_routing_entry, member)) : NULL; \
        e != NULL; \
        e = e->member.next ? (struct kvm_kernel_irq_routing_entry *)((char *)(e->member.next) - offsetof(struct kvm_kernel_irq_routing_entry, member)) : NULL)
static inline void kvm_set_msi_irq(struct kvm *kvm,
                                 struct kvm_kernel_irq_routing_entry *e,
                                 struct kvm_lapic_irq *irq) {}
static inline int kvm_intr_is_single_vcpu(struct kvm *kvm,
                                        struct kvm_lapic_irq *irq,
                                        struct kvm_vcpu **vcpu) { return 0; }
static inline int irq_set_vcpu_affinity(unsigned int irq, void *vcpu_info) { return 0; }
static inline void printk(const char *fmt, ...) {}
static inline void *vcpu_to_pi_desc(struct kvm_vcpu *vcpu) { return NULL; }
static inline void pi_set_sn(void *pi_desc) {}
static inline void pi_clear_sn(void *pi_desc) {}
static inline void trace_kvm_pi_irte_update(int vcpu_id, unsigned int host_irq,
                                          unsigned int gsi, uint8_t vector,
                                          uint64_t pi_desc_addr, bool set) {}