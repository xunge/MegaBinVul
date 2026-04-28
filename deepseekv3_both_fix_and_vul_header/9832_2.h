#include <stdatomic.h>
#include <stddef.h>
#include <stdint.h>

#define NORET_TYPE _Noreturn
#define unlikely(x) (x)
#define likely(x) (x)
#define WARN_ON(cond) 
#define KERN_ALERT ""
#define KERN_INFO ""
#define PF_EXITING 0
#define PF_EXITPIDONE 0
#define USER_DS 0
#define TASK_UNINTERRUPTIBLE 0
#define TASK_DEAD 0
#define CONFIG_NUMA 0
#define CONFIG_FUTEX 0

struct task_struct {
    atomic_int fs_excl;
    int pid;
    int flags;
    void *mm;
    struct signal_struct *signal;
    void *audit_context;
    void *io_context;
    void *splice_pipe;
    void *mempolicy;
    void *pi_state_cache;
    int exit_code;
    int state;
    char comm[16];
    void *pi_lock;
};

struct signal_struct {
    atomic_int live;
    void *real_timer;
    void *maxrss;
};

struct thread_info {
    struct exec_domain *exec_domain;
};

struct exec_domain {
    void *module;
};

extern struct task_struct *current;

void profile_task_exit(struct task_struct *tsk);
void set_fs(int fs);
void tracehook_report_exit(long *code);
void validate_creds_for_do_exit(struct task_struct *tsk);
void printk(const char *fmt, ...);
void exit_irq_thread(void);
void exit_signals(struct task_struct *tsk);
void smp_mb(void);
void raw_spin_unlock_wait(void *lock);
int in_atomic(void);
int task_pid_nr(struct task_struct *tsk);
int preempt_count(void);
void acct_update_integrals(struct task_struct *tsk);
void sync_mm_rss(struct task_struct *tsk, void *mm);
void hrtimer_cancel(void *timer);
void exit_itimers(void *signal);
void setmax_mm_hiwater_rss(void *maxrss, void *mm);
void acct_collect(long code, int group_dead);
void tty_audit_exit(void);
void audit_free(struct task_struct *tsk);
void taskstats_exit(struct task_struct *tsk, int group_dead);
void exit_mm(struct task_struct *tsk);
void acct_process(void);
void trace_sched_process_exit(struct task_struct *tsk);
void exit_sem(struct task_struct *tsk);
void exit_files(struct task_struct *tsk);
void exit_fs(struct task_struct *tsk);
void check_stack_usage(void);
void exit_thread(void);
void cgroup_exit(struct task_struct *tsk, int flag);
void disassociate_ctty(int flag);
void module_put(void *module);
void proc_exit_connector(struct task_struct *tsk);
void flush_ptrace_hw_breakpoint(struct task_struct *tsk);
void perf_event_exit_task(struct task_struct *tsk);
void exit_notify(struct task_struct *tsk, int group_dead);
void task_lock(struct task_struct *tsk);
void mpol_put(void *mempolicy);
void task_unlock(struct task_struct *tsk);
void kfree(void *ptr);
void debug_check_no_locks_held(struct task_struct *tsk);
void exit_io_context(struct task_struct *tsk);
void __free_pipe_info(void *pipe);
void preempt_disable(void);
void exit_rcu(void);
void schedule(void);
void BUG(void);
void cpu_relax(void);
void panic(const char *msg);
int in_interrupt(void);
struct thread_info *task_thread_info(struct task_struct *tsk);
void set_current_state(int state);
int atomic_dec_and_test(atomic_int *v);