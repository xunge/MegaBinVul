#include <stdbool.h>

enum x86_intercept_stage {
    X86_INTERCEPT_STAGE_NONE,
    X86_INTERCEPT_STAGE_DECODE,
    X86_INTERCEPT_STAGE_EXECUTE
};

enum x86_intercept {
    x86_intercept_rdtscp,
    x86_intercept_in,
    x86_intercept_ins,
    x86_intercept_out,
    x86_intercept_outs
};

#define UD_VECTOR 6
#define SECONDARY_EXEC_RDTSCP (1 << 0)

#define X86EMUL_PROPAGATE_FAULT 1
#define X86EMUL_UNHANDLEABLE 2

struct x86_instruction_info {
    enum x86_intercept intercept;
};

struct x86_emulate_ctxt {
    struct {
        int vector;
        bool error_code_valid;
    } exception;
};

struct vmcs12;
struct kvm_vcpu {
    struct {
        struct x86_emulate_ctxt emulate_ctxt;
    } arch;
};

struct vmcs12 *get_vmcs12(struct kvm_vcpu *vcpu);
bool nested_cpu_has2(struct vmcs12 *vmcs12, unsigned long bit);
int vmx_check_intercept_io(struct kvm_vcpu *vcpu, struct x86_instruction_info *info);