#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <endian.h>

#define USB_8DEV_DATA_START 0x55
#define USB_8DEV_DATA_END 0xAA
#define USB_8DEV_RTR 0x01
#define USB_8DEV_EXTID 0x02
#define USB_8DEV_ENDP_DATA_TX 0x01
#define MAX_TX_URBS 10
#define GFP_ATOMIC 0
#define CAN_RTR_FLAG 0x40000000
#define CAN_EFF_FLAG 0x80000000
#define CAN_ERR_MASK 0x1FFFFFFF
#define NETDEV_TX_OK 0
#define NETDEV_TX_BUSY 1
#define URB_NO_TRANSFER_DMA_MAP (1 << 0)
#define ENODEV 19

typedef unsigned int netdev_tx_t;
typedef unsigned int gfp_t;
typedef unsigned char u8;
typedef uint32_t u32;
typedef uint32_t __be32;
typedef uint64_t dma_addr_t;

struct net_device_stats {
    unsigned long tx_dropped;
};

struct sk_buff {
    void *data;
};

struct net_device {
    struct net_device_stats stats;
};

struct urb {
    dma_addr_t transfer_dma;
    unsigned int transfer_flags;
};

struct usb_device;

struct can_frame {
    uint32_t can_id;
    uint8_t len;
    uint8_t data[8];
};

struct can_priv {
    uint32_t ctrlmode;
};

struct usb_8dev_tx_urb_context {
    struct usb_8dev_priv *priv;
    u32 echo_index;
};

struct usb_8dev_priv {
    struct usb_device *udev;
    struct can_priv can;
    struct {
        void *anchor;
    } tx_submitted;
    int active_tx_urbs;
    struct usb_8dev_tx_urb_context tx_contexts[MAX_TX_URBS];
};

struct usb_8dev_tx_msg {
    u8 begin;
    u8 flags;
    __be32 id;
    u8 dlc;
    u8 data[8];
    u8 end;
};

static inline void *netdev_priv(struct net_device *dev) { return NULL; }
static inline int can_dropped_invalid_skb(struct net_device *dev, struct sk_buff *skb) { return 0; }
static inline struct urb *usb_alloc_urb(int iso_packets, gfp_t mem_flags) { return NULL; }
static inline void *usb_alloc_coherent(struct usb_device *dev, size_t size, gfp_t mem_flags, dma_addr_t *dma) { return NULL; }
static inline void usb_free_coherent(struct usb_device *dev, size_t size, void *addr, dma_addr_t dma) {}
static inline void usb_free_urb(struct urb *urb) {}
static inline void usb_fill_bulk_urb(struct urb *urb, struct usb_device *dev, unsigned int pipe, void *buf, int buf_len, void (*complete_fn)(struct urb *), void *context) {}
static inline void usb_anchor_urb(struct urb *urb, void *anchor) {}
static inline void usb_unanchor_urb(struct urb *urb) {}
static inline int usb_submit_urb(struct urb *urb, gfp_t mem_flags) { return 0; }
static inline void can_put_echo_skb(struct sk_buff *skb, struct net_device *dev, unsigned int idx, unsigned int frame_len) {}
static inline void can_free_echo_skb(struct net_device *dev, unsigned int idx, void *unused) {}
static inline int atomic_read(int *v) { return *v; }
static inline void atomic_inc(int *v) { (*v)++; }
static inline void atomic_dec(int *v) { (*v)--; }
static inline void netif_stop_queue(struct net_device *dev) {}
static inline void netif_device_detach(struct net_device *dev) {}
static inline void dev_kfree_skb(struct sk_buff *skb) {}
static inline void netdev_err(struct net_device *dev, const char *fmt, ...) {}
static inline void netdev_warn(struct net_device *dev, const char *fmt, ...) {}
static inline unsigned int usb_sndbulkpipe(struct usb_device *dev, unsigned int endpoint) { return 0; }
static inline uint8_t can_get_cc_dlc(struct can_frame *cf, uint32_t ctrlmode) { return 0; }
static inline __be32 cpu_to_be32(uint32_t x) { return htobe32(x); }
static inline int unlikely(int x) { return x; }
static inline void usb_8dev_write_bulk_callback(struct urb *urb) {}