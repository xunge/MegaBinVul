#include <stddef.h>
#include <signal.h>
#include <sys/types.h>

#define EPERM 1
#define SIGSTOP 19

#define PT_PTRACED 0x00000001
#define PT_ATTACHED 0x00000002
#define PT_PTRACE_CAP 0x00000004

#define CAP_SYS_PTRACE 0

struct task_struct {
    pid_t pid;
    pid_t tgid;
    unsigned long ptrace;
    struct task_struct *real_parent;
    // Other members omitted
};

extern struct task_struct *current;
extern struct rwlock tasklist_lock;

static inline void task_lock(struct task_struct *task) {}
static inline void task_unlock(struct task_struct *task) {}
static inline void write_lock_irq(void *lock) {}
static inline void write_unlock_irq(void *lock) {}
static inline int capable(int cap) { return 1; }
static inline void force_sig_specific(int sig, struct task_struct *task) {}

int may_attach(struct task_struct *task);
void __ptrace_link(struct task_struct *child, struct task_struct *new_parent);