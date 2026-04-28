#include <stdint.h>
#include <stdbool.h>

#define INVALID_PADDR (~0UL)
#define X86EMUL_OKAY 0
#define X86EMUL_EXCEPTION 1
#define IO_BITMAP_A 0
#define IO_BITMAP_B 1
#define MSR_BITMAP 2
#define VMCS_HIGH(x) (x)
#define VMX_INSN_SUCCEED 0

typedef uint64_t u64;
typedef bool bool_t;

enum vmx_insn_errno {
    VMX_INSN_OK = VMX_INSN_SUCCEED,
    VMX_INSN_UNSUPPORTED_VMCS_COMPONENT = 1
};

struct cpu_user_regs;

struct vmx_inst_decoded {
    int reg2;
};

struct nestedhvm_vcpu {
    unsigned long nv_vvmcxaddr;
};

struct vcpu {
    struct nestedhvm_vcpu nestedhvm;
};

extern struct vcpu *current;
extern int decode_vmx_inst(struct cpu_user_regs *regs, struct vmx_inst_decoded *decode, unsigned long *operand, int flag);
extern void vmfail_invalid(struct cpu_user_regs *regs);
extern u64 reg_read(struct cpu_user_regs *regs, int reg);
extern enum vmx_insn_errno set_vvmcs_safe(struct vcpu *v, u64 vmcs_encoding, unsigned long operand);
extern void vmfail(struct cpu_user_regs *regs, enum vmx_insn_errno err);
extern bool_t _map_io_bitmap(struct vcpu *v, int bitmap);
extern bool_t _map_msr_bitmap(struct vcpu *v);
extern void vmsucceed(struct cpu_user_regs *regs);
extern void vmfail_valid(struct cpu_user_regs *regs, enum vmx_insn_errno err);

static inline struct nestedhvm_vcpu vcpu_nestedhvm(struct vcpu *v) {
    return v->nestedhvm;
}