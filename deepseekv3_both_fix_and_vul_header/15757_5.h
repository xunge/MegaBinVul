#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <sched.h>
#include <sys/types.h>

#define TASK_COMM_LEN 16
#define PF_NO_SETAFFINITY 0x04000000
#define IO_SQ_THREAD_SHOULD_STOP 0
#define IO_SQ_THREAD_SHOULD_PARK 1
#define IORING_SETUP_IOPOLL (1 << 0)
#define TASK_INTERRUPTIBLE 1

struct list_head {
    struct list_head *next, *prev;
};

struct mutex {
    int lock;
};

struct completion {
    int done;
};

struct wait_queue_head {
    int lock;
};

typedef struct wait_queue_head wait_queue_head_t;

struct io_sq_data {
    int task_pid;
    int sq_cpu;
    unsigned long sq_thread_idle;
    struct list_head ctx_list;
    struct mutex lock;
    unsigned long state;
    struct task_struct *thread;
    struct completion exited;
    struct list_head park_task_work;
    wait_queue_head_t wait;
};

struct io_ring_ctx {
    struct list_head sqd_list;
    struct list_head iopoll_list;
    unsigned int flags;
    struct cred *sq_creds;
};

struct task_struct {
    char comm[TASK_COMM_LEN];
    unsigned long flags;
    void *pf_io_worker;
};

struct ksignal {
    int dummy;
};

struct cred {
    int dummy;
};

struct wait_queue_entry {
    int dummy;
};

#define DEFINE_WAIT(name) struct wait_queue_entry name = {0}
#define list_for_each_entry(pos, head, member) for (pos = NULL; pos != NULL; pos = NULL)
#define sqd_list dummy_member

extern struct task_struct *current;
extern unsigned long jiffies;
extern const struct cpumask *cpu_online_mask;

static inline void set_task_comm(struct task_struct *tsk, const char *buf) {}
static inline void set_cpus_allowed_ptr(struct task_struct *p, const struct cpumask *new_mask) {}
static inline const struct cpumask *cpumask_of(int cpu) { return NULL; }
static inline void mutex_lock(struct mutex *lock) {}
static inline void mutex_unlock(struct mutex *lock) {}
static inline int test_bit(int nr, const volatile unsigned long *addr) { return 0; }
static inline int signal_pending(struct task_struct *p) { return 0; }
static inline int get_signal(struct ksignal *ksig) { return 0; }
static inline void cond_resched(void) {}
static inline void io_run_task_work(void) {}
static inline void io_run_task_work_head(struct list_head *work) {}
static inline bool list_is_singular(const struct list_head *head) { return false; }
static inline struct cred *current_cred(void) { return NULL; }
static inline struct cred *override_creds(struct cred *new) { return NULL; }
static inline void revert_creds(const struct cred *old) {}
static inline int __io_sq_thread(struct io_ring_ctx *ctx, bool cap_entries) { return 0; }
static inline bool list_empty(const struct list_head *head) { return true; }
static inline bool list_empty_careful(const struct list_head *head) { return true; }
static inline bool time_after(unsigned long a, unsigned long b) { return false; }
static inline void prepare_to_wait(wait_queue_head_t *q, void *wait, int state) {}
static inline void finish_wait(wait_queue_head_t *q, void *wait) {}
static inline void schedule(void) {}
static inline void io_ring_set_wakeup_flag(struct io_ring_ctx *ctx) {}
static inline void io_ring_clear_wakeup_flag(struct io_ring_ctx *ctx) {}
static inline void io_uring_cancel_sqpoll(struct io_ring_ctx *ctx) {}
static inline int io_sqring_entries(struct io_ring_ctx *ctx) { return 0; }
static inline void complete(struct completion *comp) {}
static inline void do_exit(int code) {}