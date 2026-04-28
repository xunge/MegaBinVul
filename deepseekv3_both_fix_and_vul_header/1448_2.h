#include <stddef.h>
#include <stdint.h>

struct cdev {
    // minimal definition
};

struct inode {
    struct cdev *i_cdev;
};

struct file {
    void *private_data;
};

struct printer_dev {
    struct cdev printer_cdev;
    uintptr_t lock;
    int interface;
    int printer_cdev_open;
    unsigned int printer_status;
    uintptr_t kref;
};

#define PRINTER_SELECTED 0x01
#define EBUSY 16
#define ENODEV 19

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define spin_lock_irqsave(lock, flags) ((void)0)
#define spin_unlock_irqrestore(lock, flags) ((void)0)
#define kref_get(kref) ((void)0)
#define DBG(dev, fmt, ...) ((void)0)