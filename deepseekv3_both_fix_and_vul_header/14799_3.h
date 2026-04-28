#include <stdint.h>
#include <errno.h>
#include <stddef.h>
#include <stdbool.h>

struct file;
struct eventfd_ctx;

struct mutex {
    int dummy;
};

struct vhost_virtqueue {
    struct mutex mutex;
    void *private_data;
    void *log_base;
    struct eventfd_ctx *log_ctx;
};

struct vhost_dev {
    unsigned int nvqs;
    struct vhost_virtqueue **vqs;
    struct file *log_file;
    struct eventfd_ctx *log_ctx;
};

#define __user
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define PTR_ERR(x) ((long)(x))
#define EFAULT 14
#define ENOIOCTLCMD 515

typedef uint64_t u64;

#define VHOST_SET_OWNER 0x01
#define VHOST_SET_MEM_TABLE 0x02
#define VHOST_SET_LOG_BASE 0x03
#define VHOST_SET_LOG_FD 0x04

extern long vhost_dev_set_owner(struct vhost_dev *d);
extern long vhost_dev_check_owner(struct vhost_dev *d);
extern long vhost_set_memory(struct vhost_dev *d, void *argp);
extern bool vq_log_access_ok(struct vhost_virtqueue *vq, void *base);
extern struct file *eventfd_fget(int fd);
extern struct eventfd_ctx *eventfd_ctx_fileget(struct file *file);
extern void eventfd_ctx_put(struct eventfd_ctx *ctx);
extern void fput(struct file *file);
extern int get_user(int, int *);
extern int copy_from_user(void *, const void *, unsigned long);
extern void mutex_lock(struct mutex *);
extern void mutex_unlock(struct mutex *);