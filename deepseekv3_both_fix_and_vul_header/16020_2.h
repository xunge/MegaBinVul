#include <stdbool.h>

struct list_head {
    struct list_head *next, *prev;
};

struct kvm_mmu_page_role {
    unsigned invalid:1;
};

struct kvm_mmu_page {
    struct list_head link;
    struct kvm_mmu_page_role role;
    unsigned unsync:1;
    unsigned root_count;
    unsigned lpage_disallowed:1;
};

struct kvm_stat {
    unsigned mmu_shadow_zapped;
};

struct kvm {
    struct kvm_stat stat;
    void *mmu_lock;
};

#define KVM_REQ_MMU_FREE_OBSOLETE_ROOTS 0

static inline void lockdep_assert_held_write(void *lock) {}
static inline void trace_kvm_mmu_prepare_zap_page(struct kvm_mmu_page *sp) {}
static inline int mmu_zap_unsync_children(struct kvm *kvm, struct kvm_mmu_page *sp, struct list_head *list) { return 0; }
static inline int kvm_mmu_page_unlink_children(struct kvm *kvm, struct kvm_mmu_page *sp, struct list_head *list) { return 0; }
static inline void kvm_mmu_unlink_parents(struct kvm_mmu_page *sp) {}
static inline bool sp_has_gptes(struct kvm_mmu_page *sp) { return false; }
static inline void unaccount_shadowed(struct kvm *kvm, struct kvm_mmu_page *sp) {}
static inline void kvm_unlink_unsync_page(struct kvm *kvm, struct kvm_mmu_page *sp) {}
static inline void list_add(struct list_head *new, struct list_head *head) {}
static inline void list_move(struct list_head *list, struct list_head *head) {}
static inline void list_del(struct list_head *entry) {}
static inline void kvm_unaccount_mmu_page(struct kvm *kvm, struct kvm_mmu_page *sp) {}
static inline bool is_obsolete_sp(struct kvm *kvm, struct kvm_mmu_page *sp) { return false; }
static inline void unaccount_huge_nx_page(struct kvm *kvm, struct kvm_mmu_page *sp) {}
static inline void kvm_make_all_cpus_request(struct kvm *kvm, int req) {}