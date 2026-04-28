#include <stdlib.h>
#include <sys/types.h>

#define DVB_MAJOR 212
#define MAX_DVB_MINORS 256
#define __exit

struct list_head {
    struct list_head *next, *prev;
};

struct file_operations {
    int dummy;
};

struct dvbdevfops_node {
    struct list_head list_head;
    struct file_operations *fops;
};

struct class;
struct cdev;

extern struct class *dvb_class;
extern struct cdev dvb_device_cdev;
extern struct list_head dvbdevfops_list;

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = NULL, n = NULL; pos != (head); pos = n)
#define list_del(entry) do { } while(0)
#define kfree(ptr) free(ptr)
#define MKDEV(major, minor) (((major) << 8) | (minor))

static inline void class_destroy(struct class *cls) {}
static inline void cdev_del(struct cdev *cdev) {}
static inline void unregister_chrdev_region(dev_t dev, unsigned count) {}