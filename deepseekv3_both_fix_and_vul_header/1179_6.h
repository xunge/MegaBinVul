#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

#define USB_COMP_EP0_BUFSIZ 4096
#define USB_COMP_EP0_OS_DESC_BUFSIZ 4096
#define MAX_CONFIG_INTERFACES 32
#define OTG_STS_SELECTOR 0xF000
#define USB_INTRF_FUNC_SUSPEND 0
#define USB_GADGET_DELAYED_STATUS (-115)

#define USB_DIR_OUT 0
#define USB_DIR_IN 0x80
#define USB_TYPE_MASK 0x60
#define USB_TYPE_STANDARD 0x00
#define USB_TYPE_VENDOR 0x40
#define USB_RECIP_MASK 0x1F
#define USB_RECIP_DEVICE 0x00
#define USB_RECIP_INTERFACE 0x01
#define USB_RECIP_ENDPOINT 0x02

#define USB_REQ_GET_DESCRIPTOR 0x06
#define USB_REQ_SET_CONFIGURATION 0x09
#define USB_REQ_GET_CONFIGURATION 0x08
#define USB_REQ_SET_INTERFACE 0x0B
#define USB_REQ_GET_INTERFACE 0x0A
#define USB_REQ_GET_STATUS 0x00
#define USB_REQ_CLEAR_FEATURE 0x01
#define USB_REQ_SET_FEATURE 0x03

#define USB_DT_DEVICE 0x01
#define USB_DT_CONFIG 0x02
#define USB_DT_STRING 0x03
#define USB_DT_INTERFACE 0x04
#define USB_DT_ENDPOINT 0x05
#define USB_DT_DEVICE_QUALIFIER 0x06
#define USB_DT_OTHER_SPEED_CONFIG 0x07
#define USB_DT_BOS 0x0F
#define USB_DT_OTG 0x09

#define USB_SPEED_SUPER 3

#define EOPNOTSUPP 95
#define GFP_ATOMIC 0

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef int16_t __le16;

struct list_head {
    struct list_head *next, *prev;
};

struct usb_gadget {
    struct usb_ep *ep0;
    unsigned speed;
    unsigned is_dualspeed:1;
    unsigned is_superspeed:1;
    unsigned is_otg:1;
    unsigned a_hnp_support:1;
    unsigned a_alt_hnp_support:1;
    unsigned hnp_polling_support:1;
    unsigned lpm_capable:1;
    u8 host_request_flag;
    struct usb_otg_caps *otg_caps;
};

struct usb_ep {
    void *driver_data;
    unsigned maxpacket;
};

struct usb_ctrlrequest {
    u8 bRequestType;
    u8 bRequest;
    __le16 wValue;
    __le16 wIndex;
    __le16 wLength;
};

struct usb_request {
    void *buf;
    unsigned length;
    unsigned zero;
    void *context;
    void (*complete)(struct usb_ep *, struct usb_request *);
    int status;
};

struct usb_device_descriptor {
    u8 bLength;
    u8 bDescriptorType;
    __le16 bcdUSB;
    u8 bDeviceClass;
    u8 bDeviceSubClass;
    u8 bDeviceProtocol;
    u8 bMaxPacketSize0;
    u8 bNumConfigurations;
};

struct usb_composite_dev {
    struct usb_gadget *gadget;
    struct usb_request *req;
    struct usb_device_descriptor desc;
    struct usb_configuration *config;
    struct list_head configs;
    unsigned delayed_status;
    int lock;
    unsigned use_os_string:1;
    struct usb_configuration *os_desc_config;
    u8 b_vendor_code;
    struct usb_request *os_desc_req;
};

struct usb_function {
    const char *name;
    struct list_head list;
    int (*set_alt)(struct usb_function *, unsigned, unsigned);
    int (*get_alt)(struct usb_function *, unsigned);
    int (*get_status)(struct usb_function *);
    int (*func_suspend)(struct usb_function *, u8);
    bool (*req_match)(struct usb_function *, const struct usb_ctrlrequest *, bool);
    int (*setup)(struct usb_function *, const struct usb_ctrlrequest *);
    unsigned long endpoints[1];
};

struct usb_configuration {
    struct list_head list;
    struct list_head functions;
    struct usb_function *interface[MAX_CONFIG_INTERFACES];
    u8 bConfigurationValue;
    int (*setup)(struct usb_configuration *, const struct usb_ctrlrequest *);
    const u8 **descriptors;
};

struct usb_qualifier_descriptor {
    u8 bLength;
    u8 bDescriptorType;
    __le16 bcdUSB;
    u8 bDeviceClass;
    u8 bDeviceSubClass;
    u8 bDeviceProtocol;
    u8 bMaxPacketSize0;
    u8 bNumConfigurations;
    u8 bRESERVED;
};

struct usb_otg_descriptor {
    u8 bLength;
    u8 bDescriptorType;
    u8 bmAttributes;
};

struct usb_otg20_descriptor {
    u8 bLength;
    u8 bDescriptorType;
    u8 bmAttributes;
    __le16 bcdOTG;
};

struct usb_otg_caps {
    u16 otg_rev;
};

static inline __le16 cpu_to_le16(u16 val) { return val; }
static inline u16 le16_to_cpu(__le16 val) { return val; }
static inline void put_unaligned_le16(u16 val, void *p) { *(u16 *)p = val; }
static inline void put_unaligned_le32(u32 val, void *p) { *(u32 *)p = val; }

#define min(x, y) ((x) < (y) ? (x) : (y))
#define min_t(type, x, y) ((type)(x) < (type)(y) ? (type)(x) : (type)(y))

static inline void spin_lock(int *lock) { (void)lock; }
static inline void spin_unlock(int *lock) { (void)lock; }
static inline bool test_bit(unsigned nr, const unsigned long *addr) { return false; }

static inline struct usb_composite_dev *get_gadget_data(struct usb_gadget *g) { return NULL; }
static inline void composite_setup_complete(struct usb_ep *ep, struct usb_request *req) {}
static inline int composite_ep0_queue(struct usb_composite_dev *cdev, struct usb_request *req, int gfp) { return 0; }
static inline int count_configs(struct usb_composite_dev *cdev, u8 type) { return 0; }
static inline void device_qual(struct usb_composite_dev *cdev) {}
static inline int config_desc(struct usb_composite_dev *cdev, u16 w_value) { return 0; }
static inline int get_string(struct usb_composite_dev *cdev, u8 *buf, u16 w_index, u8 id) { return 0; }
static inline int bos_desc(struct usb_composite_dev *cdev) { return 0; }
static inline int set_config(struct usb_composite_dev *cdev, const struct usb_ctrlrequest *ctrl, u16 w_value) { return 0; }
static inline int count_ext_compat(struct usb_configuration *c) { return 0; }
static inline int fill_ext_compat(struct usb_configuration *c, u8 *buf) { return 0; }
static inline int count_ext_prop(struct usb_configuration *c, int interface) { return 0; }
static inline int len_ext_prop(struct usb_configuration *c, int interface) { return 0; }
static inline int fill_ext_prop(struct usb_configuration *c, int interface, u8 *buf) { return 0; }

#define DBG(dev, format, ...) 
#define VDBG(dev, format, ...) 
#define ERROR(dev, format, ...) 
#define WARN(dev, format, ...) 

static inline int gadget_is_dualspeed(struct usb_gadget *g) { return g->is_dualspeed; }
static inline int gadget_is_superspeed(struct usb_gadget *g) { return g->is_superspeed; }
static inline int gadget_is_otg(struct usb_gadget *g) { return g->is_otg; }

#define list_entry(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define list_first_entry(ptr, type, member) \
    list_entry((ptr)->next, type, member)

#define list_for_each_entry(pos, head, member) \
    for (pos = list_entry((head)->next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = list_entry(pos->member.next, typeof(*pos), member))

#define list_is_singular(head) ((head)->next == (head)->prev)

#define fallthrough