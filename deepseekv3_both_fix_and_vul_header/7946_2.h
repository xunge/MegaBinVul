#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

struct file {
    struct file_operations *f_op;
};

struct file_operations {
    void *mmap;
};

struct dentry {
    void *d_inode;
};

struct vfsmount {};
struct cred {};
struct path {
    struct dentry *dentry;
    struct vfsmount *mnt;
};

struct completion {
    int dummy;
};

struct list_head {
    struct list_head *next, *prev;
};

struct mutex {
    int dummy;
};

struct wait_queue_head {
    int dummy;
};

struct ecryptfs_open_req {
    struct completion done;
    struct file **lower_file;
    struct path path;
    struct list_head kthread_ctl_list;
};

struct ecryptfs_kthread_ctl {
    struct mutex mux;
    struct list_head req_list;
    struct wait_queue_head wait;
    unsigned int flags;
};

#define ECRYPTFS_KTHREAD_ZOMBIE 0x00000001
#define O_LARGEFILE 0100000
#define IS_RDONLY(inode) 1
#define IS_ERR(ptr) 0
#define PTR_ERR(ptr) (-1)
#define KERN_ERR ""
#define printk(fmt, ...) printf(fmt, ##__VA_ARGS__)

static inline void init_completion(struct completion *c) { c->dummy = 0; }
static inline struct file *dentry_open(struct path *path, int flags, const struct cred *cred) { return NULL; }
static inline void mutex_lock(struct mutex *lock) {}
static inline void mutex_unlock(struct mutex *lock) {}
static inline void list_add_tail(struct list_head *new, struct list_head *head) {}
static inline void wake_up(struct wait_queue_head *wq) {}
static inline void wait_for_completion(struct completion *c) {}
static inline void fput(struct file *file) {}

struct ecryptfs_kthread_ctl ecryptfs_kthread_ctl;