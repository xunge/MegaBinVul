#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

struct callback_head {
    struct callback_head *next;
    void (*func)(struct callback_head *);
};

struct io_kiocb {
    struct callback_head task_work;
    struct io_ring_ctx *ctx;
    uint32_t refs;
};

struct io_ring_ctx {
    uint32_t refs;
};

static inline bool io_resubmit_prep(struct io_kiocb *req, int err) { return false; }
static int io_sq_thread_acquire_mm(struct io_ring_ctx *ctx, struct io_kiocb *req) { return 0; }
static void io_queue_async_work(struct io_kiocb *req) {}
static void refcount_inc(uint32_t *ref) { (*ref)++; }
static void percpu_ref_put(uint32_t *ref) { (*ref)--; }

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))