#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>

#define READ_ONCE(x) (x)
#define unlikely(x) (x)

#define IORING_OP_LAST 32
#define SQE_VALID_FLAGS 0xffffffff
#define IOSQE_BUFFER_SELECT (1 << 0)
#define EINVAL 22
#define EFAULT 14
#define EOPNOTSUPP 95

struct task_struct {
    struct {
        atomic_long req_issue;
    } *io_uring;
};

struct io_uring_sqe {
    unsigned opcode;
    unsigned flags;
    unsigned user_data;
    unsigned personality;
    unsigned fd;
};

struct io_kiocb {
    unsigned opcode;
    unsigned user_data;
    void *io;
    void *file;
    struct io_ring_ctx *ctx;
    unsigned flags;
    atomic_int refs;
    struct task_struct *task;
    long result;
    struct {
        const void *creds;
    } work;
};

struct io_ring_ctx {
    struct {
        int dummy;
    } personality_idr;
};

struct io_submit_state {
};

struct io_op_def {
    bool buffer_select;
    bool needs_file;
};

extern struct io_op_def io_op_defs[];
extern struct task_struct *current;

static inline void refcount_set(atomic_int *r, int val) { atomic_store(r, val); }
static inline void get_task_struct(struct task_struct *t) {}
static inline void get_cred(const void *cred) {}
static inline void io_req_init_async(struct io_kiocb *req) {}
static inline int io_sq_thread_acquire_mm(struct io_ring_ctx *ctx, struct io_kiocb *req) { return 0; }
static inline int io_req_set_file(struct io_submit_state *state, struct io_kiocb *req, unsigned fd) { return 0; }
static inline void *idr_find(struct io_ring_ctx *ctx, int id) { return NULL; }
static inline void atomic_long_inc(atomic_long *v) { (*v)++; }