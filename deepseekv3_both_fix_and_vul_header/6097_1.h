#include <stdint.h>
#include <stdbool.h>

typedef uint64_t u64;

struct vmcb_control;

struct vcpu_svm {
    struct {
        u64 vmcb12_gpa;
    } nested;
    struct vcpu {
        // vcpu fields would be defined here
    } vcpu;
};

struct vmcb {
    struct vmcb_control {
        // control fields would be defined here
    } control;
    struct {
        unsigned long cr3;
    } save;
};

void load_nested_vmcb_control(struct vcpu_svm *svm, struct vmcb_control *control);
void nested_prepare_vmcb_save(struct vcpu_svm *svm, struct vmcb *vmcb12);
void nested_prepare_vmcb_control(struct vcpu_svm *svm);
int nested_svm_load_cr3(struct vcpu *vcpu, unsigned long cr3, bool nested_npt_enabled);
bool nested_npt_enabled(struct vcpu_svm *svm);
void svm_set_gif(struct vcpu_svm *svm, bool enable);