#include <stddef.h>

enum x86_emulate_fpu_type {
    X86EMUL_FPU_fpu,
    X86EMUL_FPU_wait,
    X86EMUL_FPU_mmx,
    X86EMUL_FPU_xmm,
    X86EMUL_FPU_ymm
};

#define X86EMUL_OKAY 0
#define X86EMUL_UNHANDLEABLE 1

#define X86_CR0_PE (1 << 0)
#define X86_CR0_EM (1 << 2)
#define X86_CR4_OSFXSR (1 << 9)
#define X86_CR4_OSXSAVE (1 << 18)
#define X86_EFLAGS_VM (1 << 17)

#define XSTATE_SSE (1 << 1)
#define XSTATE_YMM (1 << 2)

struct cpu_user_regs {
    unsigned long eflags;
};

struct x86_emulate_ctxt {
    struct cpu_user_regs *regs;
};

struct hvm_vcpu {
    unsigned long guest_cr[5];
    void (*fpu_exception_callback)(void *, struct cpu_user_regs *);
    void *fpu_exception_callback_arg;
    unsigned long xcr0;
};

struct arch_vcpu {
    struct hvm_vcpu hvm_vcpu;
    unsigned long xcr0;
};

struct vcpu {
    struct arch_vcpu arch;
    int fpu_dirtied;
};

struct hvm_funcs {
    void (*fpu_dirty_intercept)(void);
};

extern struct vcpu *current;
extern struct hvm_funcs hvm_funcs;
extern int cpu_has_mmx;