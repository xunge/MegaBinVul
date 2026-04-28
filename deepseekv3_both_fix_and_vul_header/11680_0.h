#include <stddef.h>
#include <stdint.h>

#define X86EMUL_OKAY 0
#define INVEPT_SINGLE_CONTEXT 1
#define INVEPT_ALL_CONTEXT 2

struct cpu_user_regs {
    unsigned long reg2;
};

struct vmx_inst_decoded {
    unsigned long reg2;
};

struct domain;
struct vcpu {
    struct domain *domain;
};

extern struct vcpu *current;

int decode_vmx_inst(struct cpu_user_regs *regs, struct vmx_inst_decoded *decode, unsigned long *eptp, int flags);
void np2m_flush_base(struct vcpu *v, unsigned long eptp);
void p2m_flush_nestedp2m(struct domain *d);
void __invept(int type, unsigned long eptp);
void vmfail_invalid(struct cpu_user_regs *regs);
void vmsucceed(struct cpu_user_regs *regs);
unsigned long reg_read(struct cpu_user_regs *regs, unsigned long reg);