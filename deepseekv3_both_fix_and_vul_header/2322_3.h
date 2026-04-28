#include <stdint.h>
#include <stddef.h>

typedef uint64_t u64;

#define __user
#define unlikely(x) (x)
#define IS_ENABLED(x) 0
#define CONFIG_X86_32 0
#define CONFIG_IA32_EMULATION 0
#define VERIFY_READ 0
#define EACCES 1
#define EINVAL 1
#define X86_FEATURE_FPU 0

struct fpu {
    struct {
        struct {
            struct {
                u64 xcomp_bv;
            } header;
        } xsave;
    } state;
    int fpstate_active;
};

struct xregs_state {
    struct {
        u64 xcomp_bv;
    } header;
};

struct task_struct {
    struct {
        struct fpu fpu;
    } thread;
};

struct user_i387_ia32_struct {};
struct fxregs_state {};
struct _fpx_sw_bytes {
    uint32_t xstate_size;
    u64 xfeatures;
};

extern struct task_struct *current;
extern int fpu_kernel_xstate_size;
extern int use_xsave(void);
extern int check_for_xstate(void *, void *, struct _fpx_sw_bytes *);
extern void fpu__clear(struct fpu *);
extern int access_ok(int, void *, int);
extern void fpu__activate_curr(struct fpu *);
extern int fpregs_soft_set(struct task_struct *, void *, int, int, void *, void *);
extern void trace_x86_fpu_xstate_check_failed(struct fpu *);
extern int using_compacted_format(void);
extern int copy_user_to_xstate(struct xregs_state *, void *);
extern int __copy_from_user(void *, void *, int);
extern void fpstate_init(void *);
extern void trace_x86_fpu_init_state(struct fpu *);
extern void sanitize_restored_xstate(struct task_struct *, struct user_i387_ia32_struct *, u64, int);
extern void fpu__drop(struct fpu *);
extern void fpu__restore(struct fpu *);
extern void preempt_disable(void);
extern void preempt_enable(void);
extern void user_fpu_begin(void);
extern int copy_user_to_fpregs_zeroing(void *, u64, int);
extern int static_cpu_has(int);