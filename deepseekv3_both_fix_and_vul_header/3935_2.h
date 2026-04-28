#include <stdint.h>
#include <stddef.h>
#include <string.h>

struct in6_addr {
    uint8_t s6_addr[16];
};

struct ipv6hdr {
    uint8_t priority:4;
    uint8_t version:4;
    uint8_t flow_lbl[3];
    uint16_t payload_len;
    uint8_t nexthdr;
    uint8_t hop_limit;
    struct in6_addr saddr;
    struct in6_addr daddr;
};

struct net_device {
    int ifindex;
    struct {
        unsigned long tx_errors;
    } stats;
    unsigned int mark;
};

struct net;
struct sock;

struct dst_entry {
    int error;
};

struct flowi6 {
    int flowi6_oif;
    struct in6_addr daddr;
    struct in6_addr saddr;
    unsigned int flowi6_flags;
    uint32_t flowlabel;
    unsigned int flowi6_mark;
    uint8_t flowi6_proto;
};

struct sk_buff {
    struct net_device *dev;
    unsigned int mark;
    struct sock *sk;
};

#define NET_XMIT_DROP 0
#define NET_XMIT_SUCCESS 1
#define FLOWI_FLAG_ANYSRC 0
#define IP6CB(skb) ((void*)0)

static inline uint32_t ip6_flowinfo(const struct ipv6hdr *hdr) { return 0; }
static inline struct net *dev_net(const struct net_device *dev) { return NULL; }
static inline void dst_release(struct dst_entry *dst) {}
static inline void skb_dst_set(struct sk_buff *skb, struct dst_entry *dst) {}
static inline int net_xmit_eval(int err) { return err; }
static inline void kfree_skb(struct sk_buff *skb) {}
static inline struct ipv6hdr *ipv6_hdr(const struct sk_buff *skb) { return NULL; }
static inline struct dst_entry *ip6_route_output(struct net *net, void *a, struct flowi6 *fl6) { return NULL; }
static inline int ip6_local_out(struct net *net, void *sk, struct sk_buff *skb) { return 0; }