#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define GS_USB_BREQ_HOST_FORMAT 0
#define GS_USB_BREQ_DEVICE_CONFIG 1
#define GS_MAX_INTF 8
#define ENOMEM 12
#define EINVAL 22
#define GFP_KERNEL 0
#define USB_DIR_OUT 0
#define USB_DIR_IN 0x80
#define USB_TYPE_VENDOR (0x02 << 5)
#define USB_RECIP_INTERFACE 0x01

typedef uint8_t __u8;
typedef uint16_t __u16;
typedef uint32_t __u32;

struct usb_interface {
    struct {
        struct {
            uint8_t bInterfaceNumber;
        } desc;
    } altsetting[1];
    struct {
        int dev;
    } dev;
};

struct usb_device;
struct usb_device_id;

struct usb_anchor {
    int dummy;
};

struct gs_host_config {
    uint32_t byte_order;
};

struct gs_device_config {
    unsigned int icount;
};

struct gs_candev {
    struct gs_usb *parent;
};

struct gs_usb {
    struct usb_device *udev;
    struct usb_anchor rx_submitted;
    int active_channels;
    struct gs_candev *canch[GS_MAX_INTF];
};

static inline struct usb_device *interface_to_usbdev(struct usb_interface *intf) { return NULL; }
static inline unsigned int usb_sndctrlpipe(struct usb_device *dev, int endpoint) { return 0; }
static inline unsigned int usb_rcvctrlpipe(struct usb_device *dev, int endpoint) { return 0; }
static inline int usb_control_msg(struct usb_device *dev, unsigned int pipe, 
                                 __u8 request, __u8 requesttype, 
                                 __u16 value, __u16 index, 
                                 void *data, __u16 size, int timeout) { return 0; }
static inline void *kzalloc(size_t size, int flags) { return NULL; }
static inline void kfree(void *ptr) {}
static inline void init_usb_anchor(struct usb_anchor *anchor) {}
static inline void usb_kill_anchored_urbs(struct usb_anchor *anchor) {}
static inline void usb_set_intfdata(struct usb_interface *intf, void *data) {}
static inline struct gs_candev *gs_make_candev(int i, struct usb_interface *intf, struct gs_device_config *dconf) { return NULL; }
static inline void gs_destroy_candev(struct gs_candev *dev) {}
static inline void atomic_set(int *v, int i) { *v = i; }
#define dev_err(dev, fmt, ...) 
#define dev_info(dev, fmt, ...) 
#define IS_ERR_OR_NULL(ptr) (0)
#define PTR_ERR(ptr) (0)