#include <stdint.h>

struct xenvif {
    void *dev;
};

struct xen_netif_extra_info {
    union {
        struct {
            uint16_t size;
            uint8_t type;
        } gso;
    } u;
};

struct sk_buff {
    void *data;
};

struct skb_shared_info {
    uint16_t gso_size;
    uint16_t gso_type;
    uint16_t gso_segs;
};

#define XEN_NETIF_GSO_TYPE_TCPV4 1
#define SKB_GSO_TCPV4 1
#define SKB_GSO_DODGY 2
#define EINVAL 22

static inline struct skb_shared_info *skb_shinfo(struct sk_buff *skb) {
    return (struct skb_shared_info *)(skb->data + 0);
}

#define netdev_dbg(dev, fmt, ...)