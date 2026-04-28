#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define HANDSPRING_VENDOR_ID 0x082d
#define KYOCERA_VENDOR_ID 0x0c88
#define ENODEV 19
#define ENOMEM 12
#define GFP_KERNEL 0

struct usb_device_descriptor {
    uint16_t idVendor;
};

struct device {
    // minimal device structure
};

struct usb_interface {
    struct device dev;
};

struct urb {
    void *context;
};

struct usb_serial_port {
    struct urb *read_urbs[8];
    struct urb *read_urb;
    unsigned int bulk_in_endpointAddress;
    void *bulk_in_buffer;
    int bulk_in_size;
    struct urb *interrupt_in_urb;
    unsigned int interrupt_in_endpointAddress;
    void *interrupt_in_buffer;
    void *bulk_in_buffers[8];
};

struct usb_serial {
    struct usb_device *dev;
    struct usb_interface *interface;
    unsigned int num_bulk_in;
    unsigned int num_interrupt_in;
    struct usb_serial_port *port[2];
};

struct usb_device {
    struct usb_device_descriptor descriptor;
};

static inline uint16_t le16_to_cpu(uint16_t val) { return val; }
static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline void dev_err(struct device *dev, const char *fmt, ...) {}