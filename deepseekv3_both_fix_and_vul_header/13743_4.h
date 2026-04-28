#include <stdint.h>
#include <stdlib.h>

typedef uint32_t u32;

struct device {
    struct device *parent;
};

struct usb_endpoint_descriptor {
    int bEndpointAddress;
};

struct usb_host_interface {
    struct {
        int bNumEndpoints;
    } desc;
    struct {
        struct usb_endpoint_descriptor desc;
    } endpoint[];
};

struct usb_interface {
    struct device dev;
    struct usb_host_interface *cur_altsetting;
};

struct usb_device {
    struct device dev;
};

struct usb_device_id {
    unsigned long driver_info;
};

struct urb;
struct pn533;
struct pn533_phy_ops;
struct pn533_frame_ops;

struct pn533_usb_phy {
    struct pn533 *priv;
    struct usb_device *udev;
    struct usb_interface *interface;
    struct urb *in_urb;
    struct urb *out_urb;
    struct urb *ack_urb;
    unsigned char *ack_buffer;
};

enum pn533_protocol_type {
    PN533_PROTO_REQ_ACK_RESP,
    PN533_PROTO_REQ_RESP
};

#define PN533_DEVICE_STD 0
#define PN533_DEVICE_PASORI 1
#define PN533_DEVICE_ACR122U 2

#define PN533_ALL_PROTOCOLS 0
#define PN533_NO_TYPE_B_PROTOCOLS 0

#define PN533_EXT_FRAME_HEADER_LEN 0
#define PN533_STD_FRAME_MAX_PAYLOAD_LEN 0
#define PN533_STD_FRAME_TAIL_LEN 0

#define GFP_KERNEL 0
#define ENOMEM (-1)
#define ENODEV (-2)
#define EINVAL (-3)

#define IS_ERR(x) (0)
#define PTR_ERR(x) (0)

extern void *devm_kzalloc(struct device *dev, size_t size, int flags);
extern void *kzalloc(size_t size, int flags);
extern void kfree(void *ptr);
extern struct usb_device *usb_get_dev(struct usb_device *dev);
extern struct usb_device *interface_to_usbdev(struct usb_interface *interface);
extern int usb_endpoint_is_bulk_in(struct usb_endpoint_descriptor *epd);
extern int usb_endpoint_is_bulk_out(struct usb_endpoint_descriptor *epd);
extern struct urb *usb_alloc_urb(int iso_packets, int mem_flags);
extern void usb_fill_bulk_urb(struct urb *urb, struct usb_device *dev, unsigned int pipe,
                             void *transfer_buffer, int buffer_length,
                             void *complete_fn, void *context);
extern unsigned int usb_rcvbulkpipe(struct usb_device *dev, int endpoint);
extern unsigned int usb_sndbulkpipe(struct usb_device *dev, int endpoint);
extern void usb_kill_urb(struct urb *urb);
extern void usb_free_urb(struct urb *urb);
extern void usb_put_dev(struct usb_device *dev);
extern void usb_set_intfdata(struct usb_interface *intf, void *data);
extern void nfc_err(struct device *dev, const char *fmt, ...);

extern struct pn533_frame_ops pn533_acr122_frame_ops;
extern const struct pn533_phy_ops usb_phy_ops;
extern int pn533_acr122_poweron_rdr(struct pn533_usb_phy *phy);
extern struct pn533 *pn533_register_device(unsigned long device_type, u32 protocols,
                                         enum pn533_protocol_type protocol_type,
                                         void *phy, const struct pn533_phy_ops *phy_ops,
                                         struct pn533_frame_ops *fops,
                                         struct device *dev, struct device *parent);
extern void pn533_unregister_device(struct pn533 *priv);
extern int pn533_finalize_setup(struct pn533 *priv);
extern void pn533_send_complete(struct urb *urb);