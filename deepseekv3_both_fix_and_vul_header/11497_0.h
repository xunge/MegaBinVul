#include <stdbool.h>

struct x86_emulate_ctxt;
struct kvm_vcpu;
struct x86_exception;
typedef unsigned long gva_t;
typedef unsigned int u32;

#define PFERR_USER_MASK 0

struct kvm_x86_ops {
    int (*get_cpl)(struct kvm_vcpu *);
};

extern struct kvm_x86_ops *kvm_x86_ops;

static inline struct kvm_vcpu *emul_to_vcpu(struct x86_emulate_ctxt *ctxt) {
    return (struct kvm_vcpu *)0;
}

static inline int kvm_read_guest_virt_helper(gva_t addr, void *val, unsigned int bytes, 
                                           struct kvm_vcpu *vcpu, u32 access, 
                                           struct x86_exception *exception) {
    return 0;
}