#include <stdint.h>

struct kvm_vcpu;
struct vcpu_vmx {
    struct {
        int vmxon;
    } nested;
};
struct vcpu_vmx *to_vmx(struct kvm_vcpu *vcpu);
void kvm_queue_exception(struct kvm_vcpu *vcpu, unsigned int nr);

#define UD_VECTOR 6