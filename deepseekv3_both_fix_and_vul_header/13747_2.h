#include <stddef.h>

struct usb_interface {
    void *dev;
};

struct mutex {
    // dummy definition
};

struct urb {
    // dummy definition
};

struct usb_class_driver {
    // dummy definition
};

struct iowarrior {
    int minor;
    struct mutex mutex;
    int present;
    int opened;
    struct urb *int_in_urb;
    void *read_wait;
    void *write_wait;
};

extern struct mutex iowarrior_open_disc_lock;
extern struct usb_class_driver iowarrior_class;
extern int IOWARRIOR_MINOR_BASE;