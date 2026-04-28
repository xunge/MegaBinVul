#include <sys/types.h>
#include <unistd.h>

struct mutex {
    int dummy;
};

struct inode {
    struct mutex i_mutex;
};

struct file {
    struct {
        struct dentry *dentry;
    } f_path;
};

struct pipe_inode_info {
    struct inode *inode;
};

struct dentry {
    struct inode *d_inode;
    struct {
        unsigned int len;
        const char *name;
    } d_name;
};

struct buffer_head {
};

#define I_MUTEX_PARENT 0
#define I_MUTEX_CHILD 0

extern int ocfs2_rw_lock(struct inode *inode, int write);
extern void ocfs2_rw_unlock(struct inode *inode, int write);
extern int ocfs2_prepare_inode_for_write(struct dentry *dentry, loff_t *ppos, size_t count, int append, struct buffer_head **bh);
extern ssize_t generic_file_splice_write_nolock(struct pipe_inode_info *pipe, struct file *out, loff_t *ppos, size_t len, unsigned int flags);
extern void inode_double_lock(struct inode *inode1, struct inode *inode2);
extern void inode_double_unlock(struct inode *inode1, struct inode *inode2);
extern void mlog_entry(const char *fmt, ...);
extern void mlog_errno(int err);
extern void mlog_exit(int ret);
extern void mutex_lock_nested(struct mutex *lock, int subclass);
extern void mutex_unlock(struct mutex *lock);