#include <stddef.h>

struct fpu {
    unsigned int last_cpu;
};

extern struct fpu *fpu_fpregs_owner_ctx;

#define this_cpu_read_stable(var) (var)