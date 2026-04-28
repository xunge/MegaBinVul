#include <stdint.h>
#include <netinet/in.h>
#include <stddef.h>

typedef uint32_t u32;
typedef uint32_t __be32;

struct dst_entry {
    void *dev;
};

struct sk_buff {
    unsigned char *head;
    unsigned char *data;
    unsigned char *tail;
    unsigned char *end;
    unsigned int len;
    unsigned int truesize;
    struct dst_entry *dst;
};

struct ipv6hdr {
    uint8_t payload_len[2];
};

struct net {
    // minimal definition
};

#define IPV6_MAXPLEN 65535
#define KERN_DEBUG ""
#define LIMIT_NETDEBUG(fmt, ...)
#define IP6_INC_STATS_BH(net, idev, field)
#define ICMPV6_HDR_FIELD 0
#define IPSTATS_MIB_INHDRERRORS 0
#define IPSTATS_MIB_INTRUNCATEDPKTS 0

static inline const unsigned char *skb_network_header(const struct sk_buff *skb) {
    return skb->head;
}

static inline struct net *dev_net(const void *dev) {
    return NULL;
}

static inline struct dst_entry *skb_dst(const struct sk_buff *skb) {
    return skb->dst;
}

static inline void *ipv6_skb_idev(const struct sk_buff *skb) {
    return NULL;
}

static inline struct ipv6hdr *ipv6_hdr(const struct sk_buff *skb) {
    return (struct ipv6hdr *)skb->data;
}

static inline int pskb_trim_rcsum(struct sk_buff *skb, unsigned int len) {
    return 0;
}

static inline void kfree_skb(struct sk_buff *skb) {
}

static inline void icmpv6_param_prob(struct sk_buff *skb, int code, int pos) {
}