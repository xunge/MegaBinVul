#include <stdbool.h>

struct kvm_vcpu;
struct kvm_cpuid_entry2 {
    int ecx;
};

struct kvm_cpuid_entry2 *kvm_find_cpuid_entry(struct kvm_vcpu *vcpu, int id, int index);
#define X86_FEATURE_XSAVE 0
#define bit(n) (1 << (n))