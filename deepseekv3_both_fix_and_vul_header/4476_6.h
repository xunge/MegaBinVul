#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

typedef uint8_t __u8;
typedef uint16_t __u16;
typedef uint32_t __u32;

#define POWERMATE_PRODUCT_NEW 0x1910
#define POWERMATE_PRODUCT_OLD 0x0410
#define POWERMATE_PAYLOAD_SIZE_MIN 1
#define POWERMATE_PAYLOAD_SIZE_MAX 6

#define UPDATE_PULSE_ASLEEP (1 << 0)
#define UPDATE_PULSE_AWAKE  (1 << 1)
#define UPDATE_PULSE_MODE   (1 << 2)
#define UPDATE_STATIC_BRIGHTNESS (1 << 3)

#define ENOMEM 12
#define EINVAL 22
#define EIO 5

#define USB_TYPE_CLASS (0x01 << 5)
#define USB_RECIP_INTERFACE 0x01
#define USB_CTRL_SET_TIMEOUT 5000
#define GFP_KERNEL 0
#define KERN_WARNING ""
#define URB_NO_TRANSFER_DMA_MAP (1 << 0)

#define EV_KEY 0x01
#define EV_REL 0x02
#define EV_MSC 0x04
#define BTN_0 0x100
#define REL_DIAL 0x07
#define MSC_PULSELED 0x01

#define BIT_MASK(nr) (1UL << ((nr) % (8 * sizeof(long))))
#define BIT_WORD(nr) ((nr) / (8 * sizeof(long)))

static const char pm_name_powermate[] = "Griffin PowerMate";
static const char pm_name_soundknob[] = "Griffin SoundKnob";

struct usb_device_id {
    __u16 match_flags;
    __u16 idVendor;
    __u16 idProduct;
    __u16 bcdDevice_lo;
    __u16 bcdDevice_hi;
    __u8 bDeviceClass;
    __u8 bDeviceSubClass;
    __u8 bDeviceProtocol;
    __u8 bInterfaceClass;
    __u8 bInterfaceSubClass;
    __u8 bInterfaceProtocol;
    uintptr_t driver_info;
};

struct usb_endpoint_descriptor {
    __u8 bLength;
    __u8 bDescriptorType;
    __u8 bEndpointAddress;
    __u8 bmAttributes;
    __u16 wMaxPacketSize;
    __u8 bInterval;
};

struct usb_host_interface {
    struct {
        __u8 bNumEndpoints;
        __u8 bInterfaceNumber;
    } desc;
    struct {
        struct usb_endpoint_descriptor desc;
    } endpoint[1];
};

struct usb_interface {
    struct usb_host_interface *cur_altsetting;
    struct {
        struct usb_device *parent;
        struct usb_interface *dev;
    } dev;
};

struct usb_device {
    struct {
        __u16 idProduct;
    } descriptor;
};

struct urb {
    void *transfer_dma;
    unsigned int transfer_flags;
};

struct input_id {
    int id;
};

struct input_dev {
    const char *name;
    const char *phys;
    struct {
        struct usb_interface *dev;
        struct usb_interface *parent;
    } dev;
    void *event;
    unsigned long evbit[1];
    unsigned long keybit[1];
    unsigned long relbit[1];
    unsigned long mscbit[1];
    struct input_id id;
};

struct powermate_device {
    struct usb_device *udev;
    struct usb_interface *intf;
    struct urb *irq;
    struct urb *config;
    struct input_dev *input;
    int lock;
    char phys[64];
    unsigned int requires_update;
    unsigned char *data;
    uintptr_t data_dma;
};

static inline struct usb_device *interface_to_usbdev(struct usb_interface *intf) {
    return intf ? (struct usb_device *)intf->dev.parent : NULL;
}

static inline int usb_endpoint_is_int_in(const struct usb_endpoint_descriptor *epd) {
    return epd ? ((epd->bmAttributes & 0x03) == 0x03) && ((epd->bEndpointAddress & 0x80) == 0x80) : 0;
}

static inline int usb_control_msg(struct usb_device *dev, unsigned int pipe,
                __u8 request, __u8 requesttype,
                __u16 value, __u16 index,
                void *data, __u16 size, int timeout) {
    return 0;
}

static inline unsigned int usb_sndctrlpipe(struct usb_device *dev, unsigned int endpoint) {
    return 0;
}

static inline unsigned int usb_rcvintpipe(struct usb_device *dev, unsigned int endpoint) {
    return 0;
}

static inline unsigned int usb_pipeout(unsigned int pipe) {
    return 0;
}

static inline unsigned int usb_maxpacket(struct usb_device *dev, unsigned int pipe, int is_out) {
    return 0;
}

static inline void *kzalloc(size_t size, int flags) {
    return calloc(1, size);
}

static inline void kfree(void *ptr) {
    free(ptr);
}

static inline struct input_dev *input_allocate_device(void) {
    return (struct input_dev *)calloc(1, sizeof(struct input_dev));
}

static inline void input_free_device(struct input_dev *dev) {
    free(dev);
}

static inline int powermate_alloc_buffers(struct usb_device *udev, struct powermate_device *pm) {
    return 0;
}

static inline struct urb *usb_alloc_urb(int iso_packets, int mem_flags) {
    return (struct urb *)calloc(1, sizeof(struct urb));
}

static inline void usb_free_urb(struct urb *urb) {
    free(urb);
}

static inline void usb_make_path(struct usb_device *dev, char *buf, size_t size) {
    snprintf(buf, size, "usb-%04x-%04x", 0, 0);
}

static inline size_t strlcat(char *dst, const char *src, size_t size) {
    return strncat(dst, src, size - strlen(dst) - 1) ? strlen(dst) + strlen(src) : 0;
}

static inline void spin_lock_init(int *lock) {
    *lock = 0;
}

static inline __u16 le16_to_cpu(__u16 val) {
    return val;
}

static inline int printk(const char *fmt, ...) {
    return 0;
}

static inline void usb_to_input_id(struct usb_device *dev, struct input_id *id) {
}

static inline void input_set_drvdata(struct input_dev *dev, void *data) {
}

static inline void powermate_input_event(struct input_dev *dev, unsigned int type, 
                                      unsigned int code, int value) {
}

static inline void powermate_irq(struct urb *urb) {
}

static inline void usb_fill_int_urb(struct urb *urb, struct usb_device *dev,
                                  unsigned int pipe, void *transfer_buffer,
                                  int buffer_length, void (*complete_fn)(struct urb *),
                                  void *context, int interval) {
}

static inline int usb_submit_urb(struct urb *urb, int mem_flags) {
    return 0;
}

static inline int input_register_device(struct input_dev *dev) {
    return 0;
}

static inline void usb_set_intfdata(struct usb_interface *intf, void *data) {
}

static inline void usb_kill_urb(struct urb *urb) {
}

static inline void powermate_pulse_led(struct powermate_device *pm, __u8 level, 
                                    __u8 pulse_table, __u8 pulse_speed,
                                    __u8 pulse_table_on, __u8 pulse_speed_on) {
}

static inline void powermate_free_buffers(struct usb_device *udev, struct powermate_device *pm) {
}