#include <stddef.h>

struct usb_interface {
    void *dev;
};

struct mutex {
    int dummy;
};

struct urb {
    int dummy;
};

struct wait_queue_head {
    int dummy;
};

struct usb_class_driver {
    int dummy;
};

struct iowarrior {
    int minor;
    int present;
    struct mutex mutex;
    int opened;
    struct urb *int_in_urb;
    struct wait_queue_head read_wait;
    struct wait_queue_head write_wait;
};

extern struct mutex iowarrior_open_disc_lock;
extern struct usb_class_driver iowarrior_class;
extern int IOWARRIOR_MINOR_BASE;

void *usb_get_intfdata(struct usb_interface *interface);
void usb_set_intfdata(struct usb_interface *interface, void *data);
void mutex_lock(struct mutex *lock);
void mutex_unlock(struct mutex *lock);
void usb_deregister_dev(struct usb_interface *interface, struct usb_class_driver *driver);
void usb_kill_urb(struct urb *urb);
void wake_up_interruptible(struct wait_queue_head *q);
void iowarrior_delete(struct iowarrior *dev);
void dev_info(void *dev, const char *fmt, ...);