#include <stdbool.h>

struct mmu_notifier;
struct kvm;

typedef unsigned long pte_t;
typedef int (*hva_handler_t)(struct kvm *kvm, unsigned long start,
                            unsigned long end, pte_t pte, void *data);

struct kvm_hva_range {
    unsigned long start;
    unsigned long end;
    pte_t pte;
    hva_handler_t handler;
    void *on_lock;
    void *on_unlock;
    bool flush_on_ret;
    bool may_block;
};

#define __always_inline inline
#define __pte(x) ((pte_t)(x))

static inline struct kvm *mmu_notifier_to_kvm(struct mmu_notifier *mn) { return 0; }
static inline int __kvm_handle_hva_range(struct kvm *kvm, const struct kvm_hva_range *range) { return 0; }
static inline void kvm_null_fn(void) {}