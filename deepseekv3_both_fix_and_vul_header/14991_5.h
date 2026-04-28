#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#define AT_FDCWD -100
#define AT_SYMLINK_NOFOLLOW 0x100
#define UTIME_NOW ((1l << 30) - 1l)
#define UTIME_OMIT ((1l << 30) - 2l)

struct path {
    void *dentry;
};

struct nameidata {
    struct path path;
};

struct dentry {
    void *d_inode;
};

struct inode {
    void *i_mutex;
};

struct iattr {
    unsigned int ia_valid;
    struct timespec ia_atime;
    struct timespec ia_mtime;
    struct timespec ia_ctime;
};

struct file {
    struct path f_path;
    int f_mode;
};

#define IS_RDONLY(inode) 0
#define IS_APPEND(inode) 0
#define IS_IMMUTABLE(inode) 0
#define MAY_WRITE 2
#define LOOKUP_FOLLOW 1

#define ATTR_ATIME 1
#define ATTR_MTIME 2
#define ATTR_CTIME 4
#define ATTR_ATIME_SET 8
#define ATTR_MTIME_SET 16

#define FMODE_WRITE 2

#define __user

static inline int nsec_valid(long nsec) { return 1; }
static inline int __user_walk_fd(int dfd, char *filename, int flags, struct nameidata *nd) { return 0; }
static inline int is_owner_or_cap(void *inode) { return 1; }
static inline int vfs_permission(struct nameidata *nd, int mask) { return 0; }
static inline int notify_change(void *dentry, struct iattr *attr) { return 0; }
static inline struct file *fget(int fd) { return NULL; }
static inline void fput(struct file *file) {}
static inline void path_put(struct path *path) {}
static inline void mutex_lock(void *lock) {}
static inline void mutex_unlock(void *lock) {}