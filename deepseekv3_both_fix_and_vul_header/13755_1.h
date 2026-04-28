#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>

#define MAX_USB_MINORS 256
#define USB_MAJOR 180
#define EINVAL 22
#define EADDRINUSE 98
#define EXFULL 54

struct usb_interface {
    int minor;
    void *dev;
    void *usb_dev;
};

struct file_operations;

struct usb_class_driver {
    const char *name;
    const struct file_operations *fops;
    int minor_base;
};

struct usb_class {
    void *class;
};

extern pthread_mutex_t init_usb_class_mutex;
extern pthread_rwlock_t minor_rwsem;
extern struct usb_class *usb_class;
extern struct file_operations *usb_minors[MAX_USB_MINORS];

int init_usb_class(void);
#define IS_ERR(ptr) ((unsigned long)(ptr) > (unsigned long)-1000L)
#define PTR_ERR(ptr) ((long)(ptr))
#define MKDEV(major, minor) (((major) << 8) | (minor))
#define dev_dbg(dev, fmt, ...) printf(fmt, ##__VA_ARGS__)
#define kbasename(path) (strrchr(path, '/') ? strrchr(path, '/') + 1 : path)
#define mutex_lock(lock) pthread_mutex_lock(lock)
#define mutex_unlock(lock) pthread_mutex_unlock(lock)
#define down_write(lock) pthread_rwlock_wrlock(lock)
#define up_write(lock) pthread_rwlock_unlock(lock)