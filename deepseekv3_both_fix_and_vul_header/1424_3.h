#include <stddef.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/uio.h>

typedef long loff_t;

struct kiocb {
    unsigned int ki_flags;
};

struct iov_iter {
    size_t count;
    size_t truncated;
};

struct inode {
    struct super_block *i_sb;
};

struct super_block {
    // minimal definition
};

struct file {
    struct inode *f_inode;
    struct file_operations *f_op;
};

struct file_operations {
    ssize_t (*write_iter)(struct kiocb *, struct iov_iter *);
    ssize_t (*write)(struct file *, const char *, size_t, loff_t *);
};

struct io_ring_ctx {
    unsigned int flags;
};

struct io_async_rw {
    struct iov_iter iter;
};

struct io_kiocb {
    struct {
        struct kiocb kiocb;
    } rw;
    unsigned int flags;
    void *async_data;
    struct file *file;
    struct io_ring_ctx *ctx;
    ssize_t result;
};

#define UIO_FASTIOV 8
#define WRITE 1
#define IO_URING_F_NONBLOCK 1
#define IOCB_NOWAIT 1
#define IOCB_DIRECT 2
#define IOCB_WRITE 4
#define REQ_F_ISREG 1
#define REQ_F_REISSUE 2
#define REQ_F_NOWAIT 4
#define SB_FREEZE_WRITE 1
#define IORING_SETUP_IOPOLL (1U << 0)
#define EINVAL 22
#define EAGAIN 11
#define EOPNOTSUPP 95

static inline int unlikely(int x) { return x; }

void kfree(void *ptr);
void sb_start_write(struct super_block *sb);
void __sb_writers_release(struct super_block *sb, int flag);
ssize_t io_import_iovec(int rw, struct io_kiocb *req, struct iovec **iovec, struct iov_iter *iter, bool compat);
size_t iov_iter_count(struct iov_iter *i);
void iov_iter_reexpand(struct iov_iter *i, size_t count);
void iov_iter_revert(struct iov_iter *i, size_t count);
ssize_t call_write_iter(struct file *file, struct kiocb *kiocb, struct iov_iter *iter);
ssize_t loop_rw_iter(int rw, struct io_kiocb *req, struct iov_iter *iter);
int io_setup_async_rw(struct io_kiocb *req, struct iovec *iovec, struct iovec *inline_vecs, struct iov_iter *iter, bool has_ref);
void kiocb_done(struct kiocb *kiocb, ssize_t ret, unsigned int issue_flags);
int rw_verify_area(int rw, struct file *file, const loff_t *ppos, size_t count);
bool io_file_supports_async(struct io_kiocb *req, int rw);
loff_t io_kiocb_ppos(struct kiocb *kiocb);
struct inode *file_inode(struct file *file);