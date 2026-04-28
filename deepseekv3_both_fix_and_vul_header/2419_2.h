#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define USB_MAXINTERFACES 32
#define USB_MAXALTSETTING 128
#define USB_MAXIADS 2
#define USB_QUIRK_HONOR_BNUMINTERFACES (1 << 0)
#define USB_DT_CONFIG 0x02
#define USB_DT_INTERFACE 0x04
#define USB_DT_DEVICE 0x01
#define USB_DT_INTERFACE_ASSOCIATION 0x0B
#define USB_DT_CONFIG_SIZE 9
#define USB_DT_INTERFACE_SIZE 9
#define USB_DT_INTERFACE_ASSOCIATION_SIZE 8

#define plural(n) ((n) == 1 ? "" : "s")
#define GFP_KERNEL 0
#define ENOMEM 12
#define EINVAL 22

typedef uint8_t u8;
typedef uint16_t u16;

struct device {
    const char *name;
};

struct usb_descriptor_header {
    u8 bLength;
    u8 bDescriptorType;
};

struct usb_config_descriptor {
    u8 bLength;
    u8 bDescriptorType;
    u16 wTotalLength;
    u8 bNumInterfaces;
    u8 bConfigurationValue;
    u8 iConfiguration;
    u8 bmAttributes;
    u8 bMaxPower;
};

struct usb_interface_descriptor {
    u8 bLength;
    u8 bDescriptorType;
    u8 bInterfaceNumber;
    u8 bAlternateSetting;
    u8 bNumEndpoints;
    u8 bInterfaceClass;
    u8 bInterfaceSubClass;
    u8 bInterfaceProtocol;
    u8 iInterface;
};

struct usb_interface_assoc_descriptor {
    u8 bLength;
    u8 bDescriptorType;
    u8 bFirstInterface;
    u8 bInterfaceCount;
    u8 bFunctionClass;
    u8 bFunctionSubClass;
    u8 bFunctionProtocol;
    u8 iFunction;
};

struct usb_host_interface {
    struct usb_interface_descriptor desc;
};

struct kref {
    int refcount;
};

struct usb_interface_cache {
    struct kref ref;
    unsigned int num_altsetting;
    struct usb_host_interface altsetting[];
};

struct usb_device {
    struct device dev;
    unsigned int quirks;
};

struct usb_host_config {
    struct usb_config_descriptor desc;
    struct usb_interface_cache *intf_cache[USB_MAXINTERFACES];
    struct usb_interface_assoc_descriptor *intf_assoc[USB_MAXIADS];
    unsigned char *extra;
    int extralen;
};

static inline void kref_init(struct kref *kref) {
    kref->refcount = 1;
}

static inline void *kzalloc(size_t size, int flags) {
    (void)flags;
    return calloc(1, size);
}

static inline u16 cpu_to_le16(u16 val) {
    return val;
}

static inline void dev_err(const struct device *dev, const char *fmt, ...) {}
static inline void dev_warn(const struct device *dev, const char *fmt, ...) {}
static inline void dev_dbg(const struct device *dev, const char *fmt, ...) {}

static int find_next_descriptor(unsigned char *buffer, int size,
                  int dt1, int dt2, int *num_skipped) {
    return 0;
}

static int usb_parse_interface(struct device *ddev, int cfgno,
                struct usb_host_config *config,
                unsigned char *buffer, int size,
                u8 *inums, u8 *nalts) {
    return 0;
}