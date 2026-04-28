#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>

struct module {
    int dummy;
};

struct cdev {
    int dummy;
};

struct mdev_driver {
    int dummy;
};

struct class {
    int dummy;
};

struct device {
    struct class *class;
    void (*release)(struct device *dev);
    int dummy;
};

struct file_operations {
    int dummy;
};

static atomic_int mbochs_avail_mbytes;
static int max_mbytes;
static dev_t mbochs_devt;
static struct cdev mbochs_cdev;
static struct mdev_driver mbochs_driver;
static struct class *mbochs_class;
static struct device mbochs_dev;
static const struct file_operations vd_fops;
static const struct file_operations mdev_fops;
static void mbochs_device_release(struct device *dev) {}

#define MINORMASK 0
#define MBOCHS_NAME ""
#define MBOCHS_CLASS_NAME ""
#define THIS_MODULE NULL
#define IS_ERR(x) (0)
#define PTR_ERR(x) (0)
#define MAJOR(x) (0)
#define __init
#define pr_err(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define pr_info(fmt, ...) printf(fmt, ##__VA_ARGS__)

static inline void atomic_set(atomic_int *v, int i) { *v = i; }
int alloc_chrdev_region(dev_t *dev, unsigned baseminor, unsigned count, const char *name) { return 0; }
void cdev_init(struct cdev *cdev, const struct file_operations *fops) {}
int cdev_add(struct cdev *p, dev_t dev, unsigned count) { return 0; }
int mdev_register_driver(struct mdev_driver *drv) { return 0; }
struct class *class_create(struct module *owner, const char *name) { return NULL; }
void dev_set_name(struct device *dev, const char *fmt, const char *name) {}
int device_register(struct device *dev) { return 0; }
int mdev_register_device(struct device *dev, const struct file_operations *fops) { return 0; }
void device_unregister(struct device *dev) {}
void class_destroy(struct class *cls) {}
void mdev_unregister_driver(struct mdev_driver *drv) {}
void cdev_del(struct cdev *p) {}
void unregister_chrdev_region(dev_t from, unsigned count) {}