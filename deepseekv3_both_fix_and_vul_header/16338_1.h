#include <stddef.h>
#include <stdbool.h>
#include <stdatomic.h>

struct task_struct {
    int exit_state;
    _Atomic int usage;
    struct signal_struct *signal;
};

struct signal_struct;

#define WARN_ON(condition) ((void)0)
#define current ((struct task_struct *)NULL)

static inline int refcount_read(_Atomic int *r) {
    return atomic_load(r);
}

extern void cgroup_free(struct task_struct *tsk);
extern void task_numa_free(struct task_struct *tsk, bool flag);
extern void security_task_free(struct task_struct *tsk);
extern void exit_creds(struct task_struct *tsk);
extern void delayacct_tsk_free(struct task_struct *tsk);
extern void put_signal_struct(struct signal_struct *sig);
extern bool profile_handoff_task(struct task_struct *tsk);
extern void free_task(struct task_struct *tsk);