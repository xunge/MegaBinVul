#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef unsigned long ulong;

enum x86_transfer_type {
    X86_TRANSFER_TASK_SWITCH,
    X86_TRANSFER_CALL_JMP
};

enum {
    GP_VECTOR = 13,
    TS_VECTOR = 10,
    SS_VECTOR = 12,
    NP_VECTOR = 11
};

enum {
    VCPU_SREG_ES,
    VCPU_SREG_CS,
    VCPU_SREG_SS,
    VCPU_SREG_DS,
    VCPU_SREG_FS,
    VCPU_SREG_GS,
    VCPU_SREG_TR,
    VCPU_SREG_LDTR
};

enum x86emul_mode {
    X86EMUL_MODE_REAL,
    X86EMUL_MODE_VM86,
    X86EMUL_MODE_PROT64
};

struct desc_struct {
    u32 limit0 : 16;
    u32 base0 : 16;
    u32 base1 : 8;
    u32 type : 4;
    u32 s : 1;
    u32 dpl : 2;
    u32 p : 1;
    u32 limit1 : 4;
    u32 avl : 1;
    u32 l : 1;
    u32 d : 1;
    u32 g : 1;
    u32 base2 : 8;
};

struct x86_emulate_ops {
    int (*get_segment)(struct x86_emulate_ctxt *, u16 *, struct desc_struct *, u32 *, int);
    int (*set_segment)(struct x86_emulate_ctxt *, u16, struct desc_struct *, u32, int);
    int (*get_msr)(struct x86_emulate_ctxt *, u32, u64 *);
    int (*cmpxchg_emulated)(struct x86_emulate_ctxt *, ulong, void *, void *, size_t, void *);
    int (*read_std)(struct x86_emulate_ctxt *, ulong, void *, size_t, void *);
};

struct x86_emulate_ctxt {
    enum x86emul_mode mode;
    struct x86_emulate_ops *ops;
    void *exception;
};

#define MSR_EFER 0xC0000080
#define EFER_LMA (1<<8)

#define X86EMUL_CONTINUE 0
#define X86EMUL_UNHANDLEABLE 1

static inline void set_desc_base(struct desc_struct *desc, u32 base) {
    desc->base0 = base & 0xFFFF;
    desc->base1 = (base >> 16) & 0xFF;
    desc->base2 = (base >> 24) & 0xFF;
}

static inline void set_desc_limit(struct desc_struct *desc, u32 limit) {
    desc->limit0 = limit & 0xFFFF;
    desc->limit1 = (limit >> 16) & 0xF;
}

static inline u32 get_desc_base(struct desc_struct *desc) {
    return desc->base0 | (desc->base1 << 16) | (desc->base2 << 24);
}

static inline bool is_noncanonical_address(u64 addr) {
    return (addr >= (1ULL << 47)) != (addr < (1ULL << 48));
}

static int emulate_gp(struct x86_emulate_ctxt *ctxt, int err_code) {
    return X86EMUL_CONTINUE;
}

static int emulate_exception(struct x86_emulate_ctxt *ctxt, unsigned vec, u32 err_code, bool reinject) {
    return X86EMUL_CONTINUE;
}

static int read_segment_descriptor(struct x86_emulate_ctxt *ctxt, u16 selector, struct desc_struct *desc, ulong *desc_addr) {
    return X86EMUL_CONTINUE;
}

static int write_segment_descriptor(struct x86_emulate_ctxt *ctxt, u16 selector, struct desc_struct *desc) {
    return X86EMUL_CONTINUE;
}