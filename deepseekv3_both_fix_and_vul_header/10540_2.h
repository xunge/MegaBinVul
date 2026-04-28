#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

typedef uint8_t u8;
typedef uint32_t netdev_features_t;
typedef uint32_t __wsum;

#define DIV_ROUND_UP(n, d) (((n) + (d) - 1) / (d))
#define unlikely(x) (x)
#define NETIF_F_GSO_ROBUST (1 << 24)
#define NETIF_F_HW_CSUM (1 << 25)
#define CHECKSUM_NONE 0
#define NEXTHDR_FRAGMENT 44
#define CSUM_MANGLED_0 0xffff
#define SKB_GSO_UDP_TUNNEL (1 << 0)
#define SKB_GSO_UDP_TUNNEL_CSUM (1 << 1)
#define ERR_PTR(err) ((void *)((long)(err)))

struct sk_buff {
    unsigned int len;
    unsigned char *head;
    unsigned char *mac_header;
    unsigned char *network_header;
    unsigned int encapsulation;
    unsigned int encap_hdr_csum;
    unsigned int ip_summed;
    void *dev;
    struct skb_shared_info *shinfo;
};

struct skb_shared_info {
    unsigned int gso_size;
    unsigned int gso_segs;
    unsigned int gso_type;
    uint32_t ip6_frag_id;
};

struct ipv6hdr {
    uint8_t saddr[16];
    uint8_t daddr[16];
};

struct udphdr {
    uint16_t check;
};

struct frag_hdr {
    uint8_t nexthdr;
    uint8_t reserved;
    uint16_t frag_off;
    uint32_t identification;
};

struct skb_gso_cb {
    unsigned int mac_offset;
};

static inline struct skb_shared_info *skb_shinfo(const struct sk_buff *skb) {
    return skb->shinfo;
}

static inline int skb_gso_ok(const struct sk_buff *skb, netdev_features_t features) {
    return 1;
}

static inline int skb_tnl_header_len(const struct sk_buff *skb) {
    return 0;
}

static inline int gso_pskb_expand_head(struct sk_buff *skb, int len) {
    return 0;
}

static inline unsigned int ip6_find_1stfragopt(struct sk_buff *skb, u8 **prevhdr) {
    return 0;
}

static inline struct udphdr *udp_hdr(const struct sk_buff *skb) {
    return (struct udphdr *)(skb->network_header + 40);
}

static inline struct ipv6hdr *ipv6_hdr(const struct sk_buff *skb) {
    return (struct ipv6hdr *)skb->network_header;
}

static inline __wsum skb_checksum(struct sk_buff *skb, int offset, int len, int sum) {
    return 0;
}

static inline uint16_t udp_v6_check(int len, const uint8_t *saddr, const uint8_t *daddr, __wsum csum) {
    return 0;
}

static inline void *dev_net(const void *dev) {
    return (void *)dev;
}

static inline void ipv6_proxy_select_ident(void *net, struct sk_buff *skb) {
}

static inline struct sk_buff *skb_udp_tunnel_segment(struct sk_buff *skb, netdev_features_t features, bool flag) {
    return NULL;
}

static inline struct sk_buff *skb_segment(struct sk_buff *skb, netdev_features_t features) {
    return NULL;
}

static inline int pskb_may_pull(struct sk_buff *skb, unsigned int len) {
    return 1;
}

static inline unsigned char *skb_network_header(const struct sk_buff *skb) {
    return skb->network_header;
}

static inline unsigned char *skb_mac_header(const struct sk_buff *skb) {
    return skb->mac_header;
}

static inline struct skb_gso_cb *SKB_GSO_CB(const struct sk_buff *skb) {
    return (struct skb_gso_cb *)skb;
}