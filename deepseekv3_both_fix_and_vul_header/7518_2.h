#include <stdint.h>
#include <string.h>

typedef unsigned int netdev_tx_t;
#define NETDEV_TX_OK 0
#define NETDEV_TX_BUSY 1

struct sk_buff {
    void *data;
};

struct net_device_stats {
    unsigned long tx_dropped;
};

struct net_device {
    struct net_device_stats stats;
};

struct can_frame {
    uint32_t can_id;
    uint8_t len;
    uint8_t data[8];
};

struct mcba_priv {
    struct net_device *netdev;
};

struct mcba_usb_ctx {
    int ndx;
};

struct mcba_usb_msg {
    uint8_t cmd_id;
};

struct mcba_usb_msg_can {
    uint8_t cmd_id;
    uint16_t sid;
    uint16_t eid;
    uint8_t dlc;
    uint8_t data[8];
};

#define CAN_EFF_FLAG 0x80000000
#define CAN_RTR_FLAG 0x40000000
#define CAN_SFF_MASK 0x000007FF
#define MBCA_CMD_TRANSMIT_MESSAGE_EV 0
#define MCBA_SIDL_EXID_MASK 0
#define MCBA_DLC_RTR_MASK 0x80

typedef uint16_t u16;

static inline void put_unaligned_be16(uint16_t val, void *p)
{
    uint8_t *ptr = p;
    ptr[0] = val >> 8;
    ptr[1] = val;
}

static inline struct mcba_priv *netdev_priv(struct net_device *dev)
{
    return (struct mcba_priv *)dev;
}

static inline int can_dropped_invalid_skb(struct net_device *dev, struct sk_buff *skb)
{
    return 0;
}

static inline struct mcba_usb_ctx *mcba_usb_get_free_ctx(struct mcba_priv *priv, struct can_frame *cf)
{
    return NULL;
}

static inline void mcba_usb_free_ctx(struct mcba_usb_ctx *ctx)
{
}

static inline void can_put_echo_skb(struct sk_buff *skb, struct net_device *dev, int ndx, int dummy)
{
}

static inline void can_free_echo_skb(struct net_device *dev, int ndx, void *dummy)
{
}

static inline void dev_kfree_skb(struct sk_buff *skb)
{
}

static inline int mcba_usb_xmit(struct mcba_priv *priv, struct mcba_usb_msg *msg, struct mcba_usb_ctx *ctx)
{
    return 0;
}