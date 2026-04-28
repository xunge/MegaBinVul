#include <stdbool.h>

struct mmu_notifier;

struct mmu_notifier_range {
    unsigned long start;
    unsigned long end;
};

struct kvm_hva_range {
    unsigned long start;
    unsigned long end;
    unsigned long pte;
    void *handler;
    void (*on_lock)(void);
    void (*on_unlock)(void);
    bool flush_on_ret;
    bool may_block;
};

struct kvm {
    struct spinlock *mn_invalidate_lock;
    int mn_active_invalidate_count;
    struct rcuwait *mn_memslots_update_rcuwait;
    int mmu_notifier_count;
};

struct spinlock;
struct rcuwait;

extern struct kvm *mmu_notifier_to_kvm(struct mmu_notifier *mn);
extern void __kvm_handle_hva_range(struct kvm *kvm, const struct kvm_hva_range *hva_range);
extern void kvm_null_fn(void);
extern void kvm_dec_notifier_count(void);
extern bool mmu_notifier_range_blockable(const struct mmu_notifier_range *range);
extern void spin_lock(struct spinlock *lock);
extern void spin_unlock(struct spinlock *lock);
extern void rcuwait_wake_up(struct rcuwait *wait);
extern unsigned long __pte(unsigned long);
extern void BUG_ON(bool condition);