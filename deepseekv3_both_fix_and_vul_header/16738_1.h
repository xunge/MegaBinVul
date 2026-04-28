#include <stdbool.h>
#include <stddef.h>

#define X86_CR4_SMEP (1UL << 20)
#define X86_CR4_SMAP (1UL << 21)
#define PAGE_SHIFT 12

struct kvm_vcpu {
    struct kvm *kvm;
};

struct kvm;

unsigned long kvm_read_cr4(struct kvm_vcpu *vcpu);
int svm_get_cpl(struct kvm_vcpu *vcpu);
bool kvm_vcpu_gfn_to_memslot(struct kvm_vcpu *vcpu, unsigned long gfn);
unsigned long kvm_rip_read(struct kvm_vcpu *vcpu);
bool sev_guest(struct kvm *kvm);
void kvm_make_request(int req, struct kvm_vcpu *vcpu);
#define KVM_REQ_TRIPLE_FAULT 0
void pr_err_ratelimited(const char *fmt, ...);