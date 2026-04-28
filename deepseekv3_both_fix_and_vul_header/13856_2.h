#include <stdint.h>

typedef uint8_t u8;
typedef uint16_t u16;

#define NEXTHDR_HOP 0
#define NEXTHDR_ROUTING 43
#define NEXTHDR_DEST 60
#define IPV6_TLV_HAO 201
#define IPV6_MAXPLEN 65535
#define EINVAL 22
#define IS_ENABLED(x) 0

struct ipv6hdr {
    u8 nexthdr;
};

struct ipv6_opt_hdr {
    u8 nexthdr;
    u8 hdrlen;
};

struct sk_buff {
    u8* head;
    u8* data;
    u8* tail;
    u8* end;
};

static inline u8* skb_tail_pointer(const struct sk_buff *skb) {
    return skb->tail;
}

static inline u8* skb_network_header(const struct sk_buff *skb) {
    return skb->data;
}

static inline struct ipv6hdr* ipv6_hdr(const struct sk_buff *skb) {
    return (struct ipv6hdr*)skb_network_header(skb);
}

static inline unsigned int ipv6_optlen(const struct ipv6_opt_hdr *hdr) {
    return (hdr->hdrlen + 1) << 3;
}