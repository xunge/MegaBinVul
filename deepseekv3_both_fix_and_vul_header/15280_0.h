#include <stddef.h>

#define X86EMUL_UNHANDLEABLE 1

struct x86_emulate_ops;

struct x86_emulate_ctxt {
    unsigned long cs_base;
    struct {
        unsigned long eip_orig;
    } decode;
};

static int do_fetch_insn_byte(struct x86_emulate_ctxt *ctxt,
                             struct x86_emulate_ops *ops,
                             unsigned long eip, void *dest);