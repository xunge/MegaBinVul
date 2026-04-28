#include <stdlib.h>
#include <string.h>

#define ATUSB_BUILD_SIZE 64
#define ATUSB_BUILD 0x00
#define ATUSB_REQ_FROM_DEV 0x01
#define GFP_KERNEL 0
#define ENOMEM 12

struct usb_device {
    int dev;
};

struct atusb {
    struct usb_device *usb_dev;
};

static int atusb_control_msg(struct atusb *atusb, int pipe, int request, int requesttype, 
                            int value, int index, void *data, int size, int timeout);
static void dev_info(int *dev, const char *format, ...);