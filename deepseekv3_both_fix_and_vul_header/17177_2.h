#include <sys/types.h>
#include <signal.h>
#include <limits.h>
#include <errno.h>
#include <stddef.h>

typedef int pid_t;
struct siginfo;
struct task_struct;
struct pid;

extern int kill_pid_info(int sig, struct siginfo *info, struct pid *pid);
extern int __kill_pgrp_info(int sig, struct siginfo *info, struct pid *pgrp);
extern struct pid *find_vpid(int nr);
extern struct pid *task_pgrp(struct task_struct *task);
extern int task_pid_vnr(struct task_struct *tsk);
extern int same_thread_group(struct task_struct *p1, struct task_struct *p2);
extern int group_send_sig_info(int sig, struct siginfo *info, struct task_struct *p);
extern void rcu_read_lock(void);
extern void rcu_read_unlock(void);
extern void read_lock(void *lock);
extern void read_unlock(void *lock);
extern struct task_struct *current;
extern void *tasklist_lock;
#define for_each_process(p) for (p = NULL; p != NULL; p = NULL)