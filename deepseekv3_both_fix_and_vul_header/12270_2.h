#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

#define K90_REQUEST_STATUS 0x09
#define USB_CTRL_SET_TIMEOUT 5000
#define GFP_KERNEL 0
#define ENOMEM 12
#define EIO 5
#define USB_DIR_IN 0x80
#define USB_TYPE_VENDOR 0x40
#define USB_RECIP_DEVICE 0x00

typedef uint8_t __u8;
typedef uint16_t __u16;

enum led_brightness {
    LED_OFF = 0,
    LED_HALF = 1,
    LED_FULL = 2
};

struct device {
    struct device *parent;
};

struct usb_interface;
struct usb_device;

struct led_classdev {
    struct device *dev;
};

struct k90_led {
    struct led_classdev cdev;
};

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

static inline struct usb_device *interface_to_usbdev(struct usb_interface *intf) {
    return (struct usb_device *)0;
}

static inline struct usb_interface *to_usb_interface(struct device *dev) {
    return (struct usb_interface *)0;
}

static inline int usb_control_msg(struct usb_device *dev, unsigned int pipe,
                                __u8 request, __u8 requesttype,
                                __u16 value, __u16 index,
                                void *data, __u16 size, int timeout) {
    return 0;
}

static inline unsigned int usb_rcvctrlpipe(struct usb_device *dev, unsigned int endpoint) {
    return 0;
}

static inline void dev_warn(struct device *dev, const char *fmt, ...) {}

static inline void *kmalloc(size_t size, int flags) {
    return malloc(size);
}

static inline void kfree(void *ptr) {
    free(ptr);
}