#include <stddef.h>
#include <stdatomic.h>
#include <stdint.h>
#include <stdlib.h>

#define NORET_TYPE __attribute__((noreturn))
#define WARN_ON(condition) ((void)0)
#define unlikely(x) (x)
#define in_interrupt() (0)
#define in_atomic() (0)
#define preempt_count() (0)
#define KERN_ALERT ""
#define KERN_INFO ""
#define PF_EXITING (0)
#define PF_EXITPIDONE (0)
#define TASK_UNINTERRUPTIBLE (0)
#define TASK_DEAD (0)
#define CONFIG_FUTEX 1
#define CONFIG_COMPAT 1
#define CONFIG_NUMA 1

struct list_head {
    struct list_head *next, *prev;
};

typedef int spinlock_t;

struct task_struct {
    long pid;
    atomic_int fs_excl;
    unsigned int flags;
    void *io_context;
    struct signal_struct *signal;
    void *mm;
    void *robust_list;
    void *compat_robust_list;
    long exit_code;
    void *audit_context;
    struct list_head pi_state_list;
    void *pi_state_cache;
    void *splice_pipe;
    char comm[16];
    struct thread_info *thread_info;
    struct binfmt *binfmt;
    void *mempolicy;
    int state;
    spinlock_t pi_lock;
};

struct signal_struct {
    atomic_int live;
    void *real_timer;
    int leader;
};

struct thread_info {
    struct exec_domain *exec_domain;
};

struct exec_domain {
    void *module;
};

struct binfmt {
    void *module;
};

extern struct task_struct *current;

void panic(const char *str);
void printk(const char *fmt, ...);
void schedule(void);
void cpu_relax(void);
void BUG(void);
void profile_task_exit(void *);
void tracehook_report_exit(void *);
void exit_io_context(void);
void set_current_state(int);
void exit_signals(void *);
void smp_mb(void);
void spin_unlock_wait(spinlock_t *);
int task_pid_nr(void *);
void acct_update_integrals(void *);
void update_hiwater_rss(void *);
void update_hiwater_vm(void *);
int atomic_dec_and_test(atomic_int *);
void hrtimer_cancel(void *);
void exit_itimers(void *);
void acct_collect(long, int);
void exit_robust_list(void *);
void compat_exit_robust_list(void *);
void tty_audit_exit(void);
void audit_free(void *);
void taskstats_exit(void *, int);
void exit_mm(void *);
void acct_process(void);
void trace_sched_process_exit(void *);
void exit_sem(void *);
void exit_files(void *);
void exit_fs(void *);
void check_stack_usage(void);
void exit_thread(void);
void cgroup_exit(void *, int);
void exit_keys(void *);
void disassociate_ctty(int);
void module_put(void *);
struct thread_info *task_thread_info(void *);
void proc_exit_connector(void *);
void exit_notify(void *, int);
void mpol_put(void *);
int list_empty(struct list_head *);
void exit_pi_state_list(void *);
void kfree(void *);
void debug_check_no_locks_held(void *);
void __free_pipe_info(void *);
void preempt_disable(void);