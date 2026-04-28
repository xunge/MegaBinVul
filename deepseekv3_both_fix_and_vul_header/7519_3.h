#include <stdint.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_TX_URBS 10
#define CPC_HEADER_SIZE 4
#define CPC_MSG_HEADER_LEN 4
#define CPC_CAN_MSG_MIN_SIZE 8
#define CPC_TX_QUEUE_TRIGGER_LOW 5
#define CAN_ERR_MASK 0x1FFFFFFFU
#define CAN_RTR_FLAG 0x40000000U
#define CAN_EFF_FLAG 0x80000000U
#define GFP_ATOMIC 0
#define NETDEV_TX_OK 0
#define NETDEV_TX_BUSY 1
#define URB_NO_TRANSFER_DMA_MAP (1 << 0)
#define ENODEV 19
#define CPC_CMD_TYPE_EXT_RTR_FRAME 0
#define CPC_CMD_TYPE_RTR_FRAME 1
#define CPC_CMD_TYPE_EXT_CAN_FRAME 2
#define CPC_CMD_TYPE_CAN_FRAME 3

typedef unsigned int netdev_tx_t;
typedef uint8_t u8;
typedef int atomic_t;

struct sk_buff {
    void *data;
};

struct net_device_stats {
    unsigned long tx_dropped;
};

struct net_device {
    struct net_device_stats stats;
};

struct urb {
    void *transfer_dma;
    unsigned int transfer_flags;
};

struct ems_tx_urb_context {
    struct ems_usb *dev;
    unsigned int echo_index;
};

struct cpc_can_msg {
    uint32_t id;
    uint8_t length;
    uint8_t msg[8];
};

struct ems_cpc_msg {
    u8 type;
    u8 length;
    u8 msgid;
    u8 unused;
    union {
        struct cpc_can_msg can_msg;
    } msg;
};

struct can_frame {
    uint32_t can_id;
    uint8_t len;
    uint8_t data[8];
};

struct ems_usb {
    void *udev;
    struct ems_tx_urb_context tx_contexts[MAX_TX_URBS];
    int free_slots;
    atomic_t active_tx_urbs;
    void *tx_submitted;
};

static inline uint32_t cpu_to_le32(uint32_t x) { return x; }
static inline void atomic_inc(atomic_t *v) { (*v)++; }
static inline void atomic_dec(atomic_t *v) { (*v)--; }
static inline int atomic_read(const atomic_t *v) { return *v; }
static inline int unlikely(int x) { return x; }
static inline void netif_trans_update(struct net_device *dev) {}
static inline void netif_stop_queue(struct net_device *dev) {}
static inline void netif_device_detach(struct net_device *dev) {}
static inline void usb_anchor_urb(struct urb *urb, void *anchor) {}
static inline void usb_unanchor_urb(struct urb *urb) {}
static inline int usb_submit_urb(struct urb *urb, int flags) { return 0; }
static inline struct urb *usb_alloc_urb(int iso_packets, int mem_flags) { return malloc(sizeof(struct urb)); }
static inline void usb_free_urb(struct urb *urb) { free(urb); }
static inline void *usb_alloc_coherent(void *dev, size_t size, int mem_flags, void *dma) { return malloc(size); }
static inline void usb_free_coherent(void *dev, size_t size, void *addr, void *dma) { free(addr); }
static inline void usb_fill_bulk_urb(struct urb *urb, void *dev, void *pipe, void *buf, int size, void *complete_fn, void *context) {}
static inline void dev_kfree_skb(struct sk_buff *skb) { free(skb); }
static inline int can_dropped_invalid_skb(struct net_device *dev, struct sk_buff *skb) { return 0; }
static inline void can_put_echo_skb(struct sk_buff *skb, struct net_device *dev, unsigned int idx, unsigned int frame_len) {}
static inline void can_free_echo_skb(struct net_device *dev, unsigned int idx, void *unused) {}
static inline void *netdev_priv(struct net_device *dev) { return NULL; }
static inline void netdev_err(struct net_device *dev, const char *fmt, ...) {}
static inline void netdev_warn(struct net_device *dev, const char *fmt, ...) {}
static inline void *usb_sndbulkpipe(void *dev, int endpoint) { return NULL; }
static inline void ems_usb_write_bulk_callback(struct urb *urb) {}