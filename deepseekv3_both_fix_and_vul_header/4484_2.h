#include <stddef.h>
#include <stdarg.h>

struct usb_endpoint_descriptor {
    int bEndpointAddress;
    int bmAttributes;
    int wMaxPacketSize;
    int bInterval;
    int bRefresh;
    int bSynchAddress;
    int desc;
};

struct usb_host_interface {
    struct usb_endpoint_descriptor *endpoint;
    struct {
        int bNumEndpoints;
    } desc;
    struct usb_host_interface *cur_altsetting;
};

struct usb_interface {
    struct usb_host_interface *cur_altsetting;
};

struct usb_device;
struct device;

struct usb_cdc_union_desc {
    int bMasterInterface0;
    int bSlaveInterface0;
};

struct ims_pcu {
    struct usb_device *udev;
    struct device *dev;
    struct usb_interface *ctrl_intf;
    struct usb_interface *data_intf;
    struct usb_endpoint_descriptor *ep_ctrl;
    struct usb_endpoint_descriptor *ep_out;
    struct usb_endpoint_descriptor *ep_in;
    size_t max_ctrl_size;
    size_t max_out_size;
    size_t max_in_size;
};

#define EINVAL 22

static const struct usb_cdc_union_desc *ims_pcu_get_cdc_union_desc(struct usb_interface *intf) { return NULL; }
static struct usb_interface *usb_ifnum_to_if(struct usb_device *udev, int ifnum) { return NULL; }
static size_t usb_endpoint_maxp(const struct usb_endpoint_descriptor *ep) { return 0; }
static int usb_endpoint_is_bulk_out(const struct usb_endpoint_descriptor *ep) { return 0; }
static int usb_endpoint_is_bulk_in(const struct usb_endpoint_descriptor *ep) { return 0; }
static void dev_err(struct device *dev, const char *fmt, ...) {}