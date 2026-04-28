#include <sys/types.h>
#include <stddef.h>
#include <linux/fs.h>
#include <linux/fuse.h>
#include <linux/uio.h>
#include <linux/errno.h>

struct kiocb {
    struct file *ki_filp;
};

struct file {
    void *private_data;
};

struct inode;

struct fuse_file {
    unsigned int open_flags;
};

struct iov_iter;

ssize_t fuse_dax_read_iter(struct kiocb *iocb, struct iov_iter *to);
ssize_t fuse_cache_read_iter(struct kiocb *iocb, struct iov_iter *to);
ssize_t fuse_direct_read_iter(struct kiocb *iocb, struct iov_iter *to);

static inline struct inode *file_inode(const struct file *file) { return NULL; }
static inline int is_bad_inode(const struct inode *inode) { return 0; }