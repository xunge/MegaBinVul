#include <stdbool.h>
#include <stddef.h>

#define READ_ONCE(x) (x)
#define __must_hold(x)
#define unlikely(x) (x)

#define SQE_VALID_FLAGS 0
#define IORING_OP_LAST 0
#define IOSQE_BUFFER_SELECT 0
#define IOSQE_IO_DRAIN 0
#define IOSQE_FIXED_FILE 0
#define REQ_F_CREDS 0
#define EINVAL 1
#define EACCES 1
#define EOPNOTSUPP 1
#define EBADF 1

struct file {
    int dummy;
};

struct task_struct {
    int dummy;
};

struct cred {
    int dummy;
};

struct blk_plug {
    int dummy;
};

struct io_submit_state {
    bool plug_started;
    int ios_left;
    struct blk_plug plug;
};

struct io_ring_ctx {
    int uring_lock;
    bool drain_active;
    struct io_submit_state submit_state;
    void *personalities;
};

struct io_kiocb {
    int opcode;
    unsigned int flags;
    unsigned long long user_data;
    struct file *file;
    void *fixed_rsrc_refs;
    struct task_struct *task;
    const struct cred *creds;
};

struct io_uring_sqe {
    int opcode;
    unsigned int flags;
    unsigned long long user_data;
    int personality;
    int fd;
};

struct io_op_def {
    bool buffer_select;
    bool plug;
    bool needs_file;
};

extern struct io_op_def io_op_defs[];
extern struct task_struct *current;

static inline void *xa_load(void *xa, int index) { return NULL; }
static inline void get_cred(const struct cred *cred) {}
static inline void blk_start_plug(struct blk_plug *plug) {}
static inline int io_check_restriction(struct io_ring_ctx *ctx, struct io_kiocb *req, unsigned int flags) { return 1; }
static inline struct file *io_file_get(struct io_ring_ctx *ctx, struct io_kiocb *req, int fd, unsigned int flags, ...) { return NULL; }