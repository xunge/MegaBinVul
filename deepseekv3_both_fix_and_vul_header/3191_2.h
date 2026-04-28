#include <stdint.h>
#include <string.h>
#include <errno.h>

#define NETIF_F_GSO_ROBUST 0
#define SKB_GSO_UDP 0
#define SKB_GSO_DODGY 0
#define SKB_GSO_UDP_TUNNEL 0
#define SKB_GSO_GRE 0
#define SKB_GSO_IPIP 0
#define SKB_GSO_SIT 0
#define SKB_GSO_MPLS 0
#define CHECKSUM_NONE 0
#define NEXTHDR_FRAGMENT 0
#define EINVAL 22

typedef uint32_t netdev_features_t;
typedef uint32_t __wsum;
typedef uint16_t __sum16;
typedef uint8_t u8;
typedef int32_t __be32;
typedef uint16_t __be16;

struct sk_buff {
    unsigned int len;
    unsigned char *data;
    int ip_summed;
    int csum_offset;
    unsigned char *head;
    unsigned char *mac_header;
    unsigned char *network_header;
    int encapsulation;
    void *dst;
};

struct skb_shared_info {
    unsigned int gso_size;
    unsigned int gso_type;
    unsigned int gso_segs;
};

struct frag_hdr {
    u8 nexthdr;
    u8 reserved;
    __be16 frag_off;
    __be32 identification;
};

struct rt6_info {};
struct skb_gso_cb {
    unsigned int mac_offset;
};

static inline unsigned char *skb_network_header(const struct sk_buff *skb) {
    return skb->network_header;
}

static inline unsigned char *skb_mac_header(const struct sk_buff *skb) {
    return skb->mac_header;
}

static inline void *skb_dst(const struct sk_buff *skb) {
    return skb->dst;
}

#define SKB_GSO_CB(skb) ((struct skb_gso_cb *)(skb + 1))

#define ERR_PTR(err) ((void *)((long)(err)))
#define unlikely(cond) (cond)
#define DIV_ROUND_UP(n, d) (((n) + (d) - 1) / (d))

static inline struct skb_shared_info *skb_shinfo(struct sk_buff *skb) {
    return (struct skb_shared_info *)(skb + 1);
}

static inline int skb_gso_ok(struct sk_buff *skb, netdev_features_t features) {
    return 0;
}

static inline int skb_checksum_start_offset(struct sk_buff *skb) {
    return 0;
}

static inline __wsum skb_checksum(struct sk_buff *skb, int offset, int len, __wsum sum) {
    return 0;
}

static inline __sum16 csum_fold(__wsum csum) {
    return 0;
}

static inline int skb_tnl_header_len(struct sk_buff *skb) {
    return 0;
}

static inline int skb_headroom(struct sk_buff *skb) {
    return 0;
}

static inline int gso_pskb_expand_head(struct sk_buff *skb, int len) {
    return 0;
}

static inline unsigned int ip6_find_1stfragopt(struct sk_buff *skb, u8 **prevhdr) {
    return 0;
}

static inline void ipv6_select_ident(struct frag_hdr *fhdr, struct rt6_info *rt) {
}

static inline struct sk_buff *skb_udp_tunnel_segment(struct sk_buff *skb, netdev_features_t features) {
    return NULL;
}

static inline struct sk_buff *skb_segment(struct sk_buff *skb, netdev_features_t features) {
    return NULL;
}