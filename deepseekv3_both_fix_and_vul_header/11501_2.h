#include <stdbool.h>

#define X86EMUL_CONTINUE 0

typedef unsigned long ulong;

struct x86_emulate_ctxt;

struct segmented_address {
    unsigned short segment;
    unsigned long offset;
};

struct x86_emulate_ops {
    int (*read_std)(struct x86_emulate_ctxt *ctxt, ulong linear, void *data,
                    unsigned size, void *exception, ...);
};

struct x86_emulate_ctxt {
    struct x86_emulate_ops *ops;
    void *exception;
};

int linearize(struct x86_emulate_ctxt *ctxt, struct segmented_address addr,
              unsigned size, bool write, ulong *linear);