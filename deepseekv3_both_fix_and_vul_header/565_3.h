#include <stddef.h>
#include <stdint.h>

#define OBUF_SIZE 0x1000
#define IBUF_SIZE 0x1000
#define GFP_KERNEL 0
#define EBUSY 16
#define ENOMEM 12

struct usb_device {
    int devnum;
    struct {
        int dummy;
    } dev;
};

struct usb_interface {
    struct usb_device dev;
};

struct usb_device_id {};
struct usb_class_driver {};

struct mutex {
    int dummy;
};

struct rio_usb_data {
    struct usb_device *rio_dev;
    unsigned char *obuf;
    unsigned char *ibuf;
    struct mutex lock;
    int present;
};

static struct rio_usb_data rio_instance;
static struct mutex rio500_mutex;
static struct usb_class_driver usb_rio_class;

static inline struct usb_device *interface_to_usbdev(struct usb_interface *intf) { return &intf->dev; }
static inline int usb_register_dev(struct usb_interface *intf, struct usb_class_driver *class) { return 0; }
static inline void usb_deregister_dev(struct usb_interface *intf, struct usb_class_driver *class) {}
static inline void *kmalloc(size_t size, int flags) { return NULL; }
static inline void kfree(void *ptr) {}
static inline void mutex_init(struct mutex *lock) {}
static inline void mutex_lock(struct mutex *lock) {}
static inline void mutex_unlock(struct mutex *lock) {}
static inline void usb_set_intfdata(struct usb_interface *intf, void *data) {}
static inline void dev_info(struct usb_device *dev, const char *fmt, ...) {}
static inline void dev_err(struct usb_device *dev, const char *fmt, ...) {}
static inline void dev_dbg(struct usb_device *dev, const char *fmt, ...) {}