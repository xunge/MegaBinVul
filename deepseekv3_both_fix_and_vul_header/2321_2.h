#include <stddef.h>
#include <stdint.h>
#include <string.h>

#define X86_FEATURE_XSAVE 0
#define X86_FEATURE_XSAVES 0
#define ENODEV 19
#define EFAULT 14
#define EINVAL 22

struct user_regset;

struct i387_struct {
    unsigned long mxcsr;
};

struct xstate_header {
    unsigned long xfeatures;
    unsigned long xcomp_bv;
    unsigned char reserved[48];
};

struct xregs_state {
    struct i387_struct i387;
    struct xstate_header header;
};

struct fpu {
    struct {
        struct xregs_state xsave;
    } state;
};

struct task_struct {
    struct {
        struct fpu fpu;
    } thread;
};

#define __user

extern int boot_cpu_has(int feature);
extern size_t fpu_user_xstate_size;
extern unsigned long mxcsr_feature_mask;
extern unsigned long xfeatures_mask;
extern void fpstate_init(void *state);
extern int copy_kernel_to_xstate(struct xregs_state *xsave, const void *kbuf);
extern int copy_user_to_xstate(struct xregs_state *xsave, const void __user *ubuf);
extern int user_regset_copyin(unsigned int *pos, unsigned int *count, const void **kbuf, const void __user **ubuf, void *data, unsigned int start_pos, unsigned int end_pos);
extern void fpu__activate_fpstate_write(struct fpu *fpu);