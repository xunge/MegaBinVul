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
    struct inode *f_inode;
};

struct inode;

struct fuse_file {
    unsigned int open_flags;
};

struct iov_iter;

#define FUSE_IS_DAX(inode) (0)

static inline struct inode *file_inode(struct file *file) { return file->f_inode; }
static inline int is_bad_inode(struct inode *inode) { return 0; }

ssize_t fuse_dax_write_iter(struct kiocb *iocb, struct iov_iter *from);
ssize_t fuse_cache_write_iter(struct kiocb *iocb, struct iov_iter *from);
ssize_t fuse_direct_write_iter(struct kiocb *iocb, struct iov_iter *from);