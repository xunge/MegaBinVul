#include <stdint.h>
#include <stddef.h>

#define X86EMUL_CONTINUE 0
#define X86EMUL_UNHANDLEABLE 1
#define VCPU_SREG_CS 0
#define X86_TRANSFER_RET 0
#define X86EMUL_MODE_PROT64 0
#define X86EMUL_MODE_PROT16 0

typedef uint16_t u16;

struct desc_struct {
    unsigned long a;
    unsigned long b;
};

struct x86_emulate_ctxt;

struct x86_emulate_ops {
    int (*cpl)(struct x86_emulate_ctxt *);
    void (*get_segment)(struct x86_emulate_ctxt *, u16 *, struct desc_struct *, void *, int);
    void (*set_segment)(struct x86_emulate_ctxt *, u16, struct desc_struct *, int, int);
};

struct x86_emulate_ctxt {
    int mode;
    int op_bytes;
    struct x86_emulate_ops *ops;
};

static int emulate_pop(struct x86_emulate_ctxt *, unsigned long *, int);
static int __load_segment_descriptor(struct x86_emulate_ctxt *, u16, int, int, int, struct desc_struct *);
static int assign_eip_far(struct x86_emulate_ctxt *, unsigned long, struct desc_struct *);
static void WARN_ON(int condition);