#include <stdbool.h>
#include <stddef.h>

struct x86_emulate_ctxt {
    struct {
        int vector;
        bool error_code_valid;
    } exception;
};

struct kvm_vcpu {
    struct {
        struct x86_emulate_ctxt emulate_ctxt;
    } arch;
};

struct x86_instruction_info {
    int intercept;
};

struct vmcs12;

enum x86_intercept_stage {
    X86EMUL_CONTINUE,
    X86EMUL_PROPAGATE_FAULT,
    X86EMUL_UNHANDLEABLE
};

#define x86_intercept_rdtscp 0
#define UD_VECTOR 0
#define SECONDARY_EXEC_RDTSCP 0

static inline struct vmcs12 *get_vmcs12(struct kvm_vcpu *vcpu) { return NULL; }
static inline bool nested_cpu_has2(struct vmcs12 *vmcs12, int flag) { return false; }