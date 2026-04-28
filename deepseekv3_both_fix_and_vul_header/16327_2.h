#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <stdbool.h>

#define EBUSY 16
#define IORING_SETUP_IOPOLL (1U << 0)

struct cred;
struct list_head {
    struct list_head *next, *prev;
};

struct io_ring_ctx {
    int sq_thread_comp;
    struct cred *creds;
    unsigned long sq_thread_idle;
    struct list_head iopoll_list;
    pthread_mutex_t uring_lock;
    pthread_cond_t sqo_wait;
    unsigned int flags;
    int refs;
};

#define DEFINE_WAIT(wait) int wait
#define TASK_INTERRUPTIBLE 0
#define jiffies time(NULL)
#define need_resched() false
#define kthread_should_park() false
#define kthread_parkme() 
#define cond_resched() 
#define schedule() usleep(1000)
#define signal_pending(x) false
#define flush_signals(x)
#define likely(x) x
#define current pthread_self()

static inline bool list_empty(const struct list_head *head) { return true; }
static inline bool list_empty_careful(const struct list_head *head) { return true; }
static inline void mutex_lock(pthread_mutex_t *lock) { pthread_mutex_lock(lock); }
static inline void mutex_unlock(pthread_mutex_t *lock) { pthread_mutex_unlock(lock); }
static inline void prepare_to_wait(pthread_cond_t *cond, int *wait, int state) {}
static inline void finish_wait(pthread_cond_t *cond, int *wait) {}
static inline bool time_after(unsigned long a, unsigned long b) { return a > b; }
static inline bool percpu_ref_is_dying(int *ref) { return false; }

static inline void complete(int *comp) {}
static inline struct cred *override_creds(struct cred *creds) { return NULL; }
static inline void revert_creds(const struct cred *creds) {}
static inline void io_sq_thread_drop_mm() {}
static inline unsigned int io_sqring_entries(struct io_ring_ctx *ctx) { return 0; }
static inline void io_do_iopoll(struct io_ring_ctx *ctx, unsigned int *nr_events, int flags) {}
static inline bool io_run_task_work() { return false; }
static inline void io_ring_set_wakeup_flag(struct io_ring_ctx *ctx) {}
static inline void io_ring_clear_wakeup_flag(struct io_ring_ctx *ctx) {}
static inline int io_submit_sqes(struct io_ring_ctx *ctx, unsigned int to_submit, ...) { return 0; }