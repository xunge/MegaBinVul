#include <stddef.h>
#include <signal.h>
#include <stdint.h>

#define DR6_RESERVED    0xFFFF0FF0
#define DR_STEP         0x4000
#define DR_TRAP_BITS    0xF
#define X86_VM_MASK     (1 << 17)
#define X86_EFLAGS_TF   0x100
#define TIF_BLOCKSTEP   4
#define TIF_SINGLESTEP  5
#define SIGTRAP        5
#define NOTIFY_STOP     0x8000
#define DIE_DEBUG      1

struct pt_regs {
    unsigned long flags;
};

struct kernel_vm86_regs {
};

struct thread_struct {
    unsigned long debugreg6;
};

struct task_struct {
    struct thread_struct thread;
    unsigned long flags;
};

#define __kprobes

extern struct task_struct *current;
extern int user_mode(struct pt_regs *regs);
extern void get_debugreg(unsigned long val, int reg);
extern void set_debugreg(unsigned long val, int reg);
extern void clear_tsk_thread_flag(struct task_struct *tsk, int flag);
extern void set_tsk_thread_flag(struct task_struct *tsk, int flag);
extern int notify_die(int val, const char *str, struct pt_regs *regs, long err, long trap, int sig);
extern void conditional_sti_ist(struct pt_regs *regs);
extern void conditional_cli_ist(struct pt_regs *regs);
extern void preempt_conditional_sti(struct pt_regs *regs);
extern void preempt_conditional_cli(struct pt_regs *regs);
extern void handle_vm86_trap(struct kernel_vm86_regs *regs, long error_code, int trapno);
extern int kmemcheck_trap(struct pt_regs *regs);
extern int get_si_code(unsigned long debugreg6);
extern void send_sigtrap(struct task_struct *tsk, struct pt_regs *regs, long error_code, int si_code);
static inline long PTR_ERR(const void *ptr) { return (long)ptr; }