#include <stddef.h>
#include <sys/types.h>
#include <stdbool.h>
#include <stdio.h>

struct io_kiocb {
    int opcode;
};

struct io_uring_sqe;

enum {
    IORING_OP_NOP,
    IORING_OP_READV,
    IORING_OP_READ_FIXED,
    IORING_OP_WRITEV,
    IORING_OP_WRITE_FIXED,
    IORING_OP_POLL_ADD,
    IORING_OP_POLL_REMOVE,
    IORING_OP_FSYNC,
    IORING_OP_SYNC_FILE_RANGE,
    IORING_OP_SENDMSG,
    IORING_OP_RECVMSG,
    IORING_OP_CONNECT,
    IORING_OP_TIMEOUT,
    IORING_OP_TIMEOUT_REMOVE,
    IORING_OP_ASYNC_CANCEL,
    IORING_OP_LINK_TIMEOUT,
    IORING_OP_ACCEPT,
    IORING_OP_FALLOCATE,
    IORING_OP_OPENAT,
    IORING_OP_CLOSE
};

#define EINVAL 22
#define KERN_WARNING "warning"
#define printk_once(...) printf(__VA_ARGS__)

ssize_t io_read_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe, bool flag);
ssize_t io_write_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe, bool flag);
ssize_t io_poll_add_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
ssize_t io_poll_remove_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
ssize_t io_prep_fsync(struct io_kiocb *req, const struct io_uring_sqe *sqe);
ssize_t io_prep_sfr(struct io_kiocb *req, const struct io_uring_sqe *sqe);
ssize_t io_sendmsg_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
ssize_t io_recvmsg_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
ssize_t io_connect_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
ssize_t io_timeout_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe, bool flag);
ssize_t io_timeout_remove_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
ssize_t io_async_cancel_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
ssize_t io_accept_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
ssize_t io_fallocate_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
ssize_t io_openat_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
ssize_t io_close_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);