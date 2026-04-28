#include <stddef.h>

struct callback_head {
    struct callback_head *next;
    void (*func)(struct callback_head *);
};

struct io_msg {
    struct callback_head tw;
    unsigned long user_data;
    int len;
};

struct io_kiocb {
    struct file *file;
};

struct io_ring_ctx {
    unsigned int flags;
    void *uring_lock;
};

struct file {
    void *private_data;
};

struct task_struct {
    unsigned int flags;
};

#define PF_EXITING 0x00000004
#define EOWNERDEAD 130
#define EOVERFLOW 75
#define IORING_SETUP_IOPOLL (1U << 0)

extern struct task_struct *current;

static inline void mutex_lock(void *lock) {}
static inline void mutex_unlock(void *lock) {}
static inline int io_post_aux_cqe(struct io_ring_ctx *ctx, unsigned long user_data, int len, int res) { return 0; }
static inline void req_set_fail(struct io_kiocb *req) {}
static inline void io_req_queue_tw_complete(struct io_kiocb *req, int ret) {}
static inline struct io_kiocb *cmd_to_io_kiocb(struct io_msg *msg) { return (struct io_kiocb *)0; }

#define container_of(ptr, type, member) ({ \
    const typeof(((type *)0)->member) *__mptr = (ptr); \
    (type *)((char *)__mptr - offsetof(type, member)); })