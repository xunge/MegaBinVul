#include <stddef.h>
#include <stdbool.h>

struct task_struct {
    struct signal_struct *signal;
    struct sighand_struct *sighand;
    unsigned long utime;
    unsigned long stime;
    unsigned long gtime;
    unsigned long min_flt;
    unsigned long maj_flt;
    unsigned long nvcsw;
    unsigned long nivcsw;
    struct {
        unsigned long sum_exec_runtime;
    } se;
    void *ioac;
    void *pending;
};

struct signal_struct {
    struct tty_struct *tty;
    int notify_count;
    struct task_struct *group_exit_task;
    struct task_struct *curr_target;
    unsigned long utime;
    unsigned long stime;
    unsigned long gtime;
    unsigned long min_flt;
    unsigned long maj_flt;
    unsigned long nvcsw;
    unsigned long nivcsw;
    unsigned long inblock;
    unsigned long oublock;
    void *ioac;
    unsigned long sum_sched_runtime;
    int nr_threads;
    void *shared_pending;
};

struct sighand_struct {
    int siglock;
};

struct tty_struct;

#define TIF_SIGPENDING 0

static inline unsigned long cputime_add(unsigned long a, unsigned long b) { return a + b; }
static inline bool thread_group_leader(struct task_struct *tsk) { return false; }
static inline struct task_struct *next_thread(struct task_struct *tsk) { return tsk; }
static inline void __unhash_process(struct task_struct *tsk, bool group_dead) {}
static inline void flush_sigqueue(void *pending) {}
static inline void __cleanup_sighand(struct sighand_struct *sighand) {}
static inline void clear_tsk_thread_flag(struct task_struct *tsk, int flag) {}
static inline void wake_up_process(struct task_struct *tsk) {}
static inline void tty_kref_put(struct tty_struct *tty) {}
static inline unsigned long task_io_get_inblock(struct task_struct *tsk) { return 0; }
static inline unsigned long task_io_get_oublock(struct task_struct *tsk) { return 0; }
static inline void task_io_accounting_add(void *sig_ioac, void *tsk_ioac) {}
static inline void posix_cpu_timers_exit(struct task_struct *tsk) {}
static inline void posix_cpu_timers_exit_group(struct task_struct *tsk) {}

#define rcu_dereference_check(p, c) (p)
#define rcu_read_lock_held() 0
#define lockdep_tasklist_lock_is_held() 0
#define spin_lock(lock) 
#define spin_unlock(lock) 
#define uninitialized_var(x) x