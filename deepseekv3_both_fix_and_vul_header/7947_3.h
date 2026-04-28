#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define O_LARGEFILE 0100000
#define EIO 5
#define EMEDIUMTYPE 124
#define KERN_ERR ""
#define IS_ERR(x) (0)
#define PTR_ERR(x) (0)
#define IS_RDONLY(x) (0)
#define d_inode(x) (NULL)

struct file {
    struct file_operations *f_op;
};

struct file_operations {
    void *mmap;
};

struct dentry;
struct vfsmount;
struct cred;

struct path {
    struct dentry *dentry;
    struct vfsmount *mnt;
};

struct list_head {
    struct list_head *next, *prev;
};

struct ecryptfs_open_req {
    int done;
    struct file **lower_file;
    struct path path;
    struct list_head kthread_ctl_list;
};

struct ecryptfs_kthread_ctl {
    pthread_mutex_t mux;
    struct list_head req_list;
    pthread_cond_t wait;
    unsigned int flags;
};

#define ECRYPTFS_KTHREAD_ZOMBIE 0x00000001

extern struct ecryptfs_kthread_ctl ecryptfs_kthread_ctl;

void init_completion(int *done) {}
struct file *dentry_open(struct path *path, int flags, const struct cred *cred) { return NULL; }
void fput(struct file *file) {}
void mutex_lock(pthread_mutex_t *mux) {}
void mutex_unlock(pthread_mutex_t *mux) {}
void list_add_tail(struct list_head *new, struct list_head *head) {}
void wake_up(pthread_cond_t *wait) {}
void wait_for_completion(int *done) {}
int printk(const char *fmt, ...) { return 0; }