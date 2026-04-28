#include <stdatomic.h>
#include <stddef.h>
#include <time.h>

struct path {
    struct vfsmount *mnt;
    struct dentry *dentry;
};

struct ns_common {
    atomic_long stashed;
    unsigned long inum;
    struct {
        void (*put)(struct ns_common *);
    } *ops;
};

struct qstr {
    const char *name;
};

struct vfsmount {
    struct super_block *mnt_sb;
};

struct super_block;

struct dentry {
    struct {
        int count;
    } d_lockref;
    unsigned long d_flags;
    void *d_fsdata;
};

struct inode {
    unsigned long i_ino;
    time_t i_mtime;
    time_t i_atime;
    time_t i_ctime;
    unsigned int i_flags;
    unsigned int i_mode;
    struct file_operations *i_fop;
    void *i_private;
};

struct file_operations {
};

struct vfsmount *nsfs_mnt;
struct file_operations ns_file_operations;

#define S_IMMUTABLE 0
#define S_IFREG 0
#define S_IRUGO 0
#define DCACHE_RCUACCESS 0
#define ENOMEM 1
#define EAGAIN 2

#define ERR_PTR(x) ((void *)(long)(x))
#define atomic_long_read(x) 0
#define atomic_long_cmpxchg(x, y, z) 0
#define lockref_get_not_dead(x) 1
#define rcu_read_lock()
#define rcu_read_unlock()
#define mntget(x) (x)
#define new_inode_pseudo(x) NULL
#define current_time(x) time(NULL)
#define d_alloc_pseudo(x, y) NULL
#define d_instantiate(x, y)
#define d_delete(x)
#define dput(x)
#define iput(x)
#define cpu_relax()