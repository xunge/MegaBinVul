#include <errno.h>
#include <stdint.h>
#include <sys/ioctl.h>

#define FUSE_DEV_IOC_CLONE 0
typedef uint32_t __u32;
#define __user

struct file;
struct fuse_conn;

struct fuse_dev {
    struct fuse_conn *fc;
};

struct mutex;

extern struct mutex fuse_mutex;

struct file *fget(int fd);
void fput(struct file *file);
struct fuse_dev *fuse_get_dev(struct file *file);
int fuse_device_clone(struct fuse_conn *fc, struct file *file);
void mutex_lock(struct mutex *lock);
void mutex_unlock(struct mutex *lock);
int get_user(int val, void *ptr);