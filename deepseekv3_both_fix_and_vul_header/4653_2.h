#include <stddef.h>

struct usbdevfs_connectinfo {
    unsigned int devnum;
    unsigned char slow;
};

struct usb_dev_state {
    struct usb_device *dev;
};

struct usb_device {
    int devnum;
    int speed;
};

#define USB_SPEED_LOW 1
#define EFAULT 14
#define __user
typedef void* user_ptr_arg;