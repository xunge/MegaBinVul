#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct usb_interface {
    struct {
        struct {
            int bInterfaceNumber;
        } desc;
    } *cur_altsetting;
};

struct device {
    char name[64];
};

struct usb_device {
    struct device dev;
};

struct dvb_usb_device {
    struct usb_device *udev;
    const char *name;
    struct {
        void (*exit)(struct dvb_usb_device *);
    } *props;
};

#define GFP_KERNEL 0
#define KBUILD_MODNAME "module"
#define pr_info(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define dev_dbg(dev, fmt, ...) printf(fmt, ##__VA_ARGS__)
#define kstrdup(str, flags) strdup(str)
#define kfree(ptr) free(ptr)

void *usb_get_intfdata(struct usb_interface *intf);
void dvb_usbv2_exit(struct dvb_usb_device *d);