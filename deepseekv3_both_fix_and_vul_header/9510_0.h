#include <stddef.h>

#define EMULATE_DONE 0
#define EMULATE_FAIL 1
#define KVM_EXIT_INTERNAL_ERROR 2
#define KVM_INTERNAL_ERROR_EMULATION 3
#define UD_VECTOR 4

struct kvm_vcpu {
    struct {
        unsigned long insn_emulation_fail;
    } stat;
    struct {
        int exit_reason;
        struct {
            int suberror;
            int ndata;
        } internal;
    } *run;
};

struct kvm_x86_ops {
    int (*get_cpl)(struct kvm_vcpu *);
};

extern struct kvm_x86_ops *kvm_x86_ops;

static inline int is_guest_mode(struct kvm_vcpu *vcpu) { return 0; }
void trace_kvm_emulate_insn_failed(struct kvm_vcpu *vcpu);
void kvm_queue_exception(struct kvm_vcpu *vcpu, int vector);