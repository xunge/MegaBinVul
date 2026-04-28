#include <stdbool.h>

#define KVM_GUESTDBG_SINGLESTEP 0
#define KVM_GUESTDBG_USE_HW_BP 0
#define KVM_EXIT_DEBUG 0
#define DB_VECTOR 0
#define X86_EFLAGS_TF 0
#define X86_EFLAGS_RF 0

struct kvm_run {
    int exit_reason;
    struct {
        struct {
            unsigned long pc;
            int exception;
        } arch;
    } debug;
};

struct vmcb_save {
    struct {
        unsigned long base;
    } cs;
    unsigned long rip;
    unsigned long rflags;
};

struct vmcb {
    struct vmcb_save save;
};

struct vcpu {
    struct kvm_run *run;
    unsigned long guest_debug;
};

struct vcpu_svm {
    struct vcpu vcpu;
    struct vmcb *vmcb;
    bool nmi_singlestep;
};

void kvm_queue_exception(struct vcpu *vcpu, int vector);
void update_db_bp_intercept(struct vcpu *vcpu);