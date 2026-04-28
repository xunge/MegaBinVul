#include <linux/types.h>
#include <linux/errno.h>
#include <linux/io_uring.h>
#include <stddef.h>

struct io_kiocb;
struct file_operations;
extern const struct file_operations io_uring_fops;

#define unlikely(x) (x)
#define READ_ONCE(x) (x)

#define REQ_F_FIXED_FILE (1 << 0)
#define IO_WQ_WORK_NO_CANCEL (1 << 0)

struct io_wq_work {
    unsigned int flags;
};

struct file {
    const struct file_operations *f_op;
};

struct io_kiocb {
    struct io_uring_ctx *ctx;
    struct file *file;
    unsigned int flags;
    struct io_wq_work work;
    struct {
        int fd;
        struct file *put_file;
    } close;
};

struct io_uring_ctx {
    unsigned int flags;
    int ring_fd;
};

extern void io_req_init_async(struct io_kiocb *req);