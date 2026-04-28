#include <stddef.h>
#include <stdlib.h>

#define XSTATE_COMPACTION_ENABLED 0
#define FCW_DEFAULT 0
#define MXCSR_DEFAULT 0
#define ENOMEM 12

struct xsave_area {
    struct {
        unsigned long xcomp_bv;
    } xsave_hdr;
    struct {
        unsigned short fcw;
        unsigned int mxcsr;
    } fpu_sse;
};

struct arch_vcpu {
    struct xsave_area *xsave_area;
    void *fpu_ctxt;
};

struct vcpu {
    struct arch_vcpu arch;
};

extern int xstate_alloc_save_area(struct vcpu *v);
extern int cpu_has_xsaves;
extern int cpu_has_xsavec;
extern void *_xzalloc(size_t size, int alignment);