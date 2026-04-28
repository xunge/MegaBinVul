#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>

#define EPERM 1

#define PT_PTRACED      0x00000001
#define PT_ATTACHED     0x00000002  
#define PT_PTRACE_CAP   0x00000004

#define CAP_SYS_PTRACE  0
#define SIGSTOP         19

struct task_struct {
    int pid;
    int tgid;
    unsigned long ptrace;
    struct task_struct *real_parent;
};

extern struct task_struct *current;
extern int tasklist_lock;

int may_attach(struct task_struct *task);
void __ptrace_link(struct task_struct *child, struct task_struct *new_parent);
void force_sig_specific(int sig, struct task_struct *p);
void task_lock(struct task_struct *task);
void task_unlock(struct task_struct *task);
void write_lock_irq(int *lock);
void write_unlock_irq(int *lock);
int capable(int cap);