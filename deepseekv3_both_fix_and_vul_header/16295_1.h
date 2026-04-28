#include <stdbool.h>
#include <stddef.h>

struct task_struct {
    int exit_state;
    int usage;
    struct signal_struct *signal;
};

struct signal_struct;

extern struct task_struct *current;

void WARN_ON(bool condition);
unsigned int refcount_read(int *count);
void cgroup_free(struct task_struct *tsk);
void task_numa_free(struct task_struct *tsk, ...);
void security_task_free(struct task_struct *tsk);
void exit_creds(struct task_struct *tsk);
void delayacct_tsk_free(struct task_struct *tsk);
void put_signal_struct(struct signal_struct *sig);
bool profile_handoff_task(struct task_struct *tsk);
void free_task(struct task_struct *tsk);