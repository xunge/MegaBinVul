#include <stdint.h>
#include <string.h>
#include <errno.h>

typedef uint8_t u8;
typedef uint32_t u32;
typedef int32_t __wsum;
typedef int16_t __sum16;
typedef uint16_t __be16;
typedef uint32_t __be32;

#define DIV_ROUND_UP(n, d) (((n) + (d) - 1) / (d))
#define unlikely(x) (x)
#define GFP_ATOMIC 0
#define CHECKSUM_NONE 0
#define NETIF_F_GSO_ROBUST (1 << 24)
#define SKB_GSO_UDP (1 << 0)
#define SKB_GSO_DODGY (1 << 1)
#define NEXTHDR_FRAGMENT 44
#define EINVAL 22

struct sk_buff {
    unsigned int len;
    unsigned char *data;
    unsigned char *head;
    unsigned char *mac_header;
    unsigned char *network_header;
    unsigned int csum_start;
    unsigned int csum_offset;
    unsigned char ip_summed;
    unsigned int headroom;
    void *shinfo;
};

struct skb_shared_info {
    unsigned short gso_size;
    unsigned short gso_segs;
    unsigned int gso_type;
};

struct frag_hdr {
    u8 nexthdr;
    u8 reserved;
    __be16 frag_off;
    __be32 identification;
};

static inline struct skb_shared_info *skb_shinfo(struct sk_buff *skb) {
    return (struct skb_shared_info *)skb->shinfo;
}

static inline unsigned int skb_headroom(const struct sk_buff *skb) {
    return skb->headroom;
}

static inline unsigned char *skb_network_header(const struct sk_buff *skb) {
    return skb->network_header;
}

static inline unsigned char *skb_mac_header(const struct sk_buff *skb) {
    return skb->mac_header;
}

static inline int skb_gso_ok(struct sk_buff *skb, u32 features) {
    return 0;
}

static inline __wsum skb_checksum(struct sk_buff *skb, int offset, int len, __wsum sum) {
    return 0;
}

static inline __wsum csum_fold(__wsum csum) {
    return 0;
}

static inline int pskb_expand_head(struct sk_buff *skb, int newheadroom, int newtailroom, int gfp_mask) {
    return 0;
}

static inline unsigned int ip6_find_1stfragopt(struct sk_buff *skb, u8 **nexthdr) {
    return 0;
}

static inline void ipv6_select_ident(struct frag_hdr *fhdr) {
}

static inline struct sk_buff *skb_segment(struct sk_buff *skb, u32 features) {
    return NULL;
}

static inline void *ERR_PTR(long error) {
    return (void *)error;
}