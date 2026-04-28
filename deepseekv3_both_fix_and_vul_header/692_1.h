#include <stddef.h>

struct pt_regs {
    unsigned long msr;
};

struct thread_struct {
    struct pt_regs *regs;
};

struct task_struct {
    struct thread_struct thread;
};

#define MSR_FP 0x1000
#define MSR_VEC 0x2000
#define MSR_VSX 0x4000
#define MSR_SPE 0x8000

extern unsigned long msr_all_available;

void msr_check_and_set(unsigned long msr);
void msr_check_and_clear(unsigned long msr);
void check_if_tm_restore_required(struct task_struct *tsk);
void __giveup_fpu(struct task_struct *tsk);
void __giveup_altivec(struct task_struct *tsk);
void __giveup_spe(struct task_struct *tsk);

#define WARN_ON(condition) ((void)0)