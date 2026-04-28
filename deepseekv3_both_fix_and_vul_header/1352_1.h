#include <stdint.h>
#include <pthread.h>

struct kvm {
    pthread_mutex_t slots_arch_lock;
};

struct kvm_memory_slot {
    uint32_t flags;
    uint32_t as_id;
    struct {
        /* arch-specific data */
    } arch;
};

extern void kvm_copy_memslot(struct kvm_memory_slot *dest, struct kvm_memory_slot *src);
extern void kvm_replace_memslot(struct kvm *kvm, struct kvm_memory_slot *old, struct kvm_memory_slot *new);
extern void kvm_swap_active_memslots(struct kvm *kvm, uint32_t as_id);
extern void kvm_arch_flush_shadow_memslot(struct kvm *kvm, struct kvm_memory_slot *slot);

#define KVM_MEMSLOT_INVALID (1U << 0)