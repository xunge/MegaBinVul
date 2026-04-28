#include <stdint.h>
#include <stddef.h>

struct usb_hcd;
struct usb_device;

struct usb_endpoint_descriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint8_t bEndpointAddress;
    uint8_t bmAttributes;
    uint16_t wMaxPacketSize;
    uint8_t bInterval;
};

struct urb {
    struct usb_device *dev;
    struct {
        struct usb_endpoint_descriptor desc;
    } *ep;
};

struct max3421_hcd {
    int urb_done;
    struct urb *curr_urb;
    int lock;
};

typedef uint8_t u8;

static inline struct max3421_hcd *hcd_to_max3421(struct usb_hcd *hcd)
{
    return (struct max3421_hcd *)0;
}

static inline u8 spi_rd8(struct usb_hcd *hcd, int reg)
{
    return 0;
}

#define MAX3421_REG_HRSL 0
#define MAX3421_HRSL_RCVTOGRD_BIT 0
#define MAX3421_HRSL_SNDTOGRD_BIT 1

static inline int usb_endpoint_num(const struct usb_endpoint_descriptor *desc)
{
    return desc->bEndpointAddress & 0x0F;
}

static inline void usb_settoggle(struct usb_device *dev, int ep, int dir, int toggle)
{
}

static inline void usb_hcd_unlink_urb_from_ep(struct usb_hcd *hcd, struct urb *urb)
{
}

static inline void usb_hcd_giveback_urb(struct usb_hcd *hcd, struct urb *urb, int status)
{
}

static inline void spin_lock_irqsave(int *lock, unsigned long flags)
{
}

static inline void spin_unlock_irqrestore(int *lock, unsigned long flags)
{
}