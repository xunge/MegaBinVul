#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

typedef int fmode_t;

struct path {
    struct dentry *dentry;
};

struct dentry {
    struct inode *d_inode;
};

struct inode {
    unsigned long i_ino;
    void *i_mount;
};

struct file {
    struct path f_path;
    fmode_t f_mode;
    int f_flags;
};

struct xfs_inode {
    void *i_mount;
    unsigned long i_ino;
};

struct xfs_swapext {
    int sx_fdtarget;
    int sx_fdtmp;
};

typedef struct xfs_inode xfs_inode_t;
typedef struct xfs_swapext xfs_swapext_t;

#define XFS_ERROR(err) (err)
#define EINVAL 22
#define EBADF 9
#define EIO 5
#define FMODE_READ 0x1
#define FMODE_WRITE 0x2
#define IS_SWAPFILE(inode) (0)
#define XFS_FORCED_SHUTDOWN(mount) (0)
#define XFS_I(inode) ((xfs_inode_t *)(inode))

extern struct file *fget(int fd);
extern void fput(struct file *file);
extern int xfs_swap_extents(xfs_inode_t *ip, xfs_inode_t *tip, xfs_swapext_t *sxp);