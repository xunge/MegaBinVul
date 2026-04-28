#include <stddef.h>

struct usb_interface {
    int minor;
    void *dev;
    void *usb_dev;
};

struct usb_class_driver;
struct usb_device;
struct usb_class {
    void *class;
};

extern struct rw_semaphore minor_rwsem;
extern struct usb_class *usb_class;
extern struct usb_device *usb_minors[];

#define USB_MAJOR 180
#define MKDEV(ma,mi) (((ma) << 8) | (mi))

void down_write(struct rw_semaphore *sem);
void up_write(struct rw_semaphore *sem);
void device_destroy(void *class, int devt);
void destroy_usb_class(void);
void dev_dbg(const void *dev, const char *fmt, ...);