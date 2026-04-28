#include <stddef.h>
#include <stdatomic.h>

struct io_ring_ctx;
struct io_uring {
    long req_complete;
};

struct task_struct {
    struct io_uring *io_uring;
};

struct req_batch {
    void *to_free;
    struct task_struct *task;
    int task_refs;
};

extern void __io_req_free_batch_flush(struct io_ring_ctx *ctx, struct req_batch *rb);
extern void put_task_struct_many(struct task_struct *t, int count);
extern void atomic_long_add(long i, long *v);