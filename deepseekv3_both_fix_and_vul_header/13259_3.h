#include <stdbool.h>
#include <stddef.h>

struct io_op_def {
    bool buffer_select;
    bool plug;
    bool needs_file;
};

struct io_submit_state {
    bool plug_started;
    int ios_left;
    void *plug;
};

struct io_ring_ctx {
    struct io_submit_state submit_state;
    bool drain_active;
    void *uring_lock;
    void *personalities;
};

struct io_kiocb {
    int opcode;
    unsigned int flags;
    unsigned long user_data;
    void *file;
    void *fixed_rsrc_refs;
    void *task;
    void *creds;
};

struct io_uring_sqe {
    int opcode;
    unsigned int flags;
    unsigned long user_data;
    int fd;
    int personality;
};

extern struct io_op_def io_op_defs[];
extern void *current;

#define READ_ONCE(x) (x)
#define __must_hold(x)
#define unlikely(x) (x)

#define SQE_VALID_FLAGS 0
#define IORING_OP_LAST 0
#define IOSQE_BUFFER_SELECT 0
#define IOSQE_IO_DRAIN 0
#define IOSQE_FIXED_FILE 0
#define IO_URING_F_NONBLOCK 0
#define REQ_F_CREDS 0

#define EINVAL 1
#define EACCES 1
#define EOPNOTSUPP 1
#define EBADF 1

extern bool io_check_restriction(struct io_ring_ctx *ctx, struct io_kiocb *req, unsigned int flags);
extern void *io_file_get(struct io_ring_ctx *ctx, struct io_kiocb *req, int fd, bool fixed, unsigned int flags);
extern void *xa_load(void *xa, int index);
extern void get_cred(void *cred);
extern void blk_start_plug(void *plug);