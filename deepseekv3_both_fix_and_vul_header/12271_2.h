#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef uint8_t __u8;
typedef uint16_t __u16;

struct device {
    struct device *parent;
};

struct device_attribute;
struct usb_interface;
struct usb_device;

#define K90_REQUEST_GET_MODE 0x0b
#define K90_MACRO_MODE_HW 0
#define K90_MACRO_MODE_SW 1
#define GFP_KERNEL 0
#define ENOMEM 12
#define EIO 5
#define PAGE_SIZE 4096
#define USB_DIR_IN 0x80
#define USB_TYPE_VENDOR 0x40
#define USB_RECIP_DEVICE 0x00
#define USB_CTRL_SET_TIMEOUT 5000

static inline struct usb_interface *to_usb_interface(struct device *dev) { return NULL; }
static inline struct usb_device *interface_to_usbdev(struct usb_interface *intf) { return NULL; }
static inline void dev_warn(struct device *dev, const char *fmt, ...) {}
static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline int usb_control_msg(struct usb_device *dev, unsigned int pipe, 
                                __u8 request, __u8 requesttype, __u16 value, 
                                __u16 index, void *data, __u16 size, int timeout) { return 0; }
static inline unsigned int usb_rcvctrlpipe(struct usb_device *dev, unsigned int endpoint) { return 0; }