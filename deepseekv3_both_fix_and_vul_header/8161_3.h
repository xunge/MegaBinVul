#include <stddef.h>

#define PTRACE_PEEKUSR 1
#define PTRACE_POKEUSR 2
#define PTRACE_GETREGS 3
#define PTRACE_SETREGS 4
#define PTRACE_GETFPREGS 5
#define PTRACE_SETFPREGS 6
#define PTRACE_GETWMMXREGS 7
#define PTRACE_SETWMMXREGS 8
#define PTRACE_GET_THREAD_AREA 9
#define PTRACE_SET_SYSCALL 10
#define PTRACE_GETCRUNCHREGS 11
#define PTRACE_SETCRUNCHREGS 12
#define PTRACE_GETVFPREGS 13
#define PTRACE_SETVFPREGS 14
#define PTRACE_GETHBPREGS 15
#define PTRACE_SETHBPREGS 16
#define ESRCH 3

struct task_struct;
struct thread_info {
    unsigned long tp_value[1];
    long syscall;
};

struct pt_regs {
    unsigned long regs[18];
};

union fp_state {
    unsigned long regs[32];
};

#define ARM_VFPREGS_SIZE (32 * 8)
#define REGSET_GPR 0
#define REGSET_FPR 1
#define REGSET_VFP 2

struct user_arm_view {
    int dummy;
};

extern struct user_arm_view user_arm_view;
extern struct thread_info *task_thread_info(struct task_struct *task);
extern int ptrace_read_user(struct task_struct *child, unsigned long addr, unsigned long *data);
extern int ptrace_write_user(struct task_struct *child, unsigned long addr, unsigned long data);
extern int copy_regset_to_user(struct task_struct *child, const struct user_arm_view *view, int regset, unsigned int pos, unsigned int count, void *data);
extern int copy_regset_from_user(struct task_struct *child, const struct user_arm_view *view, int regset, unsigned int pos, unsigned int count, const void *data);
extern int ptrace_getwmmxregs(struct task_struct *child, unsigned long *data);
extern int ptrace_setwmmxregs(struct task_struct *child, unsigned long *data);
extern int ptrace_getcrunchregs(struct task_struct *child, unsigned long *data);
extern int ptrace_setcrunchregs(struct task_struct *child, unsigned long *data);
extern int ptrace_gethbpregs(struct task_struct *child, unsigned long addr, unsigned long *data);
extern int ptrace_sethbpregs(struct task_struct *child, unsigned long addr, unsigned long *data);
extern int ptrace_get_breakpoints(struct task_struct *child);
extern int ptrace_put_breakpoints(struct task_struct *child);
extern int ptrace_request(struct task_struct *child, long request, unsigned long addr, unsigned long data);
extern int put_user(unsigned long x, unsigned long *ptr);

#define __user