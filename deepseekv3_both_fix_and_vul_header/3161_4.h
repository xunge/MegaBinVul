#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef uint16_t u16;
typedef uint8_t u8;
typedef uint16_t __be16;
typedef uint32_t __be32;
typedef uint8_t __u8;

#define __force
#define ETH_P_IP 0x0800
#define ETH_P_IPV6 0x86DD
#define ETH_P_8021Q 0x8100
#define ETH_P_8021AD 0x88A8
#define ETH_P_PPP_SES 0x8864
#define ETH_P_TEB 0x6558
#define PPP_IP 0x0021
#define PPP_IPV6 0x0057
#define PPPOE_SES_HLEN 8
#define IP_MF 0x2000
#define IP_OFFSET 0x1FFF
#define GRE_VERSION 0x8000
#define GRE_ROUTING 0x4000
#define GRE_CSUM 0x8000
#define GRE_KEY 0x2000
#define GRE_SEQ 0x1000

struct flow_keys {
    __be32 src;
    __be32 dst;
    union {
        __be32 ports;
        __be16 port16[2];
    };
    u16 thoff;
    u8 ip_proto;
};

struct sk_buff {
    __be16 protocol;
    int network_offset;
};

struct vlan_hdr {
    __be16 h_vlan_TCI;
    __be16 h_vlan_encapsulated_proto;
};

struct iphdr {
    u8 ihl:4;
    u8 version:4;
    u8 tos;
    u16 tot_len;
    u16 id;
    u16 frag_off;
    u8 ttl;
    u8 protocol;
    u16 check;
    __be32 saddr;
    __be32 daddr;
};

struct ipv6hdr {
    __be32 version:4;
    __be32 priority:4;
    __be32 flow_lbl[3];
    __be16 payload_len;
    u8 nexthdr;
    u8 hop_limit;
    struct in6_addr saddr;
    struct in6_addr daddr;
};

struct ethhdr {
    unsigned char h_dest[6];
    unsigned char h_source[6];
    __be16 h_proto;
};

struct pppoe_hdr {
    __be16 ver;
    __be16 type;
    __be16 code;
    __be16 sid;
    __be16 length;
};

static inline int skb_network_offset(const struct sk_buff *skb) {
    return skb->network_offset;
}

static inline bool ip_is_fragment(const struct iphdr *iph) {
    return (iph->frag_off & htons(IP_MF | IP_OFFSET)) != 0;
}

static inline void iph_to_flow_copy_addrs(struct flow_keys *flow, const struct iphdr *iph) {
    flow->src = iph->saddr;
    flow->dst = iph->daddr;
}

static inline int proto_ports_offset(int proto) {
    switch (proto) {
    case IPPROTO_TCP:
    case IPPROTO_UDP:
    case IPPROTO_SCTP:
    case IPPROTO_DCCP:
        return 0;
    default:
        return -1;
    }
}

static inline void *skb_header_pointer(const struct sk_buff *skb, int offset, int len, void *buffer) {
    return buffer;
}

static inline __be32 ipv6_addr_hash(const struct in6_addr *a) {
    return 0;
}

#define __constant_htons(x) ((__be16)__builtin_bswap16((x)))