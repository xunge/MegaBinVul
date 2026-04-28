#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_INTERRUPT_BUFFER 16
#define USB_DEVICE_ID_CODEMERCS_IOW56 0x1503
#define IOWARRIOR_MINOR_BASE 0
#define GFP_KERNEL 0
#define ENOMEM 1
#define EINVAL 2
#define USB_TYPE_CLASS 0x20
#define USB_RECIP_INTERFACE 0x01
#define USB_CTRL_SET_TIMEOUT 5000

struct usb_endpoint_descriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint8_t bEndpointAddress;
    uint8_t bmAttributes;
    uint16_t wMaxPacketSize;
    uint8_t bInterval;
};

struct usb_host_interface {
    struct {
        uint8_t bLength;
        uint8_t bDescriptorType;
        uint8_t bInterfaceNumber;
        uint8_t bAlternateSetting;
        uint8_t bNumEndpoints;
        uint8_t bInterfaceClass;
        uint8_t bInterfaceSubClass;
        uint8_t bInterfaceProtocol;
        uint8_t iInterface;
    } desc;
    struct {
        struct usb_endpoint_descriptor desc;
    } endpoint[8];
};

struct usb_interface {
    struct usb_host_interface *cur_altsetting;
    struct {
        char dev[1];
    } dev;
    int minor;
};

struct usb_device {
    struct {
        uint16_t idProduct;
        uint8_t iSerialNumber;
    } descriptor;
};

struct usb_device_id {
    uint16_t match_flags;
    uint16_t idVendor;
    uint16_t idProduct;
    uint16_t bcdDevice_lo;
    uint16_t bcdDevice_hi;
    uint8_t bDeviceClass;
    uint8_t bDeviceSubClass;
    uint8_t bDeviceProtocol;
    uint8_t bInterfaceClass;
    uint8_t bInterfaceSubClass;
    uint8_t bInterfaceProtocol;
    uint32_t driver_info;
};

struct urb {
    void *hcpriv;
    int status;
    void *context;
};

struct usb_class_driver {
    char *name;
    void *(*fops)(void);
    int minor_base;
};

struct iowarrior {
    struct usb_device *udev;
    struct usb_interface *interface;
    struct usb_endpoint_descriptor *int_in_endpoint;
    struct usb_endpoint_descriptor *int_out_endpoint;
    int report_size;
    struct urb *int_in_urb;
    unsigned char *int_in_buffer;
    unsigned char *read_queue;
    char chip_serial[9];
    int product_id;
    int present;
    int minor;
    int intr_idx;
    int read_idx;
    int intr_idx_lock;
    int overflow_flag;
    int read_wait;
    int write_busy;
    int write_wait;
    int mutex;
};

static inline struct usb_device *interface_to_usbdev(struct usb_interface *interface) {
    return (struct usb_device *)0;
}

static inline void *kzalloc(size_t size, int flags) {
    return calloc(1, size);
}

static inline void dev_err(void *dev, const char *fmt, ...) {}

static inline void mutex_init(int *mutex) {}

static inline void atomic_set(int *atomic, int value) {
    *atomic = value;
}

static inline void spin_lock_init(int *lock) {}

static inline void init_waitqueue_head(int *head) {}

static inline uint16_t le16_to_cpu(uint16_t val) {
    return val;
}

static inline int usb_endpoint_is_int_in(struct usb_endpoint_descriptor *epd) {
    return 0;
}

static inline int usb_endpoint_is_int_out(struct usb_endpoint_descriptor *epd) {
    return 0;
}

static inline int usb_endpoint_maxp(struct usb_endpoint_descriptor *epd) {
    return 0;
}

static inline void *kmalloc(size_t size, int flags) {
    return malloc(size);
}

static inline void *usb_alloc_urb(int iso_packets, int flags) {
    return malloc(sizeof(struct urb));
}

static inline void usb_fill_int_urb(struct urb *urb, struct usb_device *dev,
                                   int pipe, void *transfer_buffer,
                                   int buffer_length,
                                   void (*complete_fn)(struct urb *),
                                   void *context, int interval) {}

static inline int usb_string(struct usb_device *dev, int index,
                            char *buf, size_t size) {
    return 0;
}

static inline int usb_control_msg(struct usb_device *dev, int pipe,
                                 uint8_t request, uint8_t requesttype,
                                 uint16_t value, uint16_t index,
                                 void *data, uint16_t size, int timeout) {
    return 0;
}

static inline void usb_set_intfdata(struct usb_interface *interface, void *data) {}

static inline int usb_register_dev(struct usb_interface *interface,
                                  struct usb_class_driver *class_driver) {
    return 0;
}

static inline void dev_info(void *dev, const char *fmt, ...) {}

static inline int usb_rcvintpipe(struct usb_device *dev, int endpoint) {
    return 0;
}

static inline int usb_sndctrlpipe(struct usb_device *dev, int endpoint) {
    return 0;
}

static struct usb_class_driver iowarrior_class = {
    .name = "iowarrior",
    .minor_base = IOWARRIOR_MINOR_BASE,
};

static void iowarrior_callback(struct urb *urb) {}
static void iowarrior_delete(struct iowarrior *dev) {}