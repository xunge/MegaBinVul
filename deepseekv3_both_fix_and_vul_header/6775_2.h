#include <stddef.h>

#define USBIP_DIR_IN 1
#define USBIP_DIR_OUT 0

struct device {
    // minimal device structure
};

struct usb_endpoint_descriptor {
    unsigned char bmAttributes;
};

struct usb_host_endpoint {
    struct usb_endpoint_descriptor desc;
};

struct usb_device {
    struct device dev;
    struct usb_host_endpoint *ep_in[128];
    struct usb_host_endpoint *ep_out[128];
};

struct stub_device {
    struct usb_device *udev;
};

static inline int usb_endpoint_xfer_control(const struct usb_endpoint_descriptor *epd) {
    return (epd->bmAttributes & 0x03) == 0;
}

static inline int usb_endpoint_xfer_bulk(const struct usb_endpoint_descriptor *epd) {
    return (epd->bmAttributes & 0x03) == 2;
}

static inline int usb_endpoint_xfer_int(const struct usb_endpoint_descriptor *epd) {
    return (epd->bmAttributes & 0x03) == 3;
}

static inline int usb_endpoint_xfer_isoc(const struct usb_endpoint_descriptor *epd) {
    return (epd->bmAttributes & 0x03) == 1;
}

static inline int usb_sndctrlpipe(struct usb_device *udev, int epnum) { return 0; }
static inline int usb_rcvctrlpipe(struct usb_device *udev, int epnum) { return 0; }
static inline int usb_sndbulkpipe(struct usb_device *udev, int epnum) { return 0; }
static inline int usb_rcvbulkpipe(struct usb_device *udev, int epnum) { return 0; }
static inline int usb_sndintpipe(struct usb_device *udev, int epnum) { return 0; }
static inline int usb_rcvintpipe(struct usb_device *udev, int epnum) { return 0; }
static inline int usb_sndisocpipe(struct usb_device *udev, int epnum) { return 0; }
static inline int usb_rcvisocpipe(struct usb_device *udev, int epnum) { return 0; }

static inline void dev_err(const struct device *dev, const char *fmt, ...) {}
#define BUG() do { } while (0)