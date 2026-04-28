#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

typedef uint32_t u32;

struct hid_device {
    struct {
        struct {
            void* parent;
        } dev;
        uint16_t version;
        uint8_t country;
        u32 quirks;
    };
};

struct usb_interface {
    struct usb_host_interface* cur_altsetting;
};

struct usb_host_interface {
    struct {
        uint8_t bInterfaceSubClass;
        uint8_t bInterfaceProtocol;
        uint8_t bNumEndpoints;
        uint8_t bInterfaceNumber;
    } desc;
    struct usb_host_interface* endpoint;
};

struct usb_device {
    struct {
        struct {
            uint16_t idVendor;
            uint16_t idProduct;
        } descriptor;
    };
};

struct hid_descriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint16_t bcdHID;
    uint8_t bCountryCode;
    uint8_t bNumDescriptors;
    struct hid_class_descriptor {
        uint8_t bDescriptorType;
        uint16_t wDescriptorLength;
    } desc[1];
};

#define HID_DT_HID 0x21
#define HID_DT_REPORT 0x22
#define HID_MAX_DESCRIPTOR_SIZE 4096

#define USB_INTERFACE_SUBCLASS_BOOT 1
#define USB_INTERFACE_PROTOCOL_KEYBOARD 1
#define USB_INTERFACE_PROTOCOL_MOUSE 2

#define HID_QUIRK_IGNORE 0x01
#define HID_QUIRK_NOGET 0x02

#define ENODEV 19
#define EINVAL 22
#define ENOMEM 12

#define GFP_KERNEL 0

#define le16_to_cpu(x) (x)
#define min_t(type, x, y) ((x) < (y) ? (x) : (y))

static inline struct usb_interface* to_usb_interface(void* p) { return (struct usb_interface*)p; }
static inline struct usb_device* interface_to_usbdev(struct usb_interface* intf) { return (struct usb_device*)intf; }
static inline u32 usbhid_lookup_quirk(uint16_t vendor, uint16_t product) { return 0; }
static inline int usb_get_extra_descriptor(void* interface, int type, struct hid_descriptor** hdesc) { return 0; }
static inline void hid_set_idle(struct usb_device* dev, int ifnum, int duration, int report) {}
static inline int hid_get_class_descriptor(struct usb_device* dev, int ifnum, int type, char* buf, int size) { return 0; }
static inline int hid_parse_report(struct hid_device* hid, char* rdesc, int rsize) { return 0; }
static inline void* kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void* ptr) { free(ptr); }
static inline void dbg_hid(const char* fmt, ...) {}