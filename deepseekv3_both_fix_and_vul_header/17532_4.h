#include <stdio.h>
#include <stdint.h>

struct usb_device;
struct usb_interface;

struct usb_endpoint_descriptor {
    uint16_t wMaxPacketSize;
};

struct usb_interface_descriptor {
    int bNumEndpoints;
};

struct usb_host_interface {
    struct usb_interface_descriptor desc;
    struct {
        struct usb_endpoint_descriptor desc;
    } endpoint[1];
};

struct gspca_dev {
    struct usb_device *dev;
    int iface;
    int alt;
};

#define EIO 5
#define ENODEV 19
#define pr_err(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)

static inline struct usb_interface *usb_ifnum_to_if(struct usb_device *dev, int iface) { return NULL; }
static inline struct usb_host_interface *usb_altnum_to_altsetting(struct usb_interface *intf, int alt) { return NULL; }
static inline uint16_t le16_to_cpu(uint16_t val) { return val; }