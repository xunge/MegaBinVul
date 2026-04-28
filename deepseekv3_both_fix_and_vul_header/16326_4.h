#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>

struct task_struct {
    struct io_uring_task *io_uring;
};

struct io_kiocb {
    struct task_struct *task;
    struct io_ring_ctx *ctx;
};

struct io_uring_task {
    _Atomic long req_complete;
    bool in_idle;
    struct {
        int dummy;
    } wait;
};

struct io_ring_ctx {
    _Atomic long fallback_req;
    _Atomic int refs;
};

extern struct kmem_cache *req_cachep;
extern void put_task_struct(struct task_struct *);
extern bool io_is_fallback_req(struct io_kiocb *);
extern void kmem_cache_free(struct kmem_cache *, void *);
extern void clear_bit_unlock(int, unsigned long *);
extern void percpu_ref_put(_Atomic int *);
#define likely(x) __builtin_expect(!!(x), 1)
#define atomic_long_inc(ptr) ((*(ptr))++)
#define wake_up(ptr) (void)(ptr)