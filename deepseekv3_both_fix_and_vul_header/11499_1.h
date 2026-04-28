#include <stdbool.h>

typedef unsigned long ulong;

struct x86_emulate_ctxt {
    struct {
        int (*read_std)(struct x86_emulate_ctxt *, ulong, void *, unsigned, int *, ...);
    } *ops;
    int exception;
};