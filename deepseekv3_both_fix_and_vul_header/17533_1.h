#include <stdint.h>

struct usb_interface_cache {
    int num_altsetting;
    struct usb_host_interface *altsetting;
};

struct usb_host_interface {
    struct {
        uint8_t bNumEndpoints;
    } desc;
    struct {
        struct {
            uint16_t wMaxPacketSize;
        } desc;
    } endpoint[1];
};

struct usb_config {
    struct usb_interface_cache **intf_cache;
};

struct usb_device {
    struct usb_config *actconfig;
};

struct gspca_dev {
    struct usb_device *dev;
    struct {
        int width;
    } pixfmt;
};

#define ENODEV 19

static inline uint16_t cpu_to_le16(uint16_t x) {
    return x;
}