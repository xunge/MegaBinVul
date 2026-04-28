#include <stdint.h>
#include <string.h>

enum x86_segment {
    x86_seg_cs,
    x86_seg_ss,
    x86_seg_tr,
    x86_seg_ldtr,
    x86_seg_gdtr,
    x86_seg_none
};

struct segment_register {
    uint16_t sel;
    uint32_t base;
    uint32_t limit;
    union {
        uint16_t bytes;
        struct {
            uint16_t type:4;
            uint16_t s:1;
            uint16_t dpl:2;
            uint16_t p:1;
            uint16_t avl:1;
            uint16_t l:1;
            uint16_t db:1;
            uint16_t g:1;
        } fields;
    } attr;
};

struct x86_emulate_ctxt {
    /* Context structure placeholder */
};

struct x86_emulate_ops {
    int (*read_segment)(enum x86_segment seg, struct segment_register *sreg,
                        struct x86_emulate_ctxt *ctxt);
    int (*read)(enum x86_segment seg, uint64_t addr, void *data,
                unsigned int size, struct x86_emulate_ctxt *ctxt);
    int (*cmpxchg)(enum x86_segment seg, uint64_t addr, const void *old_data,
                   const void *new_data, unsigned int size,
                   struct x86_emulate_ctxt *ctxt);
    int (*inject_hw_exception)(int vector, uint16_t error_code,
                               struct x86_emulate_ctxt *ctxt);
};

typedef int bool_t;

#define X86EMUL_OKAY 0
#define X86EMUL_UNHANDLEABLE 1
#define X86EMUL_EXCEPTION 2

#define EXC_GP 13
#define EXC_NP 11
#define EXC_SS 12

static int get_cpl(struct x86_emulate_ctxt *ctxt, const struct x86_emulate_ops *ops);
static bool_t mode_64bit(void);
static bool_t is_x86_user_segment(enum x86_segment seg);
static bool_t in_longmode(struct x86_emulate_ctxt *ctxt, const struct x86_emulate_ops *ops);