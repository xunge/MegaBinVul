#include <stddef.h>

struct fpu {
    unsigned int has_fpu;
};

struct thread_struct {
    struct fpu fpu;
};

struct task_struct {
    struct thread_struct thread;
};

#define ASM_NOP8 ".byte 0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00"
#define ASM_NOP2 ".byte 0x66,0x90"
#define X86_FEATURE_FXSAVE_LEAK 0

static inline void alternative_input(const char *old, const char *new, int feature, const char *input) {
    (void)old;
    (void)new;
    (void)feature;
    (void)input;
}

static inline int fpu_restore_checking(struct fpu *fpu) {
    (void)fpu;
    return 0;
}

#define alternative_input(old, new, feature, ...) \
    alternative_input(old, new, feature, NULL)