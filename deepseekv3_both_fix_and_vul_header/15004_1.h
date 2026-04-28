#include <sys/ptrace.h>
#include <errno.h>

#define PT_PTRACED 0x00000001

struct task_struct {
    int ptrace;
    struct task_struct *parent;
};

extern struct task_struct *current;

int security_ptrace(struct task_struct *parent, struct task_struct *child);