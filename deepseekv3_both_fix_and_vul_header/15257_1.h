#include <stdint.h>

struct kvm_vcpu;
struct kvm_x86_ops;

struct kvm_lapic {
    uint64_t vapic_addr;
};

struct kvm_vcpu {
    struct {
        struct kvm_lapic *apic;
    } arch;
};

struct kvm_x86_ops {
    void (*update_cr8_intercept)(struct kvm_vcpu *, int, int);
};

extern struct kvm_x86_ops *kvm_x86_ops;

int kvm_lapic_find_highest_irr(struct kvm_vcpu *vcpu);
int kvm_lapic_get_cr8(struct kvm_vcpu *vcpu);