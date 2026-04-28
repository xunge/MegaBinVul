#include <stdbool.h>
#include <stddef.h>
#include <errno.h>

struct callback_head {
    struct callback_head *next;
    void (*func)(struct callback_head *head);
};

struct hlist_node {
    struct hlist_node *next;
    struct hlist_node **pprev;
};

struct io_poll {
    bool canceled;
};

struct percpu_ref {
    unsigned long count;
};

struct io_ring_ctx {
    void *completion_lock;
    struct percpu_ref refs;
};

struct async_poll {
    struct io_poll poll;
    struct io_poll *double_poll;
};

struct io_kiocb {
    struct callback_head task_work;
    struct async_poll *apoll;
    struct io_ring_ctx *ctx;
    unsigned int opcode;
    unsigned long user_data;
    struct hlist_node hash_node;
};

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define READ_ONCE(x) (x)

static inline bool io_poll_rewait(struct io_kiocb *req, struct io_poll *poll) { return false; }
static inline void __io_req_task_submit(struct io_kiocb *req) {}
static inline void __io_req_task_cancel(struct io_kiocb *req, int error) {}
static inline void io_poll_remove_double(struct io_kiocb *req, struct io_poll *double_poll) {}
static inline void spin_unlock_irq(void *lock) {}
static inline void percpu_ref_put(struct percpu_ref *ref) {}
static inline bool hash_hashed(struct hlist_node *node) { return false; }
static inline void hash_del(struct hlist_node *node) {}
static inline void trace_io_uring_task_run(void *ctx, unsigned int opcode, unsigned long user_data) {}
static inline void kfree(void *ptr) {}