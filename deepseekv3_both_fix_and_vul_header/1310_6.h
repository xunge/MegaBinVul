#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

struct file {
    unsigned int f_flags;
    unsigned int f_mode;
    loff_t f_pos;
};

struct inode {
    unsigned long i_flags;
    unsigned short i_mode;
    struct super_block *i_sb;
};

struct xfs_inode {
    loff_t i_size;
};

struct iattr {
    unsigned int ia_valid;
    loff_t ia_size;
};

struct super_block {
    loff_t s_maxbytes;
};

struct user_namespace;
struct dentry;

typedef struct xfs_flock64_t {
    int64_t l_start;
    int64_t l_len;
    int32_t l_whence;
    int32_t l_pid;
} xfs_flock64_t;

enum xfs_prealloc_flags {
    XFS_PREALLOC_CLEAR,
    XFS_PREALLOC_SYNC,
    XFS_PREALLOC_INVISIBLE
};

#define XFS_IOLOCK_EXCL    0x01
#define XFS_MMAPLOCK_EXCL  0x02
#define XFS_ISIZE(ip)      ((ip)->i_size)
#define BREAK_UNMAP        1
#define XFS_BMAPI_PREALLOC 0x0010

#define S_IMMUTABLE        0x00000010
#define S_APPEND           0x00000020
#define FMODE_WRITE        0x2
#define FMODE_NOCMTIME     0x800
#define ATTR_SIZE          0x0002

#define EPERM              1
#define EBADF              9
#define EINVAL             22
#define EOPNOTSUPP         95

typedef unsigned int uint;
typedef int64_t loff_t;

#define XFS_I(inode) ((struct xfs_inode *)(inode))

int mnt_want_write_file(struct file *);
void mnt_drop_write_file(struct file *);
void xfs_ilock(struct xfs_inode *, uint);
void xfs_iunlock(struct xfs_inode *, uint);
int xfs_break_layouts(struct inode *, uint *, int);
void inode_dio_wait(struct inode *);
int xfs_alloc_file_space(struct xfs_inode *, loff_t, loff_t, int);
int xfs_vn_setattr_size(struct user_namespace *, struct dentry *, struct iattr *);
int xfs_update_prealloc_flags(struct xfs_inode *, enum xfs_prealloc_flags);
bool xfs_is_always_cow_inode(struct xfs_inode *);
struct inode *file_inode(struct file *);
struct user_namespace *file_mnt_user_ns(struct file *);
struct dentry *file_dentry(struct file *);