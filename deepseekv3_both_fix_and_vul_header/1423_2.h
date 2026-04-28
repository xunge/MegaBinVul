#include <stddef.h>
#include <stdbool.h>
#include <sys/types.h>

#define UIO_FASTIOV 8
#define READ 0
#define IOCB_NOWAIT (1 << 1)
#define IOCB_WAITQ (1 << 2)
#define IO_URING_F_NONBLOCK (1 << 0)
#define REQ_F_REISSUE (1 << 0)
#define REQ_F_NOWAIT (1 << 1)
#define REQ_F_ISREG (1 << 2)
#define IORING_SETUP_IOPOLL (1 << 0)
#define EAGAIN 11
#define EIOCBQUEUED 12

struct iovec {
    void *iov_base;
    size_t iov_len;
};

struct kiocb {
    unsigned int ki_flags;
};

struct iov_iter {
    size_t count;
    size_t truncated;
};

struct io_uring_ctx {
    unsigned int flags;
};

struct io_async_rw {
    struct iov_iter iter;
    size_t bytes_done;
};

struct io_kiocb {
    union {
        struct {
            struct kiocb kiocb;
        } rw;
    };
    struct file *file;
    struct io_uring_ctx *ctx;
    struct io_async_rw *async_data;
    unsigned int flags;
    ssize_t result;
};

static inline int unlikely(int x) { return x; }

void kfree(void *ptr);
int io_import_iovec(int, struct io_kiocb *, struct iovec **, struct iov_iter *, bool);
size_t iov_iter_count(struct iov_iter *);
int io_file_supports_async(struct io_kiocb *, int);
int io_setup_async_rw(struct io_kiocb *, struct iovec *, struct iovec *, struct iov_iter *, bool);
int rw_verify_area(int, struct file *, loff_t, size_t);
loff_t io_kiocb_ppos(struct kiocb *);
int io_iter_do_read(struct io_kiocb *, struct iov_iter *);
void iov_iter_reexpand(struct iov_iter *, size_t);
void iov_iter_revert(struct iov_iter *, size_t);
int io_rw_should_retry(struct io_kiocb *);
void kiocb_done(struct kiocb *, ssize_t, unsigned int);