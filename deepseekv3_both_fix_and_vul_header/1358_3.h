#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#define KVM_ADDRESS_SPACE_NUM 2
#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)

#define WARN_ON_ONCE(condition) (condition)
#define IS_KVM_NULL_FN(fn) (!(fn))
#define KVM_MMU_LOCK(kvm) do {} while (0)
#define KVM_MMU_UNLOCK(kvm) do {} while (0)

struct interval_tree_node {
    unsigned long start;
    unsigned long last;
};

struct kvm_gfn_range {
    void *pte;
    bool may_block;
    unsigned long start;
    unsigned long end;
    struct kvm_memory_slot *slot;
};

struct kvm_memory_slot {
    unsigned long userspace_addr;
    unsigned long npages;
    struct interval_tree_node hva_node[2];
};

struct kvm_memslots {
    int node_idx;
};

struct kvm_hva_range {
    unsigned long start;
    unsigned long end;
    void *pte;
    bool may_block;
    bool flush_on_ret;
    void (*on_lock)(struct kvm *kvm, unsigned long start, unsigned long end);
    void (*on_unlock)(struct kvm *kvm);
    bool (*handler)(struct kvm *kvm, struct kvm_gfn_range *range);
};

struct kvm {
    int srcu;
};

static inline unsigned long max(unsigned long a, unsigned long b) { return a > b ? a : b; }
static inline unsigned long min(unsigned long a, unsigned long b) { return a < b ? a : b; }
static inline unsigned long hva_to_gfn_memslot(unsigned long hva, struct kvm_memory_slot *slot) { return 0; }
static inline void kvm_flush_remote_tlbs(struct kvm *kvm) {}
static inline struct kvm_memslots *__kvm_memslots(struct kvm *kvm, int i) { return NULL; }
static inline int srcu_read_lock(int *srcu) { return 0; }
static inline void srcu_read_unlock(int *srcu, int idx) {}

#define kvm_for_each_memslot_in_hva_range(node, slots, start, end) \
    for (node = NULL; node != NULL; node = NULL)
#define container_of(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))