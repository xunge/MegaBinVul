#include <stdint.h>
#include <stddef.h>

typedef uint8_t u8;

struct sk_buff {
    unsigned char *data;
    struct {
        unsigned char *raw;
    } nh;
    unsigned char *head;
    unsigned char *tail;
};

struct in6_addr {
    uint8_t s6_addr[16];
};

struct ipv6hdr {
    u8 nexthdr;
    struct in6_addr saddr;
    struct in6_addr daddr;
};

struct tcphdr {
    uint16_t source;
    uint16_t dest;
};

struct udphdr {
    uint16_t source;
    uint16_t dest;
};

struct net_info {
    union {
        struct {
            struct in6_addr saddr;
            struct in6_addr daddr;
        } v6info;
    };
    uint16_t sport;
    uint16_t dport;
};

struct avc_audit_data {
    union {
        struct net_info net;
    } u;
};

#define IPPROTO_TCP 6
#define IPPROTO_UDP 17
#define EINVAL 22

static inline void *skb_header_pointer(const struct sk_buff *skb, int offset, int len, void *buffer) {
    return NULL;
}

static inline int ipv6_skip_exthdr(const struct sk_buff *skb, int offset, const u8 *nexthdrp, ...) {
    int remaining = 0;
    if (skb) {
        remaining = skb->tail - skb->head - offset;
    }
    return 0;
}

static inline void ipv6_addr_copy(struct in6_addr *a1, const struct in6_addr *a2) {
    *a1 = *a2;
}