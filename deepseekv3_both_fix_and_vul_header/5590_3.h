#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <netinet/in.h>

typedef uint32_t u32;

struct sk_buff {
    unsigned char pkt_type;
    void *data;
    void *dst;
    struct net_device *dev;
    unsigned int priority;
    unsigned char cb[48];
};

struct iphdr {
    uint8_t ttl;
    uint8_t tos;
};

struct ip_options {
    unsigned char router_alert;
    unsigned char is_strictroute;
    unsigned char srr;
};

struct net_device {
    char name[16];
};

struct dst_entry {
    struct net_device *dev;
    unsigned int header_len;
    unsigned int mtu;
};

struct rtable {
    struct dst_entry dst;
    unsigned int rt_flags;
    bool rt_uses_gateway;
};

struct IPCB {
    struct ip_options opt;
    unsigned int flags;
};

#define NET_RX_SUCCESS 0
#define NET_RX_DROP 1
#define PACKET_HOST 0
#define IPSKB_FORWARDED (1 << 1)
#define IPSKB_DOREDIRECT (1 << 2)
#define RTCF_DOREDIRECT (1 << 3)
#define NFPROTO_IPV4 2
#define NF_INET_FORWARD 1
#define ICMP_DEST_UNREACH 3
#define ICMP_FRAG_NEEDED 4
#define ICMP_SR_FAILED 5
#define ICMP_TIME_EXCEEDED 11
#define ICMP_EXC_TTL 0
#define XFRM_POLICY_FWD 0
#define IPSTATS_MIB_FRAGFAILS 0
#define IPSTATS_MIB_INHDRERRORS 0
#define LL_RESERVED_SPACE(dev) (0)

#define IPCB(skb) ((struct IPCB *)((skb)->cb))
#define skb_rtable(skb) ((struct rtable *)(skb)->dst)
#define skb_dst(skb) ((skb)->dst)
#define ip_hdr(skb) ((struct iphdr *)((skb)->data))
#define dev_net(dev) ((struct net *)0)

static inline void IP_INC_STATS(void *net, int field) {}
static inline void IP_INC_STATS_BH(void *net, int field) {}
static inline void icmp_send(struct sk_buff *skb, int type, int code, uint32_t info) {}
static inline void kfree_skb(struct sk_buff *skb) {}
static inline bool skb_warn_if_lro(const struct sk_buff *skb) { return false; }
static inline bool xfrm4_policy_check(void *a, int b, struct sk_buff *skb) { return true; }
static inline bool xfrm4_route_forward(struct sk_buff *skb) { return true; }
static inline bool ip_may_fragment(const struct sk_buff *skb) { return true; }
static inline bool ip_exceeds_mtu(const struct sk_buff *skb, unsigned int mtu) { return false; }
static inline void ip_decrease_ttl(struct iphdr *iph) {}
static inline bool ip_call_ra_chain(struct sk_buff *skb) { return false; }
static inline void ip_rt_send_redirect(struct sk_buff *skb) {}
static inline bool skb_cow(struct sk_buff *skb, unsigned int headroom) { return false; }
static inline void skb_forward_csum(struct sk_buff *skb) {}
static inline unsigned int rt_tos2priority(unsigned char tos) { return 0; }
static inline bool skb_sec_path(const struct sk_buff *skb) { return false; }
static inline unsigned int ip_dst_mtu_maybe_forward(const struct dst_entry *dst, bool forwarding) { return dst->mtu; }
static inline int NF_HOOK(unsigned int pf, unsigned int hook, struct sk_buff *skb, struct net_device *in, struct net_device *out, int (*okfn)(struct sk_buff *)) { return okfn(skb); }
static inline int ip_forward_finish(struct sk_buff *skb) { return NET_RX_SUCCESS; }