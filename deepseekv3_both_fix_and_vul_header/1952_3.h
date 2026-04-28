#include <stdint.h>

typedef uint64_t __u64;
typedef uint32_t __u32;
typedef uint32_t __be32;
typedef uint16_t __be16;

struct sk_buff;

struct in6_addr {
    __be32 s6_addr32[4];
};

struct ipv6hdr {
    struct in6_addr daddr;
    struct in6_addr saddr;
};

struct dccp_hdr {
    __be16 dccph_sport;
    __be16 dccph_dport;
};

static inline struct ipv6hdr *ipv6_hdr(const struct sk_buff *skb) {
    return (struct ipv6hdr *)0;
}

static inline struct dccp_hdr *dccp_hdr(const struct sk_buff *skb) {
    return (struct dccp_hdr *)0;
}

__u64 secure_dccpv6_sequence_number(__be32 daddr[4], __be32 saddr[4], __be16 dport, __be16 sport);