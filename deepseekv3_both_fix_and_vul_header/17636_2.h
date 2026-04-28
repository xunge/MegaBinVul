#include <stddef.h>
#include <stdbool.h>
#include <sys/types.h>
#include <time.h>

typedef unsigned long long u64;

struct kernel_siginfo {
    int si_signo;
    int si_errno;
    pid_t si_pid;
    uid_t si_uid;
    clock_t si_utime;
    clock_t si_stime;
    int si_status;
    int si_code;
};

struct sighand_struct {
    unsigned long siglock;
    struct {
        struct {
            void (*sa_handler)(int);
            unsigned long sa_flags;
        } sa;
    } action[64];
};

struct task_struct {
    struct task_struct *parent;
    struct task_struct *group_leader;
    struct signal_struct *signal;
    unsigned long parent_exec_id;
    unsigned long self_exec_id;
    int exit_code;
    bool ptrace;
    struct sighand_struct *sighand;
};

struct signal_struct {
    u64 utime;
    u64 stime;
};

typedef int pid_t;
typedef unsigned int uid_t;

#define BUG_ON(condition) ((void)0)
#define task_is_stopped_or_traced(tsk) (0)
#define thread_group_empty(tsk) (0)
#define task_pid_nr_ns(tsk, ns) (0)
#define from_kuid_munged(ns, uid) (0)
#define task_cred_xxx(tsk, field) (NULL)
#define task_uid(tsk) (0)
#define task_active_pid_ns(parent) (NULL)
#define valid_signal(sig) (1)
#define SIGCHLD 17
#define SIG_IGN ((void (*)(int))1)
#define SA_NOCLDWAIT (1 << 0)
#define CLD_DUMPED 3
#define CLD_KILLED 2
#define CLD_EXITED 1

void clear_siginfo(struct kernel_siginfo *info);
void do_notify_pidfd(struct task_struct *tsk);
void task_cputime(struct task_struct *tsk, u64 *utime, u64 *stime);
clock_t nsec_to_clock_t(u64 nsec);
void __group_send_sig_info(int sig, struct kernel_siginfo *info, struct task_struct *parent);
void __wake_up_parent(struct task_struct *tsk, struct task_struct *parent);
void spin_lock_irqsave(unsigned long *lock, unsigned long flags);
void spin_unlock_irqrestore(unsigned long *lock, unsigned long flags);
void rcu_read_lock(void);
void rcu_read_unlock(void);