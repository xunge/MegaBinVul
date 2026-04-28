#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>

typedef struct { int lock; } rwlock_t;

struct siginfo {
    int si_signo;
    int si_errno;
    int si_code;
};

struct task_struct {
    pid_t pid;
    struct task_struct *group_leader;
};

struct pid {
    int nr;
};

extern rwlock_t tasklist_lock;
extern struct task_struct *current;
extern struct task_struct init_task;

void rcu_read_lock(void);
void rcu_read_unlock(void);
void read_lock(rwlock_t *lock);
void read_unlock(rwlock_t *lock);

int kill_pid_info(int sig, struct siginfo *info, struct pid *pid);
struct pid *find_vpid(int nr);
struct pid *task_pgrp(struct task_struct *task);
int __kill_pgrp_info(int sig, struct siginfo *info, struct pid *pgrp);
int group_send_sig_info(int sig, struct siginfo *info, struct task_struct *p);
bool same_thread_group(struct task_struct *p1, struct task_struct *p2);
struct task_struct *next_task(struct task_struct *task);

#define for_each_process(p) \
    for (p = &init_task; (p = next_task(p)) != &init_task; )