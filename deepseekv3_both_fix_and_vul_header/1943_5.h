#include <stdint.h>
#include <string.h>
#include <errno.h>

struct sk_buff {
    unsigned int len;
    unsigned char *data;
    unsigned char *head;
    unsigned char *mac_header;
    unsigned char *network_header;
    int csum_offset;
    unsigned int ip_summed;
    void *dst;
};

struct skb_shared_info {
    unsigned short gso_size;
    unsigned int gso_type;
    unsigned int gso_segs;
};

struct rt6_info {
};

struct frag_hdr {
    uint8_t nexthdr;
    uint8_t reserved;
    uint16_t frag_off;
    uint32_t identification;
};

#define NEXTHDR_FRAGMENT 44
#define SKB_GSO_UDP 4
#define SKB_GSO_DODGY 1
#define NETIF_F_GSO_ROBUST 0
#define CHECKSUM_NONE 0
#define GFP_ATOMIC 0
#define DIV_ROUND_UP(n, d) (((n) + (d) - 1) / (d))
#define ERR_PTR(err) ((void *)((long)(err)))
#define unlikely(x) (x)

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint32_t __wsum;
typedef uint16_t __sum16;

static inline struct skb_shared_info *skb_shinfo(struct sk_buff *skb) {
    return (struct skb_shared_info *)(skb->data + skb->len);
}

static inline int skb_gso_ok(struct sk_buff *skb, u32 features) {
    return 0;
}

static inline int skb_checksum_start_offset(struct sk_buff *skb) {
    return 0;
}

static inline __wsum skb_checksum(struct sk_buff *skb, int offset, int len, __wsum sum) {
    return 0;
}

static inline __wsum csum_fold(__wsum csum) {
    return 0;
}

static inline unsigned char *skb_mac_header(struct sk_buff *skb) {
    return skb->mac_header;
}

static inline unsigned char *skb_network_header(struct sk_buff *skb) {
    return skb->network_header;
}

static inline int pskb_expand_head(struct sk_buff *skb, int nhead, int ntail, int gfp_mask) {
    return 0;
}

static inline int ip6_find_1stfragopt(struct sk_buff *skb, u8 **prevhdr) {
    return 0;
}

static inline void *skb_dst(struct sk_buff *skb) {
    return skb->dst;
}

static inline void ipv6_select_ident(struct frag_hdr *fhdr, ...) {
    (void)fhdr;
}

static inline struct sk_buff *skb_segment(struct sk_buff *skb, u32 features) {
    return NULL;
}