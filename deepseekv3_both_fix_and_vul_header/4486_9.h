#include <stddef.h>
#include <string.h>

struct mutex {};
struct work_struct {};
struct sk_buff_head {};
struct wait_queue_head {};
struct usb_anchor {};
struct net_device_ops {};
struct ethtool_ops {};
struct device_type {};

struct usb_interface {
    struct {
        struct {
            const char *name;
            struct usb_driver *driver;
        } dev;
        struct usb_host_interface *cur_altsetting;
    };
};

struct usb_device_id {
    unsigned long driver_info;
};

struct usbnet {
    struct usb_device *udev;
    struct usb_interface *intf;
    struct driver_info *driver_info;
    const char *driver_name;
    unsigned int msg_enable;
    struct net_device *net;
    unsigned int hard_mtu;
    unsigned int rx_urb_size;
    unsigned int maxpacket;
    unsigned int in;
    unsigned int out;
    unsigned int can_dma_sg;
    void *padding_pkt;
    void *interrupt;
    unsigned int status;
    unsigned int interrupt_count;
    struct {
        void (*func)(unsigned long);
        unsigned long data;
    } bh;
    struct {
        void (*function)(unsigned long);
        unsigned long data;
    } delay;
    struct mutex phy_mutex;
    struct mutex interrupt_mutex;
    struct work_struct kevent;
    struct sk_buff_head rxq;
    struct sk_buff_head txq;
    struct sk_buff_head done;
    struct sk_buff_head rxq_pause;
    struct wait_queue_head wait;
    struct usb_anchor deferred;
};

struct net_device {
    char name[16];
    unsigned char dev_addr[6];
    unsigned int mtu;
    unsigned int hard_header_len;
    const struct net_device_ops *netdev_ops;
    unsigned long watchdog_timeo;
    const struct ethtool_ops *ethtool_ops;
    unsigned int flags;
    unsigned int addr_assign_type;
};

struct usb_host_interface {
    struct {
        unsigned char bInterfaceNumber;
        unsigned char bAlternateSetting;
    } desc;
};

struct driver_info {
    int (*bind)(struct usbnet *, struct usb_interface *);
    int (*unbind)(struct usbnet *, struct usb_interface *);
    unsigned int flags;
    unsigned int in;
    unsigned int out;
    const char *description;
};

struct bus_type {
    const char *bus_name;
};

struct usb_device {
    struct bus_type *bus;
    const char *devpath;
};

struct usb_driver {
    const char *name;
    unsigned int supports_autosuspend;
};

struct net_device_ops usbnet_netdev_ops;
struct ethtool_ops usbnet_ethtool_ops;
struct device_type wlan_type;
struct device_type wwan_type;

enum {
    FLAG_ETHER = 1 << 0,
    FLAG_POINTTOPOINT = 1 << 1,
    FLAG_WLAN = 1 << 2,
    FLAG_WWAN = 1 << 3,
    FLAG_NOARP = 1 << 4,
    FLAG_NO_SETINT = 1 << 5,
    FLAG_SEND_ZLP = 1 << 6,
    FLAG_MULTI_PACKET = 1 << 7,
    FLAG_LINK_INTR = 1 << 8,
    NETIF_MSG_PROBE = 1
};

#define ENODEV 19
#define ENOMEM 12
#define GFP_KERNEL 0
#define ETH_ALEN 6
#define NET_ADDR_RANDOM 1
#define IFF_NOARP 0x80
#define NETIF_MSG_DRV 0x0001
#define NETIF_MSG_PROBE 0x0002
#define NETIF_MSG_LINK 0x0004
#define HZ 100
#define TX_TIMEOUT_JIFFIES (5*HZ)
#define probe NETIF_MSG_PROBE

static inline void *kzalloc(size_t size, int flags) { return NULL; }
static inline void kfree(void *p) {}
static inline void *alloc_etherdev(size_t size) { return NULL; }
static inline void free_netdev(void *dev) {}
static inline void *netdev_priv(void *dev) { return NULL; }
static inline void mutex_init(void *mutex) {}
static inline void init_timer(void *timer) {}
static inline void INIT_WORK(void *work, void *func) {}
static inline void skb_queue_head_init(void *queue) {}
static inline void init_waitqueue_head(void *wq) {}
static inline void init_usb_anchor(void *anchor) {}
static inline int netif_msg_init(int level, int value) { return 0; }
static inline int ether_addr_equal(const unsigned char *addr1, const unsigned char *addr2) { return 0; }
static inline void SET_NETDEV_DEV(void *net, void *dev) {}
static inline void SET_NETDEV_DEVTYPE(void *net, void *type) {}
static inline int register_netdev(void *net) { return 0; }
static inline void netif_info(void *dev, int type, void *net, const char *fmt, ...) {}
static inline void usb_set_intfdata(void *intf, void *data) {}
static inline void netif_device_attach(void *net) {}
static inline void usbnet_link_change(void *dev, int link, int speed) {}
static inline void usb_free_urb(void *urb) {}
static inline int usbnet_get_endpoints(void *dev, void *intf) { return 0; }
static inline unsigned int usb_rcvbulkpipe(void *dev, unsigned int endpoint) { return 0; }
static inline unsigned int usb_sndbulkpipe(void *dev, unsigned int endpoint) { return 0; }
static inline int usb_set_interface(void *dev, int ifnum, int alt) { return 0; }
static inline int init_status(void *dev, void *intf) { return 0; }
static inline unsigned int usb_maxpacket(void *dev, unsigned int pipe, int out) { return 0; }
static inline void usbnet_update_max_qlen(void *dev) {}
static inline void pm_runtime_enable(void *dev) {}
static inline struct usb_driver *to_usb_driver(void *driver) { return NULL; }
static inline struct usb_device *interface_to_usbdev(void *intf) { return NULL; }
static inline void dev_dbg(void *dev, const char *fmt, ...) {}
static inline void usbnet_bh(unsigned long data) {}
static inline void usbnet_deferred_kevent(struct work_struct *work) {}

extern int msg_level;
extern unsigned char node_id[ETH_ALEN];