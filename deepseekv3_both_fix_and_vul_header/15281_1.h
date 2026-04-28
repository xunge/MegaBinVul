#include <stddef.h>
#include <string.h>
#include <stdint.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;

enum {
    X86EMUL_MODE_REAL,
    X86EMUL_MODE_PROT16,
    X86EMUL_MODE_PROT32,
    X86EMUL_MODE_PROT64
};

enum {
    VCPU_SREG_CS,
    VCPU_SREG_DS,
    VCPU_REGS_RAX,
    VCPU_REGS_RCX
};

enum {
    REPNE_PREFIX,
    REPE_PREFIX
};

enum {
    No64,
    Group,
    GroupMask,
    GroupDual,
    Stack,
    ModRM,
    MemAbs,
    ByteOp,
    SrcMask,
    SrcNone,
    SrcReg,
    SrcMem16,
    SrcMem32,
    SrcMem,
    SrcImm,
    SrcImmU,
    SrcImmByte,
    SrcImmUByte,
    SrcOne,
    Src2Mask,
    Src2None,
    Src2CL,
    Src2ImmByte,
    Src2Imm16,
    Src2One,
    DstMask,
    ImplicitOps,
    DstReg,
    DstMem,
    DstAcc,
    OP_REG,
    OP_MEM,
    OP_IMM,
    X86EMUL_UNHANDLEABLE
};

struct operand {
    int type;
    unsigned long val;
    unsigned long orig_val;
    unsigned long *ptr;
    int bytes;
};

struct decode_cache {
    unsigned long eip;
    unsigned long eip_orig;
    unsigned long modrm_ea;
    unsigned long regs[16];
    unsigned long cs_base;
    unsigned char b;
    unsigned char d;
    unsigned char modrm;
    unsigned char modrm_mod;
    unsigned char modrm_reg;
    unsigned char modrm_val;
    unsigned long *modrm_ptr;
    unsigned char rex_prefix;
    unsigned char lock_prefix;
    unsigned char rep_prefix;
    unsigned char twobyte;
    unsigned char has_seg_override;
    struct operand src;
    struct operand src2;
    struct operand dst;
    int op_bytes;
    int ad_bytes;
    int rip_relative;
};

struct vcpu {
    struct {
        unsigned long regs[16];
    } arch;
};

struct x86_emulate_ctxt {
    struct decode_cache decode;
    struct vcpu *vcpu;
    int mode;
    unsigned long cs_base;
};

#define DPRINTF(fmt, ...) do {} while (0)

extern unsigned long kvm_rip_read(struct vcpu *vcpu);
extern unsigned long seg_base(struct x86_emulate_ctxt *ctxt, int seg);
extern void set_seg_override(struct decode_cache *c, int seg);
extern unsigned long seg_override_base(struct x86_emulate_ctxt *ctxt, struct decode_cache *c);
extern void decode_register_operand(struct operand *op, struct decode_cache *c, int twobyte);
extern int decode_modrm(struct x86_emulate_ctxt *ctxt, struct x86_emulate_ops *ops);
extern int decode_abs(struct x86_emulate_ctxt *ctxt, struct x86_emulate_ops *ops);
extern void kvm_report_emulation_failure(struct vcpu *vcpu, const char *message);

extern unsigned char opcode_table[256];
extern unsigned char twobyte_table[256];
extern unsigned char group_table[256];
extern unsigned char group2_table[256];

#define insn_fetch(type, size, addr) (*(type *)(addr))