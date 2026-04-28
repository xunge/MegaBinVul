#include <stddef.h>
#include <linux/types.h>
#include <linux/errno.h>
#include <linux/io_uring.h>

struct io_kiocb;
struct io_uring_sqe;

#define unlikely(x) __builtin_expect(!!(x), 0)
#define READ_ONCE(x) (*(volatile typeof(x) *)&(x))

#define IORING_SETUP_IOPOLL (1U << 0)
#define REQ_F_FIXED_FILE (1U << 0)

struct file {
    const struct file_operations *f_op;
};

struct io_wq_work {
    unsigned int flags;
};

struct io_kiocb {
    struct io_uring_ctx *ctx;
    unsigned int flags;
    struct file *file;
    struct {
        int fd;
        struct file *put_file;
    } close;
};

struct io_uring_ctx {
    unsigned int flags;
};

extern const struct file_operations io_uring_fops;

void io_req_init_async(struct io_kiocb *req);