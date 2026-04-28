#include <stdint.h>

struct device {
    // Minimal device structure
};

struct usb_ss_ep_comp_descriptor {
    // Minimal descriptor structure
};

struct usb_host_interface {
    struct usb_host_endpoint *endpoint;
};

struct usb_device {
    struct usb_bus *bus;
    struct {
        uint16_t idVendor;
        uint16_t idProduct;
    } descriptor;
    struct {
        struct {
            uint8_t bMaxPower;
        } desc;
    } *actconfig;
    unsigned int speed;
    struct device dev;
};

struct usb_interface {
    struct usb_host_interface *altsetting;
};

struct usb_device_id {
    unsigned long driver_info;
};

struct usb_host_endpoint {
    struct usb_ss_ep_comp_descriptor ss_ep_comp;
};

struct usb_hcd {
    struct {
        const char *description;
    } *driver;
    unsigned int can_do_streams;
};

struct usb_bus {
    unsigned int sg_tablesize;
    const char *bus_name;
};

#define US_FL_IGNORE_UAS (1 << 0)
#define US_FL_MAX_SECTORS_240 (1 << 1)
#define USB_SPEED_SUPER 3

static inline uint16_t le16_to_cpu(uint16_t val) { return val; }

static inline struct usb_device *interface_to_usbdev(struct usb_interface *intf) { return 0; }
static inline struct usb_hcd *bus_to_hcd(struct usb_bus *bus) { return 0; }
static inline int uas_find_uas_alt_setting(struct usb_interface *intf) { return 0; }
static inline int uas_find_endpoints(struct usb_host_interface *alt, struct usb_host_endpoint **eps) { return 0; }
static inline void usb_stor_adjust_quirks(struct usb_device *udev, unsigned long *flags) {}
static inline int usb_ss_max_streams(const struct usb_ss_ep_comp_descriptor *comp) { return 0; }
static inline struct usb_bus *hcd_to_bus(struct usb_hcd *hcd) { return 0; }

void dev_warn(struct device *dev, const char *fmt, ...);