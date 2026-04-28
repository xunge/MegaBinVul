#include <sys/types.h>
#include <linux/fs.h>
#include <linux/uio.h>
#include <linux/errno.h>
#include <linux/fuse.h>

struct kiocb {
    struct file *ki_filp;
};

struct iov_iter;

struct fuse_copy_state {
    // minimal definition needed
    int dummy;
};

struct fuse_dev {
    struct fuse_conn *fc;
};

struct fuse_conn;

ssize_t fuse_get_dev(struct file *filp);
int iter_is_iovec(struct iov_iter *iter);
void fuse_copy_init(struct fuse_copy_state *cs, int flags, struct iov_iter *iter);
ssize_t fuse_dev_do_write(struct fuse_conn *fc, struct fuse_copy_state *cs, size_t count);
size_t iov_iter_count(struct iov_iter *iter);