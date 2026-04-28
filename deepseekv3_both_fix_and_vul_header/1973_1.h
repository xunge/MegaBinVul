#include <stdio.h>
#include <stddef.h>

struct task_struct;
struct signal_struct;

struct task_io_accounting {
    unsigned long long rchar;
    unsigned long long wchar;
    unsigned long long syscr;
    unsigned long long syscw;
    unsigned long long read_bytes;
    unsigned long long write_bytes;
    unsigned long long cancelled_write_bytes;
};

struct task_struct {
    struct task_io_accounting ioac;
    struct signal_struct *signal;
    struct task_struct *group_leader;
};

struct signal_struct {
    struct task_io_accounting ioac;
};

#define PTRACE_MODE_READ 0
#define EACCES 13

extern int ptrace_may_access(struct task_struct *task, int mode);
extern int lock_task_sighand(struct task_struct *task, unsigned long *flags);
extern void unlock_task_sighand(struct task_struct *task, unsigned long *flags);
extern void task_io_accounting_add(struct task_io_accounting *dst, struct task_io_accounting *src);
extern struct task_struct *next_thread(struct task_struct *t);

#define while_each_thread(g, t) \
    while ((t = next_thread(t)) != g)