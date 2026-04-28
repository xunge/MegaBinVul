#include <stddef.h>

struct mm_struct;

struct mmu_notifier {
    int dummy; 
};

struct srcu_struct {
    int dummy;
};

struct kvm {
    struct srcu_struct srcu;
    struct mmu_notifier mmu_notifier;
};

static inline struct kvm *mmu_notifier_to_kvm(struct mmu_notifier *mn) {
    return (struct kvm *)((char *)mn - offsetof(struct kvm, mmu_notifier));
}

int srcu_read_lock(struct srcu_struct *sp);
void srcu_read_unlock(struct srcu_struct *sp, int idx);
void kvm_arch_flush_shadow_all(struct kvm *kvm);