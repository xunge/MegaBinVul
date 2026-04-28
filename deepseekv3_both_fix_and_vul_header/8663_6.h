#include <stdint.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip6.h>
#include <netinet/icmp6.h>
#include <sys/types.h>

typedef uint8_t u8;
typedef uint16_t __u16;
typedef uint32_t __u32;
typedef uint32_t u32;

struct net;
struct inet6_dev;
struct sock {
    unsigned int sk_mark;
};
struct ipv6_pinfo {
    int tclass;
    int dontfrag;
    int mcast_oif;
    int ucast_oif;
};
struct dst_entry {
    struct net_device *dev;
};
struct flowi6 {
    struct in6_addr daddr;
    struct in6_addr saddr;
    __u32 flowlabel;
    int flowi6_proto;
    int flowi6_oif;
    int fl6_icmp_type;
    int fl6_icmp_code;
    unsigned int flowi6_mark;
};
struct icmpv6_msg {
    struct sk_buff *skb;
    int offset;
    int type;
};
struct sockcm_cookie {
    int unused;
};
struct ipcm6_cookie {
    int tclass;
    int hlimit;
    int dontfrag;
    void *opt;
};
struct ipv6hdr {
    struct in6_addr daddr;
    struct in6_addr saddr;
};
struct icmp6hdr {
    u8 icmp6_type;
    u8 icmp6_code;
    __u16 icmp6_cksum;
    __u32 icmp6_pointer;
};
struct rt6_info;
struct net_device {
    int ifindex;
};

struct sk_buff {
    void *head;
    void *tail;
    void *data;
    unsigned int len;
    unsigned char pkt_type;
    unsigned char *network_header;
    unsigned char *transport_header;
    unsigned int mark;
    struct net_device *dev;
};

#define IPV6_ADDR_MULTICAST 0xFF000000
#define PACKET_HOST 0
#define ICMPV6_PKT_TOOBIG 2
#define ICMPV6_PARAMPROB 4
#define ICMPV6_UNK_OPTION 2
#define IPV6_ADDR_ANY 0
#define IPV6_MIN_MTU 1280
#define ICMP6_MIB_OUTERRORS 0

static inline u32 IP6_REPLY_MARK(struct net *net, u32 mark) { return mark; }
static inline struct net *dev_net(const struct net_device *dev) { return NULL; }
static inline struct ipv6hdr *ipv6_hdr(const struct sk_buff *skb) { return NULL; }
static inline unsigned char *skb_network_header(const struct sk_buff *skb) { return NULL; }
static inline unsigned char *skb_tail_pointer(const struct sk_buff *skb) { return NULL; }
static inline int ipv6_addr_type(const struct in6_addr *addr) { return 0; }
static inline int ipv6_chk_addr(struct net *net, const struct in6_addr *addr, 
                              const struct net_device *dev, int strict) { return 0; }
static inline int ipv6_chk_acast_addr_src(struct net *net, 
                                        const struct net_device *dev, 
                                        const struct in6_addr *addr) { return 0; }
static inline int opt_unrec(struct sk_buff *skb, __u32 info) { return 0; }
static inline int __ipv6_addr_needs_scope_id(int addr_type) { return 0; }
static inline int l3mdev_master_ifindex(const struct net_device *dev) { return 0; }
static inline struct dst_entry *skb_dst(const struct sk_buff *skb) { return NULL; }
static inline int is_ineligible(const struct sk_buff *skb) { return 0; }
static inline void mip6_addr_swap(struct sk_buff *skb) {}
static inline void security_skb_classify_flow(struct sk_buff *skb, void *flow) {}
static inline void *flowi6_to_flowi(struct flowi6 *fl6) { return NULL; }
static inline struct sock *icmpv6_xmit_lock(struct net *net) { return NULL; }
static inline struct ipv6_pinfo *inet6_sk(struct sock *sk) { return NULL; }
static inline int icmpv6_xrlim_allow(struct sock *sk, u8 type, struct flowi6 *fl6) { return 1; }
static inline int ipv6_addr_is_multicast(const struct in6_addr *addr) { return 0; }
static inline __u32 ip6_make_flowinfo(__u32 tclass, __u32 flowlabel) { return 0; }
static inline struct dst_entry *icmpv6_route_lookup(struct net *net, 
                                                  struct sk_buff *skb,
                                                  struct sock *sk,
                                                  struct flowi6 *fl6) { return NULL; }
static inline int IS_ERR(const void *ptr) { return 0; }
static inline int ip6_sk_dst_hoplimit(struct ipv6_pinfo *np, 
                                    struct flowi6 *fl6,
                                    struct dst_entry *dst) { return 64; }
static inline unsigned int skb_network_offset(const struct sk_buff *skb) { return 0; }
static inline void net_dbg_ratelimited(const char *fmt, ...) {}
static inline void rcu_read_lock(void) {}
static inline void rcu_read_unlock(void) {}
static inline struct inet6_dev *__in6_dev_get(const struct net_device *dev) { return NULL; }
static inline int ip6_append_data(struct sock *sk, 
                                int (*getfrag)(void *, char *, int, int, int, struct sk_buff *),
                                struct icmpv6_msg *msg,
                                int len, int hlen,
                                struct ipcm6_cookie *ipc6,
                                struct flowi6 *fl6,
                                struct rt6_info *rt,
                                unsigned int flags,
                                struct sockcm_cookie *sockc) { return 0; }
static inline void ICMP6_INC_STATS(struct net *net, 
                                 struct inet6_dev *idev, 
                                 int field) {}
static inline void ip6_flush_pending_frames(struct sock *sk) {}
static inline int icmpv6_push_pending_frames(struct sock *sk,
                                           struct flowi6 *fl6,
                                           struct icmp6hdr *hdr,
                                           int len) { return 0; }
static inline void dst_release(struct dst_entry *dst) {}
static inline void icmpv6_xmit_unlock(struct sock *sk) {}
static inline int icmpv6_getfrag(void *from, char *to, int offset, int len, int odd, struct sk_buff *skb) { return 0; }

#define min_t(type, x, y) ({ type __x = (x); type __y = (y); __x < __y ? __x : __y; })