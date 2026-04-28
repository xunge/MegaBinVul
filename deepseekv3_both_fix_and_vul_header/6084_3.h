#include <stddef.h>
#include <stdbool.h>

#define USB_ENDPOINT_XFER_BULK 2
#define USB_DIR_IN 0x80
#define USB_DIR_OUT 0x00
#define GFP_KERNEL 0
#define NET_NAME_UNKNOWN 0
#define MUX_BULK_RX_BUF_COUNT 4
#define MUX_BULK_RX_BUF_SIZE 2048
#define MUX_BULK_TX_BUF_SIZE 2048

struct device {
    int dummy;
};

struct usb_interface {
    struct device dev;
};

struct usb_endpoint_descriptor;
struct urb;
struct net_device;
struct device_type;

struct hso_device {
    struct {
        void *dev_net;
    } port_data;
};

struct hso_net {
    struct net_device *net;
    struct hso_device *parent;
    struct usb_endpoint_descriptor *in_endp;
    struct usb_endpoint_descriptor *out_endp;
    struct urb *mux_bulk_rx_urb_pool[MUX_BULK_RX_BUF_COUNT];
    unsigned char *mux_bulk_rx_buf_pool[MUX_BULK_RX_BUF_COUNT];
    struct urb *mux_bulk_tx_urb;
    unsigned char *mux_bulk_tx_buf;
};

extern struct device_type hso_type;
extern void *kzalloc(size_t size, int flags);
extern void *usb_alloc_urb(int iso_packets, int mem_flags);
extern void dev_err(struct device *dev, const char *fmt, ...);
extern void *netdev_priv(struct net_device *dev);
extern struct net_device *alloc_netdev(int size, const char *name, int name_assign_type, void (*setup)(struct net_device *));
extern int register_netdev(struct net_device *dev);
extern void hso_net_init(struct net_device *net);
extern void hso_log_port(struct hso_device *hso_dev);
extern void hso_create_rfkill(struct hso_device *hso_dev, struct usb_interface *interface);
extern void add_net_device(struct hso_device *hso_dev);
extern void hso_free_net_device(struct hso_device *hso_dev, bool free_interface);
extern struct usb_endpoint_descriptor *hso_get_ep(struct usb_interface *interface, int type, int dir);
extern struct hso_device *hso_create_device(struct usb_interface *interface, int port_spec);

#define SET_NETDEV_DEV(net, dev) 
#define SET_NETDEV_DEVTYPE(net, type)