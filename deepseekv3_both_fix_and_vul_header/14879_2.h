#include <stdint.h>
#include <arpa/inet.h>
#include <stdlib.h>

typedef uint32_t u32;
typedef uint32_t __be32;

#define IPV6_MAXPLEN 65535
#define ICMPV6_HDR_FIELD 0

struct sk_buff {
    void *dst;
    unsigned char *head;
    unsigned char *data;
    unsigned int len;
};

struct ipv6hdr {
    uint8_t payload_len[2];
};

static inline const unsigned char *skb_network_header(const struct sk_buff *skb) {
    return skb->head;
}

static inline struct ipv6hdr *ipv6_hdr(const struct sk_buff *skb) {
    return (struct ipv6hdr *)skb->data;
}

static inline void kfree_skb(struct sk_buff *skb) {
    free(skb);
}

static inline int pskb_trim_rcsum(struct sk_buff *skb, unsigned int len) {
    return 0;
}

static inline void icmpv6_param_prob(struct sk_buff *skb, uint8_t code, int ptr) {
}

#define LIMIT_NETDEBUG(fmt, ...)
#define KERN_DEBUG ""
#define IP6_INC_STATS_BH(dev, field)
#define IPSTATS_MIB_INHDRERRORS 0
#define IPSTATS_MIB_INTRUNCATEDPKTS 0