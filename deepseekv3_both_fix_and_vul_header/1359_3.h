#include <stdbool.h>

struct mmu_notifier;
struct kvm_gfn_range;

struct mmu_notifier_range {
    unsigned long start;
    unsigned long end;
};

struct spinlock {
    int lock;
};

struct kvm {
    struct spinlock mn_invalidate_lock;
    int mn_active_invalidate_count;
};

struct kvm_hva_range {
    unsigned long start;
    unsigned long end;
    unsigned long pte;
    int (*handler)(struct kvm *kvm, struct kvm_gfn_range *range);
    void (*on_lock)(struct kvm *kvm);
    void (*on_unlock)(struct kvm *kvm);
    bool flush_on_ret;
    bool may_block;
};

#define __pte(x) (x)

extern struct kvm *mmu_notifier_to_kvm(struct mmu_notifier *mn);
extern void spin_lock(struct spinlock *lock);
extern void spin_unlock(struct spinlock *lock);
extern bool mmu_notifier_range_blockable(const struct mmu_notifier_range *range);
extern void trace_kvm_unmap_hva_range(unsigned long start, unsigned long end);
extern void gfn_to_pfn_cache_invalidate_start(struct kvm *kvm, unsigned long start, unsigned long end, bool may_block);
extern void __kvm_handle_hva_range(struct kvm *kvm, const struct kvm_hva_range *range);
extern int kvm_unmap_gfn_range(struct kvm *kvm, struct kvm_gfn_range *range);
extern void kvm_inc_notifier_count(struct kvm *kvm);
extern void kvm_arch_guest_memory_reclaimed(struct kvm *kvm);