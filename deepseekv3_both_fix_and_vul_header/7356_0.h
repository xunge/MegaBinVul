#include <stdint.h>

#define MAX_INTERCEPT 32
#define VMCB_INTERCEPTS 1
#define V_INTR_MASKING_MASK (1 << 24)
#define INTERCEPT_CR8_READ 0
#define INTERCEPT_CR8_WRITE 1
#define INTERCEPT_VINTR 2
#define INTERCEPT_VMMCALL 3
#define INTERCEPT_SMI 4
#define INTERCEPT_VMLOAD 5
#define INTERCEPT_VMSAVE 6

struct vmcb_control_area {
    uint32_t intercepts[MAX_INTERCEPT];
    uint32_t int_ctl;
};

struct vmcb {
    struct vmcb_control_area control;
};

struct nested_svm {
    struct vmcb_control_area ctl;
};

struct vcpu_svm {
    struct vmcb *vmcb;
    struct {
        struct vmcb *ptr;
    } vmcb01;
    struct nested_svm nested;
    struct {
        int vcpu;
    } vcpu;
};

extern int is_guest_mode(int *vcpu);
extern void vmcb_mark_dirty(struct vmcb *vmcb, int flag);
extern void vmcb_clr_intercept(struct vmcb_control_area *c, int intercept);
extern void vmcb_set_intercept(struct vmcb_control_area *c, int intercept);
extern int intercept_smi;