#include <stdint.h>
#include <errno.h>

struct usb_device {
    struct usb_config_descriptor *actconfig;
};

struct usb_config_descriptor {
    struct usb_interface_cache **intf_cache;
};

struct usb_interface_cache {
    struct usb_host_interface *altsetting;
};

struct usb_host_interface {
    struct {
        struct usb_endpoint_descriptor {
            uint16_t wMaxPacketSize;
        } desc;
    } *endpoint;
};

struct gspca_dev {
    struct usb_device *dev;
    int iface;
    struct {
        int width;
    } pixfmt;
};

static inline uint16_t le16_to_cpu(uint16_t x) { return x; }
static inline uint16_t cpu_to_le16(uint16_t x) { return x; }
int usb_set_interface(struct usb_device *dev, int iface, int alt);
void pr_err(const char *fmt, ...);