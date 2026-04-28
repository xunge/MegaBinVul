#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>

typedef long atomic_long_t;

struct task_struct {
    struct io_uring *io_uring;
};

struct io_uring {
    atomic_long_t req_complete;
};

struct io_uring_ctx;

struct req_batch {
    struct task_struct *task;
    unsigned int task_refs;
    struct io_kiocb *reqs[0];
    unsigned int to_free;
};

struct io_kiocb {
    unsigned int flags;
    struct task_struct *task;
    struct io_uring_ctx *ctx;
};

#define REQ_F_LINK_HEAD (1U << 0)
#define unlikely(x) (x)
#define WARN_ON_ONCE(x) (x)
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

static void atomic_long_add(long i, atomic_long_t *v) { *v += i; }
static void io_free_req(struct io_kiocb *req) {}
static void io_queue_next(struct io_kiocb *req) {}
static bool io_is_fallback_req(struct io_kiocb *req) { return false; }
static bool io_dismantle_req(struct io_kiocb *req) { return false; }
static void __io_req_free_batch_flush(struct io_uring_ctx *ctx, struct req_batch *rb) {}
static void put_task_struct_many(struct task_struct *task, unsigned int count) {}