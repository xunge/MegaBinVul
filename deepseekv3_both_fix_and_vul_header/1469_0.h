#include <stdbool.h>

struct kvm_vcpu {
    struct {
        bool at_instruction_boundary;
    } arch;
};

struct vmcb {
    struct {
        int exit_code;
    } control;
};

struct svm {
    struct vmcb *vmcb;
};

static inline struct svm *to_svm(struct kvm_vcpu *vcpu)
{
    return (struct svm *)vcpu;
}

#define SVM_EXIT_INTR 0