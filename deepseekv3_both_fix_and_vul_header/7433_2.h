#include <stdint.h>
#include <stdbool.h>
#include <linux/usb/ch9.h>

#define XUSB_MAX_ENDPOINTS 16
#define XUSB_EP_CFG_STALL_MASK 0x1

typedef uint16_t u16;
typedef uint32_t u32;
typedef uint8_t u8;

struct usb_request {
    void *buf;
    unsigned int length;
};

struct xusb_req {
    struct usb_request usb_req;
};

struct xusb_ep {
    unsigned int offset;
    bool is_in;
};

struct xusb_udc {
    struct xusb_ep ep[XUSB_MAX_ENDPOINTS];
    struct xusb_req *req;
    void *dev;
    struct {
        u8 bRequestType;
        u16 wIndex;
    } setup;
    u32 (*read_fn)(u32 addr);
    u32 addr;
    bool remote_wkp;
};

static int __xudc_ep0_queue(struct xusb_ep *ep0, struct xusb_req *req);
static void xudc_ep0_stall(struct xusb_udc *udc);
static void dev_err(void *dev, const char *msg);
static u16 cpu_to_le16(u16 val);