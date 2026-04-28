#include <stddef.h>

#define container_of(ptr, type, member) ({ \
    const typeof(((type *)0)->member) *__mptr = (ptr); \
    (type *)((char *)__mptr - offsetof(type, member)); })

struct callback_head {
    struct callback_head *next;
    void (*func)(struct callback_head *);
};

struct io_ring_ctx {
    int refs;
};

struct io_kiocb {
    struct callback_head task_work;
    struct io_ring_ctx *ctx;
};

static void io_poll_task_handler(struct io_kiocb *req, struct io_kiocb **nxt);
static void __io_req_task_submit(struct io_kiocb *req);
static void percpu_ref_put(int *refs);