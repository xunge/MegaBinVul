#include <stdlib.h>
#include <stdio.h>

struct usb_device {
    struct {
        int dev;
    } dev;
};

struct atusb {
    struct usb_device *usb_dev;
    unsigned char fw_ver_maj;
    unsigned char fw_ver_min;
    unsigned char fw_hw_type;
};

#define ATUSB_ID 0
#define ATUSB_REQ_FROM_DEV 0
#define GFP_KERNEL 0
#define ENOMEM 12

static inline unsigned int usb_rcvctrlpipe(struct usb_device *dev, int endpoint)
{
    return 0;
}

extern int atusb_control_msg(struct atusb *atusb, unsigned int pipe, unsigned char request,
                            unsigned char requesttype, unsigned short value, unsigned short index,
                            void *data, unsigned short size, int timeout);

extern void *kmalloc(size_t size, int flags);
extern void kfree(void *ptr);
extern int dev_info(struct usb_device *dev, const char *fmt, ...);