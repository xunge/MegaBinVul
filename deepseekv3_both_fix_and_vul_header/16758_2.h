#include <errno.h>
#include <sys/types.h>

struct address_space {
    struct inode *host;
};

struct file {
    struct address_space *f_mapping;
};

struct inode;

struct fuse_conn {
    int no_fsyncdir;
};

#define EIO 5
#define ENOSYS 38
#define FUSE_FSYNCDIR 1

static struct fuse_conn *get_fuse_conn(struct inode *inode) { return 0; }
static int is_bad_inode(struct inode *inode) { return 0; }
static void inode_lock(struct inode *inode) {}
static void inode_unlock(struct inode *inode) {}
static int fuse_fsync_common(struct file *file, loff_t start, loff_t end, int datasync, int flags) { return 0; }