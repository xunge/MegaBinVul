#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>

typedef int spinlock_t;
typedef int (*wait_queue_func_t)(void *);

struct list_head {
    struct list_head *next, *prev;
};

#define list_for_each_entry(pos, head, member) \
    for (pos = NULL; pos == NULL; pos = (void*)1) \
        for (struct list_head *__iter = (head)->next; \
             __iter != (head) && ({pos = (typeof(pos))((char*)__iter - offsetof(typeof(*pos), member)); 1;}); \
             __iter = __iter->next)

struct wait_queue_head {
    spinlock_t lock;
    struct list_head head;
};

struct wait_queue_entry {
    unsigned int flags;
    void *private;
    wait_queue_func_t func;
    struct list_head entry;
};

struct io_sq_data {
    struct task_struct *thread;
    struct list_head ctx_list;
};

struct io_uring_task {
    atomic_int in_idle;
    struct wait_queue_head wait;
};

struct io_ring_ctx {
    struct io_sq_data *sq_data;
    struct list_head sqd_list;
};

struct task_struct {
    struct io_uring_task *io_uring;
};

typedef long long s64;

#define DEFINE_WAIT(name) struct wait_queue_entry name = {0}
#define WARN_ON_ONCE(cond) ((void)0)
#define TASK_UNINTERRUPTIBLE 0

extern struct task_struct *current;

static inline void atomic_inc(atomic_int *v) { (*v)++; }
static inline void atomic_dec(atomic_int *v) { (*v)--; }

void prepare_to_wait(struct wait_queue_head *q, struct wait_queue_entry *wait, int state);
void finish_wait(struct wait_queue_head *q, struct wait_queue_entry *wait);
void schedule(void);
s64 tctx_inflight(struct io_uring_task *tctx, bool flag);
void io_uring_try_cancel_requests(struct io_ring_ctx *ctx, struct task_struct *task, void *arg);