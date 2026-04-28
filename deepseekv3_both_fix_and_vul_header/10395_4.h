#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ETH_ALEN 6
#define TX_TIMEOUT 0
#define RX_PKT_SZ 0
#define RX_MAX_BURST 0
#define PKT_SZ 0
#define OpTxMerge 0
#define OpRxMerge 0
#define OpLenInclude 0
#define Op3MemWaits 0
#define LEDLink 0
#define RxEnable 0
#define RxPolarity 0
#define RxMultiCast 0
#define TxBufCount 0
#define RxBufCount 0
#define StationAddr0 0
#define EthStats 0
#define MaxBurst 0
#define OpModes 0
#define LEDCtrl 0
#define RxUnit 0
#define GFP_KERNEL 0
#define EIO 5
#define ENOMEM 12
#define KERN_INFO ""

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

struct device {
    const char *name;
};

struct usb_interface_descriptor {
    uint8_t bInterfaceNumber;
};

struct usb_host_interface {
    struct usb_interface_descriptor desc;
};

struct usb_interface {
    struct device dev;
    struct usb_host_interface *altsetting;
};

struct usb_device_descriptor {
    uint16_t idVendor;
    uint16_t idProduct;
    uint16_t bcdDevice;
};

struct usb_bus {
    char *bus_name;
};

struct usb_device {
    struct usb_device_descriptor descriptor;
    struct usb_bus *bus;
    char *devpath;
};

struct net_device {
    char *name;
    u8 dev_addr[ETH_ALEN];
    void *netdev_ops;
    unsigned int watchdog_timeo;
    void *ethtool_ops;
};

struct urb {
    void *context;
};

struct timer_list {
    unsigned long data;
    void (*function)(unsigned long);
};

struct catc {
    struct usb_device *usbdev;
    struct net_device *netdev;
    void *tx_lock;
    void *ctrl_lock;
    struct timer_list timer;
    struct urb *ctrl_urb;
    struct urb *tx_urb;
    struct urb *rx_urb;
    struct urb *irq_urb;
    u8 rx_buf[0];
    u8 irq_buf[2];
    u8 multicast[64];
    u8 rxmode[2];
    int is_f5u011;
    int recq_sz;
    unsigned long last_stats;
};

struct usb_device_id {
    uint16_t idVendor;
    uint16_t idProduct;
};

static struct {
    int dummy;
} catc_netdev_ops, ops;

static unsigned long jiffies;

static void catc_stats_timer(unsigned long data) {}
static void catc_ctrl_done(struct urb *urb) {}
static void catc_tx_done(struct urb *urb) {}
static void catc_rx_done(struct urb *urb) {}
static void catc_irq_done(struct urb *urb) {}
static void catc_write_mem(struct catc *catc, u16 addr, void *buf, int len) {}
static void catc_read_mem(struct catc *catc, u16 addr, void *buf, int len) {}
static void catc_set_reg(struct catc *catc, u8 reg, u8 val) {}
static void catc_get_mac(struct catc *catc, u8 *mac) {}
static void catc_multicast(u8 *addr, u8 *multicast) {}
static void catc_reset(struct catc *catc) {}
static void f5u011_rxmode(struct catc *catc, u8 *rxmode) {}
static void atomic_set(int *v, int i) { *v = i; }

static uint16_t le16_to_cpu(uint16_t val) { return val; }
static void *interface_to_usbdev(struct usb_interface *intf) { return NULL; }
static int usb_set_interface(struct usb_device *dev, int ifnum, int alternate) { return 0; }
static struct net_device *alloc_etherdev(int size) { return NULL; }
static void *netdev_priv(struct net_device *dev) { return NULL; }
static void spin_lock_init(void *lock) {}
static void init_timer(struct timer_list *timer) {}
static struct urb *usb_alloc_urb(int iso_packets, int mem_flags) { return NULL; }
static void usb_free_urb(struct urb *urb) {}
static void usb_fill_control_urb(struct urb *urb, struct usb_device *dev,
                unsigned int pipe, void *setup_packet, void *transfer_buffer,
                int buffer_length, void (*complete_fn)(struct urb *), void *context) {}
static void usb_fill_bulk_urb(struct urb *urb, struct usb_device *dev,
                unsigned int pipe, void *transfer_buffer, int buffer_length,
                void (*complete_fn)(struct urb *), void *context) {}
static void usb_fill_int_urb(struct urb *urb, struct usb_device *dev,
                unsigned int pipe, void *transfer_buffer, int buffer_length,
                void (*complete_fn)(struct urb *), void *context, int interval) {}
static void usb_set_intfdata(struct usb_interface *intf, void *data) {}
static void SET_NETDEV_DEV(struct net_device *dev, struct device *device) {}
static int register_netdev(struct net_device *dev) { return 0; }
static void free_netdev(struct net_device *dev) {}
static void dev_err(struct device *dev, const char *fmt, ...) {}
static void dev_dbg(struct device *dev, const char *fmt, ...) {}
static void dev_warn(struct device *dev, const char *fmt, ...) {}
static void printk(const char *fmt, ...) {}
static void eth_broadcast_addr(u8 *addr) {}
static unsigned int usb_sndctrlpipe(struct usb_device *dev, unsigned int endpoint) { return 0; }
static unsigned int usb_sndbulkpipe(struct usb_device *dev, unsigned int endpoint) { return 0; }
static unsigned int usb_rcvbulkpipe(struct usb_device *dev, unsigned int endpoint) { return 0; }
static unsigned int usb_rcvintpipe(struct usb_device *dev, unsigned int endpoint) { return 0; }