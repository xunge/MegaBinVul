#include <stdbool.h>

typedef unsigned long ulong;

struct x86_emulate_ctxt;
struct x86_exception;

struct x86_emulate_ops {
    int (*write_std)(struct x86_emulate_ctxt *, ulong, void *, unsigned int, struct x86_exception *, ...);
};

struct x86_exception {
};

struct x86_emulate_ctxt {
    struct x86_emulate_ops *ops;
    struct x86_exception exception;
};