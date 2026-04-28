#include <pthread.h>
#include <stddef.h>

#define LOOKUP_RCU 0x0001
#define LOOKUP_PARENT 0x0002
#define LOOKUP_FOLLOW 0x0004
#define LAST_NORM 0
#define ECHILD 10
#define ENOMEM 12
#define ENOENT 2

struct qstr {
    const char *name;
    unsigned int len;
    unsigned int hash;
};

struct dentry {
    struct inode *d_inode;
    int d_flags;
};

struct inode {
    pthread_mutex_t i_mutex;
};

struct path {
    void *mnt;
    struct dentry *dentry;
};

struct nameidata {
    struct path path;
    unsigned flags;
    int last_type;
    struct qstr last;
};

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))
#define d_is_negative(x) (!(x)->d_inode)
#define unlikely(x) (x)
#define dget(x) (x)
#define dput(x) 
#define mntget(x) (x)
#define d_lookup(x, y) NULL
#define d_alloc(x, y) NULL
#define lookup_real(x, y, z) NULL
#define should_follow_link(x, y) 0
#define follow_mount(x)
#define terminate_walk(x)
#define mutex_lock(x) pthread_mutex_lock(x)
#define mutex_unlock(x) pthread_mutex_unlock(x)
#define unlazy_walk(x, y) 0
#define handle_dots(x, y) 0