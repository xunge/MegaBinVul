#include <stddef.h>

struct task_struct;
struct cred;
void rcu_read_lock(void);
void rcu_read_unlock(void);
void __ptrace_link(struct task_struct *, struct task_struct *, struct cred *);
struct cred *__task_cred(struct task_struct *);