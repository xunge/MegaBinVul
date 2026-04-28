#include <stddef.h>

struct callback_head {
    struct callback_head *next;
    void (*func)(struct callback_head *);
};

struct io_kiocb {
    struct callback_head task_work;
    struct io_ring_ctx *ctx;
};

struct io_ring_ctx {
    int refs;  // Simplified replacement for percpu_ref
};

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

static void __io_req_task_submit(struct io_kiocb *req);
static void percpu_ref_put(int *ref);