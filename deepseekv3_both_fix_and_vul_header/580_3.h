#include <stddef.h>

#define PIPE_CONTROL 0
#define PIPE_ISOCHRONOUS 1
#define PIPE_BULK 2
#define PIPE_INTERRUPT 3
#define EINVAL 22

struct usb_device;
struct usb_endpoint_descriptor {
    unsigned char bmAttributes;
};
struct usb_host_endpoint {
    struct usb_endpoint_descriptor desc;
};

static inline int usb_pipetype(unsigned int pipe) { return (pipe >> 30) & 3; }
static inline int usb_endpoint_type(struct usb_endpoint_descriptor *desc) { return desc->bmAttributes & 0x03; }
static inline struct usb_host_endpoint *usb_pipe_endpoint(struct usb_device *dev, unsigned int pipe) { return NULL; }