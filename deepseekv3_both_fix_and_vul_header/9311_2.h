#include <stddef.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define ENODEV 19

struct device;

struct usb_device;
struct urb;

struct usb_interface {
    struct device *dev;
};

struct usb_serial_port {
    unsigned int bulk_out_endpointAddress;
    struct urb *write_urbs[0];
};

struct usb_serial {
    struct usb_device *dev;
    struct usb_interface *interface;
    unsigned int num_bulk_out;
    unsigned int num_ports;
    struct usb_serial_port *port[0];
};

struct urb {
    unsigned int pipe;
};

static inline unsigned int usb_sndbulkpipe(struct usb_device *dev, unsigned int endpoint)
{
    return 0;
}

static inline void dev_err(const struct device *dev, const char *fmt, ...) {}