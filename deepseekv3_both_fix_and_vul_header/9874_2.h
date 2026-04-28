#include <stdint.h>
#include <stddef.h>
#include <netinet/in.h>
#include <arpa/inet.h>

struct net_bridge {
    struct net_bridge_mdb_htable *mdb;
    int multicast_disabled;
};

struct net_bridge_mdb_entry;
struct net_bridge_mdb_htable;

struct sk_buff {
    uint16_t protocol;
    void *cb;
};

struct iphdr {
    uint32_t daddr;
};

struct ipv6hdr {
    struct in6_addr daddr;
};

struct br_input_skb_cb {
    int igmp;
};

struct br_ip {
    uint16_t proto;
    union {
        uint32_t ip4;
        struct in6_addr ip6;
    } u;
};

#define ETH_P_IP 0x0800
#define ETH_P_IPV6 0x86DD
#define CONFIG_IPV6 1

#define htons(x) ((uint16_t)(((x) << 8) | ((x) >> 8)))
#define BR_INPUT_SKB_CB(skb) ((struct br_input_skb_cb *)(skb)->cb)

static inline struct iphdr *ip_hdr(const struct sk_buff *skb) {
    return (struct iphdr *)skb;
}

static inline struct ipv6hdr *ipv6_hdr(const struct sk_buff *skb) {
    return (struct ipv6hdr *)skb;
}

static inline void ipv6_addr_copy(struct in6_addr *a1, const struct in6_addr *a2) {
    *a1 = *a2;
}

struct net_bridge_mdb_entry *br_mdb_ip_get(struct net_bridge_mdb_htable *mdb, struct br_ip *ip);