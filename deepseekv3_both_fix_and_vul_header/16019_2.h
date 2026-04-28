#include <stdbool.h>
#include <stdint.h>
#include <pthread.h>

#define RET_PF_EMULATE 1
#define RET_PF_INVALID 2
#define RET_PF_CONTINUE 3
#define RET_PF_RETRY 4
#define ACC_ALL 0
#define PAGE_SHIFT 12

typedef uint64_t gpa_t;
typedef uint64_t gfn_t;
typedef uint64_t pfn_t;

struct kvm_memory_slot {
    // Minimal stub for compilation
    int dummy;
};

struct kvm_mmu {
    // Minimal stub for compilation
    int dummy;
};

struct kvm_page_fault {
    gpa_t addr;
    gfn_t gfn;
    struct kvm_memory_slot *slot;
    pfn_t pfn;
};

struct kvm_vcpu {
    struct kvm *kvm;
    struct {
        struct kvm_mmu *mmu;
    } arch;
};

struct kvm {
    pthread_rwlock_t mmu_lock;
    unsigned long mmu_invalidate_seq;
};

static inline bool is_tdp_mmu(struct kvm_mmu *mmu) { return false; }
static inline struct kvm_memory_slot *kvm_vcpu_gfn_to_memslot(struct kvm_vcpu *vcpu, gfn_t gfn) { return NULL; }
static inline bool page_fault_handle_page_track(struct kvm_vcpu *vcpu, struct kvm_page_fault *fault) { return false; }
static inline int fast_page_fault(struct kvm_vcpu *vcpu, struct kvm_page_fault *fault) { return 0; }
static inline int mmu_topup_memory_caches(struct kvm_vcpu *vcpu, bool b) { return 0; }
static inline void smp_rmb(void) {}
static inline int kvm_faultin_pfn(struct kvm_vcpu *vcpu, struct kvm_page_fault *fault) { return 0; }
static inline int handle_abnormal_pfn(struct kvm_vcpu *vcpu, struct kvm_page_fault *fault, int acc) { return 0; }
static inline bool is_page_fault_stale(struct kvm_vcpu *vcpu, struct kvm_page_fault *fault, unsigned long seq) { return false; }
static inline int make_mmu_pages_available(struct kvm_vcpu *vcpu) { return 0; }
static inline int kvm_tdp_mmu_map(struct kvm_vcpu *vcpu, struct kvm_page_fault *fault) { return 0; }
static inline int __direct_map(struct kvm_vcpu *vcpu, struct kvm_page_fault *fault) { return 0; }
static inline void kvm_release_pfn_clean(pfn_t pfn) {}