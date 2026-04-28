#include <stdint.h>

typedef uint64_t u64;
typedef uint16_t u16;
typedef uint32_t u32;

#define X86EMUL_MODE_REAL 0
#define X86EMUL_MODE_VM86 1
#define X86EMUL_MODE_PROT64 2
#define X86EMUL_CONTINUE 0
#define MSR_EFER 0
#define MSR_STAR 0
#define MSR_LSTAR 0
#define MSR_CSTAR 0
#define MSR_SYSCALL_MASK 0
#define VCPU_SREG_CS 0
#define VCPU_SREG_SS 0
#define VCPU_REGS_RCX 0
#define VCPU_REGS_R11 0
#define EFLG_RF 0
#define EFLG_VM 0
#define EFLG_IF 0
#define EFER_SCE 0
#define EFER_LMA 0
#define CONFIG_X86_64 1

struct desc_struct {
    unsigned long d;
    unsigned long l;
};

struct x86_emulate_ops {
    void (*get_msr)(struct x86_emulate_ctxt *, uint32_t, u64 *);
    void (*set_segment)(struct x86_emulate_ctxt *, u16, struct desc_struct *, int, int);
};

struct x86_emulate_ctxt {
    struct x86_emulate_ops *ops;
    int mode;
    u64 _eip;
    u64 eflags;
    u64 regs[16];
};

static int emulate_ud(struct x86_emulate_ctxt *ctxt);
static int em_syscall_is_enabled(struct x86_emulate_ctxt *ctxt);
static void setup_syscalls_segments(struct x86_emulate_ctxt *ctxt, struct desc_struct *cs, struct desc_struct *ss);