#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stddef.h>

struct nameidata {
    struct dentry *dentry;
    struct vfsmount *mnt;
};

struct dentry {
    struct inode *d_inode;
};

struct inode {
    unsigned short i_mode;
    unsigned long i_flags;
};

struct vfsmount {
    unsigned long mnt_flags;
};

#define MAY_WRITE 0x00000002
#define FMODE_WRITE 0x00000001
#define MNT_NODEV 0x00000004
#define ATTR_MTIME 0x00000002
#define ATTR_CTIME 0x00000004
#define ATTR_OPEN 0x00000020
#define O_NOATIME 01000000

#define IS_RDONLY(inode) ((inode)->i_flags & 1)
#define IS_APPEND(inode) ((inode)->i_flags & 2)

static inline int vfs_permission(struct nameidata *nd, int acc_mode) { return 0; }
static inline int is_owner_or_cap(struct inode *inode) { return 1; }
static inline int break_lease(struct inode *inode, int flag) { return 0; }
static inline int get_write_access(struct inode *inode) { return 0; }
static inline void put_write_access(struct inode *inode) {}
static inline int locks_verify_locked(struct inode *inode) { return 0; }
static inline void DQUOT_INIT(struct inode *inode) {}
static inline int do_truncate(struct dentry *dentry, int length, int flags, void *data) { return 0; }