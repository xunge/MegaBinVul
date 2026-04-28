#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define VLAN_ETH_HLEN 18
#define ETH_P_IP 0x0800
#define ETH_P_IPV6 0x86DD
#define DST_OBSOLETE_NONE 0
#define DST_NOCOUNT 0

typedef uint16_t u16;

struct net;
struct net_device {
    int mtu;
};
struct sk_buff {
    unsigned int network_offset;
    struct net_device *dev;
    void *sk;
    unsigned long _skb_refdst;
};
struct dst_entry {
    struct net_device *dev;
};
struct dst_ops {
    int dummy;
};
struct rtable {
    struct dst_entry dst;
};
struct rt6_info {
    struct dst_entry dst;
};
struct ipv6_stub {
    int (*ipv6_fragment)(struct net *, void *, struct sk_buff *, int (*)(struct sk_buff *));
} *ipv6_stub;

struct dst_ops sch_frag_dst_ops;

static inline uint16_t htons(uint16_t x) { return x; }
static inline uint16_t ntohs(uint16_t x) { return x; }
static inline unsigned int skb_network_offset(const struct sk_buff *skb) { return 0; }
static inline int skb_protocol(const struct sk_buff *skb, bool b) { return 0; }
static inline void dst_init(struct dst_entry *dst, struct dst_ops *ops, void *null, int i, int obsolete, int nocount) {}
static inline void skb_dst_set_noref(struct sk_buff *skb, struct dst_entry *dst) {}
static inline void refdst_drop(unsigned long orig_dst) {}
static inline const char *netdev_name(const struct net_device *dev) { return ""; }
static inline void net_warn_ratelimited(const char *fmt, ...) {}
static inline void kfree_skb(struct sk_buff *skb) {}

#define IPCB(skb) ((struct { int frag_max_size; } *)0)
#define IP6CB(skb) ((struct { int frag_max_size; } *)0)

static int sch_frag_xmit(struct sk_buff *skb) { return 0; }
static void sch_frag_prepare_frag(struct sk_buff *skb, int (*xmit)(struct sk_buff *)) {}
static int ip_do_fragment(struct net *net, void *sk, struct sk_buff *skb, int (*xmit)(struct sk_buff *)) { return 0; }