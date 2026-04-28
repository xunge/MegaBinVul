#include <stdint.h>
#include <stdbool.h>

typedef uint64_t u64;
typedef uint32_t u32;
typedef uint64_t phys_addr_t;
typedef uint64_t kvm_pte_t;

enum pkvm_page_state {
    PKVM_NOPAGE
};

struct kvm_protected_vcpu {
    struct kvm_shadow_vm *shadow_vm;
};

struct kvm_vcpu {
    struct {
        struct kvm_protected_vcpu pkvm;
    } arch;
};

struct kvm_shadow_vm {
    struct {
        /* placeholder for pgt */
    } pgt;
};

struct pkvm_mem_transition {
    struct {
        struct {
            struct kvm_vcpu *vcpu;
        } guest;
        u64 addr;
    } initiator;
    int nr_pages;
};

#define KVM_PGTABLE_MAX_LEVELS 4
#define E2BIG 7
#define EFAULT 14
#define EPERM 1
#define EINVAL 22