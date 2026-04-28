#include <stddef.h>

struct inode;
struct file {
    void *private_data;
};

struct fuse_dev {
    void *fc;
};

struct fuse_conn;

struct list_head {
    struct list_head *next, *prev;
};

struct cuse_conn {
    void *fc;
    struct list_head list;
    void *dev;
    struct {
        unsigned int dev;
    } *cdev;
};

struct device;

extern struct mutex cuse_lock;

static inline struct cuse_conn *fc_to_cc(void *fc)
{
    return (struct cuse_conn *)((char *)fc - offsetof(struct cuse_conn, fc));
}

int mutex_lock(void *lock);
int mutex_unlock(void *lock);
void list_del_init(struct list_head *entry);
int device_unregister(void *dev);
int unregister_chrdev_region(unsigned int dev, unsigned count);
void cdev_del(void *cdev);
void fuse_conn_put(void *fc);
int fuse_dev_release(struct inode *inode, struct file *file);