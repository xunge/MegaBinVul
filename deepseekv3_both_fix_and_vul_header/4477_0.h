#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define REPORT_MAX_SIZE 1024
#define HID_DEVICE_TYPE 0x21
#define REPORT_DEVICE_TYPE 0x22
#define GFP_KERNEL 0
#define ENOMEM 1
#define EIO 2
#define EINVAL 3
#define USB_REQ_GET_DESCRIPTOR 0x06
#define USB_RECIP_INTERFACE 0x01
#define USB_DIR_IN 0x80
#define URB_NO_TRANSFER_DMA_MAP 0x0004

struct usb_interface;
struct usb_device;
struct urb;
struct input_dev;

struct usb_endpoint_descriptor {
    uint8_t bEndpointAddress;
    uint8_t bmAttributes;
    uint8_t bDescriptorType;
    uint8_t bInterval;
};

struct usb_device_id {
    int dummy;
};

struct usb_interface {
    struct {
        struct {
            struct usb_endpoint_descriptor desc;
        } *endpoint;
        int extralen;
        struct {
            uint8_t bNumEndpoints;
            uint8_t bInterfaceClass;
        } desc;
    } *altsetting, *cur_altsetting;
    int num_altsetting;
    struct {
        char *dev;
    } dev;
};

struct hid_descriptor {
    uint8_t bDescriptorType;
    uint16_t wDescriptorLength;
};

struct urb {
    void *transfer_dma;
    int transfer_flags;
};

struct input_dev {
    void (*open)(struct input_dev *);
    void (*close)(struct input_dev *);
    char *name;
    char *phys;
    struct {
        int id;
    } id;
    struct {
        void *parent;
    } dev;
};

struct gtco {
    struct input_dev *inputdevice;
    struct usb_device *usbdev;
    struct usb_interface *intf;
    struct urb *urbinfo;
    void *buffer;
    uintptr_t buf_dma;
    char usbpath[64];
};

static inline struct usb_device *interface_to_usbdev(struct usb_interface *intf) {
    return (struct usb_device *)0;
}

static inline void *kzalloc(size_t size, int flags) {
    return calloc(1, size);
}

static inline void kfree(void *ptr) {
    free(ptr);
}

static inline void *usb_alloc_coherent(struct usb_device *dev, size_t size, int flags, uintptr_t *dma) {
    *dma = (uintptr_t)calloc(1, size);
    return (void *)*dma;
}

static inline void usb_free_coherent(struct usb_device *dev, size_t size, void *addr, uintptr_t dma) {
    free(addr);
}

static inline struct urb *usb_alloc_urb(int iso_packets, int flags) {
    return (struct urb *)calloc(1, sizeof(struct urb));
}

static inline void usb_free_urb(struct urb *urb) {
    free(urb);
}

static inline int usb_get_extra_descriptor(void *setting, unsigned char type, struct hid_descriptor **desc) {
    return -1;
}

static inline int usb_control_msg(struct usb_device *dev, unsigned int pipe, 
                                 uint8_t request, uint8_t requesttype,
                                 uint16_t value, uint16_t index,
                                 void *data, uint16_t size, int timeout) {
    return 0;
}

static inline void usb_fill_int_urb(struct urb *urb, struct usb_device *dev,
                                   unsigned int pipe, void *transfer_buffer,
                                   int buffer_length, void (*complete_fn)(struct urb *),
                                   void *context, int interval) {
}

static inline void usb_set_intfdata(struct usb_interface *intf, void *data) {
}

static inline struct input_dev *input_allocate_device(void) {
    return (struct input_dev *)calloc(1, sizeof(struct input_dev));
}

static inline void input_free_device(struct input_dev *dev) {
    free(dev);
}

static inline int input_register_device(struct input_dev *dev) {
    return 0;
}

static inline void input_set_drvdata(struct input_dev *dev, void *data) {
}

static inline void usb_to_input_id(struct usb_device *dev, void *id) {
}

static inline void dev_err(void *dev, const char *fmt, ...) {
}

static inline void dev_dbg(void *dev, const char *fmt, ...) {
}

static inline uint16_t le16_to_cpu(uint16_t val) {
    return val;
}

static inline void parse_hid_report_descriptor(struct gtco *gtco, char *report, int size) {
}

static inline void gtco_setup_caps(struct input_dev *dev) {
}

static inline void gtco_input_open(struct input_dev *dev) {
}

static inline void gtco_input_close(struct input_dev *dev) {
}

static inline void gtco_urb_callback(struct urb *urb) {
}

static inline unsigned int usb_rcvctrlpipe(struct usb_device *dev, unsigned int endpoint) {
    return 0;
}

static inline unsigned int usb_rcvintpipe(struct usb_device *dev, unsigned int endpoint) {
    return 0;
}

static inline int usb_endpoint_xfer_int(const struct usb_endpoint_descriptor *epd) {
    return 0;
}

static inline void usb_make_path(struct usb_device *dev, char *buf, size_t size) {
    strcpy(buf, "");
}

static inline void strlcat(char *dest, const char *src, size_t size) {
    strncat(dest, src, size - strlen(dest) - 1);
}