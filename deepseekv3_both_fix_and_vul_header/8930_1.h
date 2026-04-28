#include <stdbool.h>

struct kvm_vcpu {
    struct {
        unsigned long hflags;
    } arch;
};

struct vcpu_svm {
    struct kvm_vcpu vcpu;
    bool nmi_singlestep;
    struct {
        struct {
            unsigned long rflags;
        } save;
    } *vmcb;
};

#define HF_NMI_MASK 0
#define HF_IRET_MASK 0
#define X86_EFLAGS_TF 0
#define X86_EFLAGS_RF 0

static inline struct vcpu_svm *to_svm(struct kvm_vcpu *vcpu) {
    return (struct vcpu_svm *)vcpu;
}

static void update_db_bp_intercept(struct kvm_vcpu *vcpu);