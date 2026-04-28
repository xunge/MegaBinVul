#include <stdbool.h>
#include <stddef.h>

struct kref {
    int refcount;
};

struct mutex {
    int lock;
};

struct xillyfifo {
    void *waitq;
};

struct xillyusb_endpoint {
    struct xillyfifo fifo;
    bool wake_on_drain;
    bool drained;
};

struct xillyusb_channel {
    struct mutex lock;
    struct xillyusb_endpoint *out_ep;
};

struct device {
    int dummy;
};

struct usb_interface {
    struct device dev;
};

struct xillyusb_dev {
    struct xillyusb_endpoint *msg_ep;
    struct xillyusb_endpoint *in_ep;
    struct xillyusb_channel *channels;
    int num_channels;
    int error;
    struct device *dev;
    struct kref kref;
};

extern struct mutex kref_mutex;
extern void xillybus_cleanup_chrdev(struct xillyusb_dev *xdev, struct device *dev);
extern void xillyusb_send_opcode(struct xillyusb_dev *xdev, unsigned int mask, int opcode, int data);
extern void report_io_error(struct xillyusb_dev *xdev, int error);
extern void endpoint_quiesce(struct xillyusb_endpoint *ep);
extern void cleanup_dev(struct kref *kref);
extern void *usb_get_intfdata(struct usb_interface *interface);
extern void usb_set_intfdata(struct usb_interface *interface, void *data);
extern void dev_err(struct device *dev, const char *fmt, ...);
extern int wait_event_interruptible_timeout(void *waitq, bool condition, int timeout);
extern void mutex_lock(struct mutex *lock);
extern void mutex_unlock(struct mutex *lock);
extern void kref_put(struct kref *kref, void (*release)(struct kref *kref));

#define XILLY_RESPONSE_TIMEOUT 2
#define OPCODE_QUIESCE 0
#define ENODEV 19