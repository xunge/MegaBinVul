#include <stdbool.h>
#include <stddef.h>

struct kvm {
    struct {
        void *apic_map;
    } arch;
};

struct kvm_lapic {
    void *vcpu;
};

struct kvm_lapic_irq {
    int shorthand;
};

struct dest_map {};
struct kvm_apic_map {};

#define APIC_DEST_SELF 0

static inline void rcu_read_lock(void) {}
static inline void rcu_read_unlock(void) {}
static inline void *rcu_dereference(void *p) { return p; }

static inline int kvm_apic_set_irq(void *vcpu, struct kvm_lapic_irq *irq, struct dest_map *dest_map) { return 0; }
static inline bool kvm_apic_map_get_dest_lapic(struct kvm *kvm, struct kvm_lapic **src, 
        struct kvm_lapic_irq *irq, struct kvm_apic_map *map, 
        struct kvm_lapic ***dst, unsigned long *bitmap) { return false; }

static inline int find_first_bit(const unsigned long *addr, int size) { return 0; }
static inline int find_next_bit(const unsigned long *addr, int size, int offset) { return 0; }
#define for_each_set_bit(bit, addr, size) \
    for ((bit) = find_first_bit((addr), (size)); \
         (bit) < (size); \
         (bit) = find_next_bit((addr), (size), (bit) + 1))