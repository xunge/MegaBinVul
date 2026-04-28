#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

struct kobject {
    int dummy;
};

struct device {
    struct kobject kobj;
};

struct usb_endpoint_descriptor {
    int dummy;
};

struct usb_device {
    struct device dev;
    struct {
        struct {
            int bNumInterfaces;
        } desc;
    } *actconfig;
};

struct usb_interface {
    struct usb_host_interface *cur_altsetting;
    struct device dev;
    int needs_remote_wakeup;
};

struct usb_host_interface {
    struct {
        int bInterfaceNumber;
        int bNumEndpoints;
    } desc;
    struct {
        struct {
            struct usb_endpoint_descriptor desc;
        } *endpoint;
    };
};

struct usb_device_id {
    int dummy;
};

struct usb_driver {
    int dummy;
};

struct attribute_group {
    int dummy;
};

struct ati_remote2 {
    struct usb_device *udev;
    struct usb_interface *intf[2];
    struct usb_endpoint_descriptor *ep[2];
    char phys[64];
    char name[128];
    int channel_mask;
    int mode_mask;
};

static struct usb_driver ati_remote2_driver;
static int channel_mask;
static int mode_mask;
static struct attribute_group ati_remote2_attr_group;

#define GFP_KERNEL 0
#define ENODEV 19
#define ENOMEM 12

static inline struct usb_device *interface_to_usbdev(struct usb_interface *intf) { return NULL; }
static inline struct usb_interface *usb_ifnum_to_if(struct usb_device *dev, int ifnum) { return NULL; }
static inline int usb_driver_claim_interface(struct usb_driver *driver, struct usb_interface *intf, void *data) { return 0; }
static inline void usb_driver_release_interface(struct usb_driver *driver, struct usb_interface *intf) {}
static inline void usb_make_path(struct usb_device *dev, char *buf, size_t size) {}
static inline void usb_set_intfdata(struct usb_interface *intf, void *data) {}
static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline int sysfs_create_group(struct kobject *kobj, const struct attribute_group *grp) { return 0; }
static inline void sysfs_remove_group(struct kobject *kobj, const struct attribute_group *grp) {}
static inline void dev_err(struct device *dev, const char *fmt, ...) {}
static inline size_t strlcat(char *dst, const char *src, size_t size) { return strncat(dst, src, size) - dst; }

static int ati_remote2_urb_init(struct ati_remote2 *ar2) { return 0; }
static void ati_remote2_urb_cleanup(struct ati_remote2 *ar2) {}
static int ati_remote2_setup(struct ati_remote2 *ar2, int channel_mask) { return 0; }
static int ati_remote2_input_init(struct ati_remote2 *ar2) { return 0; }