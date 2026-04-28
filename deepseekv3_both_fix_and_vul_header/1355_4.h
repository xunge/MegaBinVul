#include <stdbool.h>
#include <stddef.h>

#define __always_inline inline

struct mmu_notifier;
struct kvm;
typedef unsigned long pte_t;
typedef int (*hva_handler_t)(struct kvm *kvm, unsigned long start,
                             unsigned long end, pte_t pte);

struct kvm_hva_range {
    unsigned long start;
    unsigned long end;
    pte_t pte;
    hva_handler_t handler;
    void (*on_lock)(void);
    void (*on_unlock)(void);
    bool flush_on_ret;
    bool may_block;
};

static inline void *kvm_null_fn(void) { return NULL; }
static inline struct kvm *mmu_notifier_to_kvm(struct mmu_notifier *mn) { return NULL; }
extern int __kvm_handle_hva_range(struct kvm *kvm, const struct kvm_hva_range *range);