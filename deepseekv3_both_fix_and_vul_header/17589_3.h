#include <stdint.h>

#define ECONNRESET 104
#define EINPROGRESS 115
#define ENODEV 19
#define EBUSY 16
#define EIDRM 43

struct urb;
struct device {
    // minimal device structure
    int dummy;
};

struct usb_device {
    struct device dev;
};

struct completion {
    // dummy completion structure
    int dummy;
};

struct usb_sg_request {
    uintptr_t lock;
    int status;
    int count;
    int entries;
    struct urb **urbs;
    struct usb_device *dev;
    struct completion complete;
};

void spin_lock_irqsave(uintptr_t *lock, unsigned long flags);
void spin_unlock_irqrestore(uintptr_t *lock, unsigned long flags);
void usb_block_urb(struct urb *urb);
int usb_unlink_urb(struct urb *urb);
void dev_warn(struct device *dev, const char *fmt, ...);
void complete(struct completion *comp);