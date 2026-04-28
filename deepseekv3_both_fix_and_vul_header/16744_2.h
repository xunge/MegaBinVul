#include <stddef.h>
#include <stdint.h>

typedef uint32_t u32;
struct kvm;
struct kvm_vcpu;
struct kvm_vcpu_hv_synic {
    int active;
};

static inline struct kvm_vcpu *get_vcpu_by_vpidx(struct kvm *kvm, u32 vpidx);
static inline struct kvm_vcpu_hv_synic *to_hv_synic(struct kvm_vcpu *vcpu);