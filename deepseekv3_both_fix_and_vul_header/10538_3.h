#include <stdbool.h>
#include <stdint.h>
#include <errno.h>
#include <stddef.h>

typedef uint32_t netdev_features_t;
typedef uint8_t u8;

struct net_device {
    netdev_features_t hw_enc_features;
};

struct sk_buff {
    unsigned char *head;
    unsigned char *data;
    unsigned int len;
    unsigned char *mac_header;
    unsigned char *network_header;
    unsigned char *transport_header;
    struct sk_buff *next;
    bool encapsulation;
    struct net_device *dev;
    unsigned char cb[48];
};

struct ipv6hdr {
    u8 nexthdr;
    uint16_t payload_len;
};

struct frag_hdr {
    uint16_t frag_off;
};

struct net_offload {
    struct {
        struct sk_buff *(*gso_segment)(struct sk_buff *, netdev_features_t);
    } callbacks;
};

struct skb_shared_info {
    unsigned int gso_type;
    unsigned int gso_size;
};

#define SKB_GSO_CB(skb) ((struct skb_gso_cb *)(skb)->cb)
#define SKB_GSO_IPXIP4 (1 << 0)
#define SKB_GSO_IPXIP6 (1 << 1)
#define SKB_GSO_PARTIAL (1 << 2)

struct skb_gso_cb {
    int encap_level;
    unsigned int data_offset;
};

#define IPPROTO_UDP 17
#define IP6_MF 0x0001
#define EINVAL 22
#define EPROTONOSUPPORT 93

#define ERR_PTR(error) ((struct sk_buff *)(long)(error))
#define IS_ERR_OR_NULL(ptr) (!(ptr) || (long)(ptr) < 0)
#define unlikely(cond) (cond)
#define likely(cond) (cond)

static inline struct skb_shared_info *skb_shinfo(const struct sk_buff *skb) {
    return (struct skb_shared_info *)(skb->data + skb->len);
}

static inline unsigned char *skb_mac_header(const struct sk_buff *skb) {
    return skb->mac_header;
}

static inline unsigned char *skb_network_header(const struct sk_buff *skb) {
    return skb->network_header;
}

static inline void skb_reset_network_header(struct sk_buff *skb) {
    skb->network_header = skb->data;
}

static inline void skb_reset_transport_header(struct sk_buff *skb) {
    skb->transport_header = skb->data;
}

static inline void skb_reset_inner_headers(struct sk_buff *skb) {
    // Simplified implementation
}

static inline struct ipv6hdr *ipv6_hdr(const struct sk_buff *skb) {
    return (struct ipv6hdr *)skb_network_header(skb);
}

static inline void __skb_pull(struct sk_buff *skb, unsigned int len) {
    skb->data += len;
    skb->len -= len;
}

static inline bool pskb_may_pull(struct sk_buff *skb, unsigned int len) {
    return skb->len >= len;
}

static int ipv6_gso_pull_exthdrs(struct sk_buff *skb, int nexthdr) {
    return nexthdr;
}

extern struct net_offload *inet6_offloads[];
#define rcu_dereference(p) (p)

static uint16_t htons(uint16_t x) {
    return ((x & 0xff) << 8) | ((x & 0xff00) >> 8);
}

static uint16_t ntohs(uint16_t x) {
    return htons(x);
}

static unsigned int ip6_find_1stfragopt(struct sk_buff *skb, u8 **prevhdr) {
    return 0;
}