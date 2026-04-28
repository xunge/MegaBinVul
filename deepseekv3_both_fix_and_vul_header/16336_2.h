#include <stdbool.h>
#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct files_struct;
struct io_wq;
struct io_wq_work;

struct io_ring_ctx {
    struct list_head inflight_list;
    int inflight_lock;
    int inflight_wait;
    struct io_wq *io_wq;
};

struct io_kiocb {
    struct list_head inflight_entry;
    struct {
        struct files_struct *files;
    } work;
    int refs;
};

#define DEFINE_WAIT(name) int name
#define TASK_UNINTERRUPTIBLE 0
#define list_for_each_entry(pos, head, member) \
    for (pos = (typeof(pos))((head)->next); &pos->member != (head); pos = (typeof(pos))(pos->member.next))

static inline bool list_empty_careful(const struct list_head *head) { return false; }
static inline void spin_lock_irq(int *lock) {}
static inline void spin_unlock_irq(int *lock) {}
static inline void prepare_to_wait(int *wq_head, int *wait, int state) {}
static inline void finish_wait(int *wq_head, int *wait) {}
static inline void schedule(void) {}
static inline bool refcount_inc_not_zero(int *ref) { return false; }

void io_cancel_defer_files(struct io_ring_ctx *ctx, struct files_struct *files);
void io_wq_cancel_cb(struct io_wq *wq, bool (*match)(struct io_wq_work *, void *), void *data, bool cancel_all);
bool io_wq_files_match(struct io_wq_work *work, void *data);
void io_attempt_cancel(struct io_ring_ctx *ctx, struct io_kiocb *req);
void io_put_req(struct io_kiocb *req);
void io_run_task_work(void);