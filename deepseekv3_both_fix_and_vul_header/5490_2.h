#include <stdint.h>

typedef uint32_t u32;
typedef uint16_t u16;
typedef uint64_t u64;

#define MSR_EFER 0xC0000080
#define MSR_IA32_SYSENTER_CS 0x174
#define MSR_IA32_SYSENTER_EIP 0x176
#define MSR_IA32_SYSENTER_ESP 0x175

#define X86EMUL_MODE_REAL 0
#define X86EMUL_MODE_PROT32 1
#define X86EMUL_MODE_PROT64 2
#define X86EMUL_UNHANDLEABLE 1
#define X86EMUL_CONTINUE 0

#define EFLG_VM (1 << 17)
#define EFLG_IF (1 << 9)
#define EFER_LMA (1 << 10)
#define SELECTOR_RPL_MASK 0x3

#define VCPU_SREG_CS 0
#define VCPU_SREG_SS 1
#define VCPU_REGS_RSP 2

struct desc_struct {
    unsigned long a;
    unsigned long b;
    unsigned char d;
    unsigned char l;
};

struct x86_emulate_ctxt;

struct x86_emulate_ops {
    int (*get_msr)(struct x86_emulate_ctxt *ctxt, u32 msr_index, u64 *pdata);
    void (*set_segment)(struct x86_emulate_ctxt *ctxt, u16 selector,
                       struct desc_struct *desc, unsigned base, int seg);
};

struct x86_emulate_ctxt {
    const struct x86_emulate_ops *ops;
    int mode;
    unsigned long eflags;
    unsigned long _eip;
};

static int emulate_gp(struct x86_emulate_ctxt *ctxt, int val);
static int emulate_ud(struct x86_emulate_ctxt *ctxt);
static int vendor_intel(struct x86_emulate_ctxt *ctxt);
static void setup_syscalls_segments(struct x86_emulate_ctxt *ctxt, 
                                  struct desc_struct *cs, 
                                  struct desc_struct *ss);
static u64 *reg_write(struct x86_emulate_ctxt *ctxt, int reg);