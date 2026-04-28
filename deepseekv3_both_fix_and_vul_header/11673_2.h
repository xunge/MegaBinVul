#include <stdint.h>
#include <stddef.h>

struct cpu_user_regs;

struct vmx_nestedhvm {
    unsigned long nv_vvmcxaddr;
};

struct vcpu {
    struct vmx_nestedhvm nestedhvm;
};

struct vmx_inst_decoded {
    int type;
    int reg1;
    int reg2;
    void *mem;
    int len;
};

struct pagefault_info {
    unsigned long ec;
    unsigned long linear;
};

typedef struct pagefault_info pagefault_info_t;
typedef uint64_t u64;

#define INVALID_PADDR (~0UL)
#define X86EMUL_OKAY 0
#define X86EMUL_EXCEPTION 1
#define VMX_INSN_SUCCEED 0
#define HVMTRANS_bad_linear_to_gfn 1
#define HVMTRANS_okay 0
#define VMX_INST_MEMREG_TYPE_MEMORY 1
#define VMX_INST_MEMREG_TYPE_REG 2

extern struct vcpu *current;

static inline struct vmx_nestedhvm vcpu_nestedhvm(struct vcpu *v) {
    return v->nestedhvm;
}

int decode_vmx_inst(struct cpu_user_regs *regs, struct vmx_inst_decoded *decode, void *null, int zero);
void vmfail_invalid(struct cpu_user_regs *regs);
void vmfail(struct cpu_user_regs *regs, int rc);
int get_vvmcs_safe(struct vcpu *v, u64 addr, u64 *value);
int hvm_copy_to_guest_linear(void *mem, u64 *value, int len, int zero, pagefault_info_t *pfinfo);
void hvm_inject_page_fault(unsigned long ec, unsigned long linear);
void reg_write(struct cpu_user_regs *regs, int reg, u64 value);
unsigned long reg_read(struct cpu_user_regs *regs, int reg);
void vmsucceed(struct cpu_user_regs *regs);