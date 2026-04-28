#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define PCAN_USB_MAX_TX_URBS 10
#define PCAN_USB_MAX_CMD_LEN 64
#define PCAN_USB_DRIVER_NAME "pcan_usb"
#define PCAN_USB_STATE_CONNECTED 1
#define GFP_KERNEL 0
#define IFF_ECHO 0x40000
#define ENOMEM 12

typedef uint16_t u16;

struct usb_device {
    struct {
        u16 bcdDevice;
    } descriptor;
};

struct usb_interface {
    void *dev;
};

struct net_device {
    void *dev;
    int flags;
    int dev_id;
    void *netdev_ops;
};

struct can_priv {
    unsigned int clock;
    const void *bittiming_const;
    int (*do_set_bittiming)(struct net_device *);
    const void *data_bittiming_const;
    int (*do_set_data_bittiming)(struct net_device *);
    int (*do_set_mode)(struct net_device *, int);
    int (*do_get_berr_counter)(const struct net_device *, void *);
    unsigned int ctrlmode_supported;
};

struct usb_anchor {
    int dummy;
};

struct peak_usb_device;

struct peak_usb_adapter {
    int sizeof_dev_private;
    int (*dev_init)(struct peak_usb_device *dev);
    int (*dev_set_bus)(struct peak_usb_device *dev, int on);
    int (*dev_get_device_id)(struct peak_usb_device *dev, int *device_number);
    const void *bittiming_const;
    const void *data_bittiming_const;
    unsigned int clock;
    unsigned int ctrlmode_supported;
    int (*do_get_berr_counter)(const struct net_device *netdev, void *bec);
    int ep_msg_in;
    int *ep_msg_out;
    const char *name;
};

struct peak_usb_device {
    struct can_priv can;
    struct peak_usb_adapter *adapter;
    struct usb_device *udev;
    struct net_device *netdev;
    struct peak_usb_device *prev_siblings;
    struct peak_usb_device *next_siblings;
    int active_tx_urbs;
    struct usb_anchor rx_submitted;
    struct usb_anchor tx_submitted;
    uint8_t *cmd_buf;
    int ctrl_idx;
    int state;
    int device_rev;
    int device_number;
    struct {
        int echo_index;
    } tx_contexts[PCAN_USB_MAX_TX_URBS];
    int ep_msg_in;
    int ep_msg_out;
};

struct net_device_ops {
    int dummy;
} peak_usb_netdev_ops;

static inline struct usb_device *interface_to_usbdev(struct usb_interface *intf) { return NULL; }
static inline void *usb_get_intfdata(struct usb_interface *intf) { return NULL; }
static inline void usb_set_intfdata(struct usb_interface *intf, void *data) {}
static inline uint16_t le16_to_cpu(uint16_t val) { return val; }
static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline void atomic_set(int *v, int i) { *v = i; }
static inline void init_usb_anchor(struct usb_anchor *anchor) {}
static inline struct net_device *alloc_candev(int size, int tx_urbs) { return NULL; }
static inline void free_candev(struct net_device *dev) {}
static inline int register_candev(struct net_device *dev) { return 0; }
static inline void unregister_candev(struct net_device *dev) {}
static inline void *netdev_priv(struct net_device *dev) { return NULL; }
static inline void SET_NETDEV_DEV(struct net_device *dev, void *intf) {}
static inline void dev_err(void *dev, const char *fmt, ...) {}
static inline void netdev_info(struct net_device *dev, const char *fmt, ...) {}

static int peak_usb_set_bittiming(struct net_device *netdev) { return 0; }
static int peak_usb_set_data_bittiming(struct net_device *netdev) { return 0; }
static int peak_usb_set_mode(struct net_device *netdev, int mode) { return 0; }