#include <stddef.h>
#include <signal.h>

#define EPERM 1
#define PT_PTRACED 0x00000001
#define PT_PTRACE_CAP 0x00000002
#define PTRACE_MODE_ATTACH 0x01
#define SEND_SIG_FORCED 0x1
#define CAP_SYS_PTRACE 0
#define SIGSTOP 19

struct task_struct {
    unsigned long ptrace;
    void *mm;
    void *cred_exec_mutex;
    struct task_struct *group_leader;
};

struct mutex {
    int lock;
};

struct spinlock {
    int lock;
};

extern struct task_struct *current;
extern struct spinlock tasklist_lock;

int audit_ptrace(struct task_struct *task);
int same_thread_group(struct task_struct *p1, struct task_struct *p2);
int mutex_lock_interruptible(struct mutex *lock);
void mutex_unlock(struct mutex *lock);
void task_lock(struct task_struct *task);
void task_unlock(struct task_struct *task);
int __ptrace_may_access(struct task_struct *task, int mode);
void __ptrace_link(struct task_struct *child, struct task_struct *new_parent);
int send_sig_info(int sig, int flags, struct task_struct *p);
int capable(int cap);
void cpu_relax(void);

static inline int write_trylock_irqsave(struct spinlock *lock, unsigned long flags) {
    return 0;
}

static inline int write_can_lock(struct spinlock *lock) {
    return 0;
}

static inline void write_unlock_irqrestore(struct spinlock *lock, unsigned long flags) {
}