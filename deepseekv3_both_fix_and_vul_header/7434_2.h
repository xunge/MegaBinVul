#include <stdint.h>

#define USB_REQ_SET_FEATURE 0x03
#define USB_RECIP_DEVICE 0x00
#define USB_RECIP_ENDPOINT 0x02
#define USB_DEVICE_TEST_MODE 0x02
#define USB_DEVICE_REMOTE_WAKEUP 0x01
#define USB_ENDPOINT_NUMBER_MASK 0x0f
#define USB_ENDPOINT_DIR_MASK 0x80
#define XUSB_MAX_ENDPOINTS 32
#define XUSB_EP_CFG_STALL_MASK 0x00000001
#define XUSB_EP_CFG_DATA_TOGGLE_MASK 0x00000002

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

struct xusb_req {
    struct {
        u32 length;
    } usb_req;
};

struct xusb_ep {
    u32 offset;
    u32 is_in;
};

struct xusb_udc {
    struct xusb_ep ep[XUSB_MAX_ENDPOINTS];
    struct xusb_req *req;
    struct {
        u8 bRequest;
        u8 bRequestType;
        u16 wValue;
        u16 wIndex;
    } setup;
    int remote_wkp;
    u32 (*read_fn)(u32);
    void (*write_fn)(u32, u32, u32);
    u32 addr;
    void *dev;
};

void xudc_ep0_stall(struct xusb_udc *udc);
int __xudc_ep0_queue(struct xusb_ep *ep0, struct xusb_req *req);
void dev_err(void *dev, const char *fmt, ...);