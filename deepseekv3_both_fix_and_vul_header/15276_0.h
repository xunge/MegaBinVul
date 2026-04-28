#include <stdint.h>

#define EINVAL 22
#define KVM_MAX_MCE_BANKS 32
#define KVM_MCE_CAP_SUPPORTED 0x1
#define MCG_CTL_P 0x1

struct kvm_vcpu {
    struct {
        uint64_t mcg_cap;
        uint64_t mcg_ctl;
        uint64_t mce_banks[KVM_MAX_MCE_BANKS * 4];
    } arch;
};

typedef uint64_t u64;