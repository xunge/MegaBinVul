#include <stddef.h>

struct inode;
struct file {
    void *private_data;
};
struct fuse_dev {
    void *fc;
};
struct cuse_conn {
    struct list_head *list;
    void *dev;
    struct cdev *cdev;
};
struct list_head;
struct cdev {
    unsigned int dev;
};
struct mutex;

extern struct mutex cuse_lock;
struct cuse_conn *fc_to_cc(void *fc);
int fuse_dev_release(struct inode *inode, struct file *file);
void mutex_lock(struct mutex *lock);
void mutex_unlock(struct mutex *lock);
void list_del_init(struct list_head *entry);
void device_unregister(void *dev);
void unregister_chrdev_region(unsigned int dev, unsigned int count);
void cdev_del(struct cdev *cdev);