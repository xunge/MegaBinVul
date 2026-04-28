#include <stdint.h>

#define X86EMUL_UNHANDLEABLE 0
#define X86EMUL_OKAY 1
#define TRAP_invalid_op 6
#define X86_EVENT_NO_EC 0

struct x86_emulate_ctxt {
    void *regs;
};

struct {
    int (*altp2m_vcpu_emulate_vmfunc)(void *);
} hvm_funcs;

void x86_emul_hw_exception(int trap, int event, struct x86_emulate_ctxt *ctxt);