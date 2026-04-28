#include <stdbool.h>
#include <errno.h>
#include <pthread.h>

struct io_uring_sqe;
struct io_kiocb {
    struct io_ring_ctx *ctx;
    int opcode;
    int result;
};
struct io_ring_ctx {
    unsigned int flags;
    pthread_mutex_t uring_lock;
};

enum {
    IORING_OP_NOP,
    IORING_OP_READV,
    IORING_OP_READ_FIXED,
    IORING_OP_WRITEV,
    IORING_OP_WRITE_FIXED,
    IORING_OP_FSYNC,
    IORING_OP_POLL_ADD,
    IORING_OP_POLL_REMOVE,
    IORING_OP_SYNC_FILE_RANGE,
    IORING_OP_SENDMSG,
    IORING_OP_RECVMSG,
    IORING_OP_TIMEOUT,
    IORING_OP_TIMEOUT_REMOVE,
    IORING_OP_ACCEPT,
    IORING_OP_CONNECT,
    IORING_OP_ASYNC_CANCEL,
    IORING_OP_FALLOCATE,
    IORING_OP_OPENAT,
    IORING_OP_CLOSE
};

#define IORING_SETUP_IOPOLL (1 << 0)
#define EINVAL 22
#define EAGAIN 11

extern int io_nop(struct io_kiocb *req);
extern int io_read_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe, bool force_nonblock);
extern int io_read(struct io_kiocb *req, struct io_kiocb **nxt, bool force_nonblock);
extern int io_write_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe, bool force_nonblock);
extern int io_write(struct io_kiocb *req, struct io_kiocb **nxt, bool force_nonblock);
extern int io_prep_fsync(struct io_kiocb *req, const struct io_uring_sqe *sqe);
extern int io_fsync(struct io_kiocb *req, struct io_kiocb **nxt, bool force_nonblock);
extern int io_poll_add_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
extern int io_poll_add(struct io_kiocb *req, struct io_kiocb **nxt);
extern int io_poll_remove_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
extern int io_poll_remove(struct io_kiocb *req);
extern int io_prep_sfr(struct io_kiocb *req, const struct io_uring_sqe *sqe);
extern int io_sync_file_range(struct io_kiocb *req, struct io_kiocb **nxt, bool force_nonblock);
extern int io_sendmsg_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
extern int io_sendmsg(struct io_kiocb *req, struct io_kiocb **nxt, bool force_nonblock);
extern int io_recvmsg_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
extern int io_recvmsg(struct io_kiocb *req, struct io_kiocb **nxt, bool force_nonblock);
extern int io_timeout_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe, bool flag);
extern int io_timeout(struct io_kiocb *req);
extern int io_timeout_remove_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
extern int io_timeout_remove(struct io_kiocb *req);
extern int io_accept_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
extern int io_accept(struct io_kiocb *req, struct io_kiocb **nxt, bool force_nonblock);
extern int io_connect_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
extern int io_connect(struct io_kiocb *req, struct io_kiocb **nxt, bool force_nonblock);
extern int io_async_cancel_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
extern int io_async_cancel(struct io_kiocb *req, struct io_kiocb **nxt);
extern int io_fallocate_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
extern int io_fallocate(struct io_kiocb *req, struct io_kiocb **nxt, bool force_nonblock);
extern int io_openat_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
extern int io_openat(struct io_kiocb *req, struct io_kiocb **nxt, bool force_nonblock);
extern int io_close_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
extern int io_close(struct io_kiocb *req, struct io_kiocb **nxt, bool force_nonblock);
extern bool io_wq_current_is_worker(void);
extern void io_iopoll_req_issued(struct io_kiocb *req);