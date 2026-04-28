#include <stdint.h>
#include <string.h>

enum x86_segment {
    x86_seg_cs,
    x86_seg_ss,
    x86_seg_ldtr,
    x86_seg_tr,
    x86_seg_gdtr,
    x86_seg_none
};

#define EXC_GP 13
#define EXC_NP 11
#define X86EMUL_UNHANDLEABLE 1
#define X86EMUL_EXCEPTION 2

typedef int bool_t;

struct x86_emulate_ctxt {
};

struct x86_emulate_ops {
    int (*write_segment)(enum x86_segment seg, const void *data, struct x86_emulate_ctxt *ctxt);
    int (*read_segment)(enum x86_segment seg, void *data, struct x86_emulate_ctxt *ctxt);
    int (*read)(enum x86_segment seg, uint32_t addr, void *data, size_t size, struct x86_emulate_ctxt *ctxt);
    int (*cmpxchg)(enum x86_segment seg, uint32_t addr, const void *old, const void *new, size_t size, struct x86_emulate_ctxt *ctxt);
    int (*inject_hw_exception)(int fault_type, uint16_t selector, struct x86_emulate_ctxt *ctxt);
};

struct segment_register {
    uint32_t base;
    uint32_t limit;
    uint16_t sel;
    union {
        uint16_t bytes;
        struct {
            uint16_t dpl:2;
            uint16_t g:1;
        } fields;
    } attr;
};

static int is_x86_user_segment(enum x86_segment seg) { return 0; }
static int in_longmode(struct x86_emulate_ctxt *ctxt, const struct x86_emulate_ops *ops) { return 0; }