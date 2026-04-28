#include <stddef.h>
#include <stdbool.h>

#define PF_KTHREAD 0x00200000
#define __TASK_STOPPED 0x00000002
#define TASK_KILLABLE 1

struct task_struct {
    unsigned int flags;
    unsigned int exit_state;
    unsigned long ptrace;
    struct signal_struct *signal;
    struct sighand_struct *sighand;
    unsigned long jobctl;
};

struct signal_struct {
    void *cred_guard_mutex;
};

struct sighand_struct {
    void *siglock;
};

#define PTRACE_SEIZE 0x4206
#define PTRACE_O_MASK 0x0000ffff
#define PT_PTRACED 0x00000001
#define PT_SEIZED 0x00000002
#define PT_OPT_FLAG_SHIFT 3

#define JOBCTL_TRAP_STOP 0x00000080
#define JOBCTL_TRAPPING 0x00000100
#define JOBCTL_TRAPPING_BIT 8

#define EIO 5
#define EPERM 1
#define ERESTARTNOINTR 512

#define SEND_SIG_PRIV 0
#define SIGSTOP 19

#define PTRACE_MODE_ATTACH_REALCREDS 2
#define PTRACE_ATTACH 0

extern int audit_ptrace(struct task_struct *task);
extern int __ptrace_may_access(struct task_struct *task, int mode);
extern void ptrace_link(struct task_struct *child, struct task_struct *new_parent);
extern void send_sig_info(int sig, int priv, struct task_struct *p);
extern int task_is_stopped(struct task_struct *task);
extern int task_set_jobctl_pending(struct task_struct *task, unsigned long mask);
extern void signal_wake_up_state(struct task_struct *task, unsigned int state);
extern void wait_on_bit(unsigned long *word, int bit, int mode);
extern void proc_ptrace_connector(struct task_struct *task, int event);

#define current get_current()
extern struct task_struct *get_current(void);

#define unlikely(x) __builtin_expect(!!(x), 0)
#define same_thread_group(p1, p2) (1)

#define task_lock(tsk) 
#define task_unlock(tsk) 

#define write_lock_irq(lock) 
#define write_unlock_irq(lock) 

static inline int mutex_lock_interruptible(void *mutex) { return 0; }
static inline void mutex_unlock(void *mutex) {}
static inline void spin_lock(void *lock) {}
static inline void spin_unlock(void *lock) {}