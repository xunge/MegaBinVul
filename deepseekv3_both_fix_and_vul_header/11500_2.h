#include <stdbool.h>

#define X86EMUL_CONTINUE 0

typedef unsigned long ulong;

struct x86_emulate_ctxt;

struct segmented_address {
    unsigned short segment;
    unsigned long offset;
};

struct x86_emulate_ops {
    int (*write_std)(struct x86_emulate_ctxt *, ulong, void *, unsigned int, void *, ...);
};

struct x86_emulate_ctxt {
    struct x86_emulate_ops *ops;
    void *exception;
};

int linearize(struct x86_emulate_ctxt *ctxt, struct segmented_address addr,
              unsigned int size, bool write, ulong *linear);