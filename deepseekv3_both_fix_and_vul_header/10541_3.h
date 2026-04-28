#include <stdint.h>

#define NEXTHDR_HOP 0
#define NEXTHDR_ROUTING 43
#define NEXTHDR_DEST 60
#define IPV6_TLV_HAO 201
#define EINVAL 22

typedef uint8_t u8;
typedef uint16_t u16;

struct ipv6hdr {
    u8 nexthdr;
};

struct ipv6_opt_hdr {
    u8 nexthdr;
    u8 hdrlen;
};

struct sk_buff {
    unsigned char* head;
    unsigned char* data;
    unsigned char* tail;
    unsigned char* end;
};

static inline unsigned char* skb_tail_pointer(const struct sk_buff *skb) {
    return skb->tail;
}

static inline unsigned char* skb_network_header(const struct sk_buff *skb) {
    return skb->head;
}

static inline struct ipv6hdr* ipv6_hdr(const struct sk_buff *skb) {
    return (struct ipv6hdr*)skb->data;
}

static inline int ipv6_optlen(struct ipv6_opt_hdr *hdr) {
    return (hdr->hdrlen + 1) << 3;
}

static inline int ipv6_find_tlv(struct sk_buff *skb, int offset, int type) {
    return -1;
}

#define IS_ENABLED(x) 0