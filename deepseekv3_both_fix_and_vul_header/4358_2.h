#include <sys/types.h>
#include <errno.h>

struct kiocb {
    struct file *ki_filp;
};

struct iov_iter;

struct fuse_copy_state {
    int dummy;
};

struct fuse_dev {
    void *fc;
};

struct file;

ssize_t fuse_get_dev(struct file *file);
int iter_is_iovec(struct iov_iter *to);
void fuse_copy_init(struct fuse_copy_state *cs, int arg, struct iov_iter *to);
ssize_t fuse_dev_do_read(void *fc, struct file *file, struct fuse_copy_state *cs, size_t count);
size_t iov_iter_count(struct iov_iter *to);