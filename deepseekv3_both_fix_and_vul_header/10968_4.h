#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <stdint.h>
#include <stdbool.h>

typedef uintptr_t mm_segment_t;
#define USER_DS ((mm_segment_t)0)
#define IORING_SETUP_IOPOLL (1 << 0)
#define IORING_SQ_NEED_WAKEUP (1 << 0)
#define TASK_INTERRUPTIBLE 1
#define EBUSY 16

struct list_head {
    struct list_head *next, *prev;
};

struct wait_queue_head;
struct wait_queue_entry {
    unsigned int flags;
    void *private;
    void *func;
    struct list_head entry;
};
#define DEFINE_WAIT(name) struct wait_queue_entry name = {0}

struct io_ring_ctx {
    void *completions;
    unsigned long flags;
    pthread_mutex_t uring_lock;
    struct list_head poll_list;
    unsigned long sq_thread_idle;
    unsigned int sq_entries;
    struct wait_queue_head *sqo_wait;
    struct io_rings *rings;
    void *creds;
};

struct io_rings {
    unsigned int sq_flags;
};

struct mm_struct;
struct cred;

static inline int kthread_should_park(void) { return 0; }
static inline void kthread_parkme(void) {}
static inline void complete(void *c) {}
static inline mm_segment_t get_fs(void) { return 0; }
static inline void set_fs(mm_segment_t fs) {}
static inline void *override_creds(void *c) { return NULL; }
static inline void revert_creds(void *c) {}
static inline void mutex_lock(pthread_mutex_t *m) {}
static inline void mutex_unlock(pthread_mutex_t *m) {}
static inline int list_empty(struct list_head *h) { return 1; }
static inline void __io_iopoll_check(void *ctx, unsigned *nr, int b) {}
static inline unsigned io_sqring_entries(void *ctx) { return 0; }
static inline int io_submit_sqes(void *ctx, unsigned n, void *a, int b, void **m, bool c) { return 0; }
static inline void cond_resched(void) {}
static inline void unuse_mm(void *m) {}
static inline void mmput(void *m) {}
static inline void prepare_to_wait(void *wq, void *w, int s) {}
static inline void finish_wait(void *wq, void *w) {}
static inline int signal_pending(void *t) { return 0; }
static inline void flush_signals(void *t) {}
static inline void schedule(void) {}
static inline void smp_mb(void) {}
static inline int time_after(unsigned long a, unsigned long b) { return a > b; }
static inline unsigned long min(unsigned long a, unsigned long b) { return a < b ? a : b; }

extern unsigned long volatile jiffies;
extern void *current;