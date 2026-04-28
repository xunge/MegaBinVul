#include <stdint.h>
#include <stdbool.h>

#define EINVAL 22
#define EPERM 1

typedef uint64_t u64;
typedef uint32_t u32;

typedef uint64_t kvm_pte_t;

enum kvm_pgtable_walk_flags {
    KVM_PGTABLE_WALK_FLAG_NONE = 0
};

struct check_walk_data {
    int (*get_page_state)(kvm_pte_t pte, u64 addr);
    int desired;
};

static inline bool kvm_pte_valid(kvm_pte_t pte) {
    return false;
}

static inline u64 kvm_pte_to_phys(kvm_pte_t pte) {
    return 0;
}

static inline bool addr_is_allowed_memory(u64 phys) {
    return false;
}