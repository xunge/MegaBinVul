#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#define YUREX_BUF_SIZE 64

struct kref {
    int refcount;
};

struct usb_device {
    int dummy;
};

struct usb_interface {
    struct {
        int dummy;
    } dev;
};

struct urb {
    unsigned int transfer_dma;
};

struct usb_ctrlrequest {
    int dummy;
};

struct usb_yurex {
    struct usb_device *udev;
    struct usb_interface *interface;
    struct urb *urb;
    struct urb *cntl_urb;
    void *int_buffer;
    void *cntl_buffer;
    struct usb_ctrlrequest *cntl_req;
    struct kref kref;
};

static inline struct usb_yurex *to_yurex_dev(struct kref *kref)
{
    return (struct usb_yurex *)((char *)kref - offsetof(struct usb_yurex, kref));
}

void dev_dbg(void *dev, const char *fmt, ...);
void usb_put_dev(struct usb_device *udev);
void usb_kill_urb(struct urb *urb);
void kfree(void *ptr);
void usb_free_coherent(struct usb_device *udev, size_t size, void *addr, unsigned int dma);
void usb_free_urb(struct urb *urb);