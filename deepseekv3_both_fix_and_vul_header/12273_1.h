#include <stdint.h>
#include <stdlib.h>

struct usb_device {
    struct {
        char dev[0];
    } dev;
};

struct atusb {
    struct usb_device *usb_dev;
};

#define ATUSB_REG_READ 0
#define ATUSB_REQ_FROM_DEV 0
#define GFP_KERNEL 0
#define ENOMEM 1

void *kmalloc(size_t size, int flags);
void kfree(void *ptr);
int atusb_control_msg(struct atusb *atusb, unsigned int pipe, uint8_t request, uint8_t requesttype,
                     uint16_t value, uint16_t index, void *data, uint16_t size, int timeout);
unsigned int usb_rcvctrlpipe(struct usb_device *dev, unsigned int endpoint);
void dev_dbg(void *dev, const char *fmt, ...);