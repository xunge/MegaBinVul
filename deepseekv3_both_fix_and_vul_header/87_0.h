#include <stddef.h>

#define EMULATION_OK 0
#define EMULTYPE_SKIP 0

struct kvm_vcpu {
    struct {
        struct x86_emulate_ctxt *emulate_ctxt;
    } arch;
    struct {
        int insn_emulation;
    } stat;
};

struct x86_emulate_ctxt;

void init_emulate_ctxt(struct kvm_vcpu *vcpu);
int kvm_vcpu_check_breakpoint(struct kvm_vcpu *vcpu, int *r);
int x86_decode_insn(struct x86_emulate_ctxt *ctxt, void *insn, int insn_len, int emulation_type);
void trace_kvm_emulate_insn_start(struct kvm_vcpu *vcpu);