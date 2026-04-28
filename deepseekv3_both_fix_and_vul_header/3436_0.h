#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

#define EINVAL 22
#define ENODEV 19
#define ENOBUFS 105
#define ENOMEM 12
#define EHOSTUNREACH 113
#define EACCES 13
#define EAGAIN 11
#define ENETUNREACH 101

#define IP6_RT_PRIO_USER 0
#define DST_NOCOUNT 0
#define DST_HOST 1
#define RTAX_MAX 12
#define RTPROT_UNSPEC 0
#define RTPROT_BOOT 3
#define RTF_EXPIRES 0x0100
#define RTF_LOCAL 0x80000000
#define RTF_REJECT 0x0200
#define RTF_NONEXTHOP 0x00200000
#define RTF_GATEWAY 0x0002
#define RTF_ADDRCONF 0x100000
#define RTN_BLACKHOLE 6
#define RTN_PROHIBIT 8
#define RTN_THROW 9
#define NLM_F_CREATE 0x400
#define IPV6_ADDR_MULTICAST 0xFF000000
#define IPV6_ADDR_LOOPBACK 0x0010
#define IPV6_ADDR_LINKLOCAL 0x0020
#define IPV6_ADDR_UNICAST 0x0000
#define IFF_LOOPBACK 0x8
#define GFP_KERNEL 0

typedef uint32_t u32;

struct in6_addr {
    uint8_t s6_addr[16];
};

struct net_device {
    int ifindex;
    unsigned int flags;
    struct net_device *loopback_dev;
};

struct net {
    struct net_device *loopback_dev;
};

struct nlmsghdr {
    int nlmsg_flags;
};

struct dst_entry {
    struct net_device *dev;
    unsigned long flags;
    int error;
    void (*input)(void *);
    void (*output)(void *);
};

struct rt6_info {
    struct dst_entry dst;
    struct {
        struct in6_addr addr;
        int plen;
    } rt6i_dst, rt6i_src, rt6i_prefsrc;
    struct in6_addr rt6i_gateway;
    int rt6i_flags;
    int rt6i_protocol;
    int rt6i_metric;
    void *rt6i_table;
    struct net_device *dst_dev;
    void *rt6i_idev;
};

struct fib6_config {
    int fc_dst_len;
    int fc_src_len;
    int fc_ifindex;
    int fc_metric;
    int fc_table;
    int fc_flags;
    int fc_protocol;
    int fc_type;
    int fc_expires;
    struct in6_addr fc_dst;
    struct in6_addr fc_src;
    struct in6_addr fc_gateway;
    struct in6_addr fc_prefsrc;
    void *fc_mx;
    int fc_mx_len;
    struct {
        struct net *nl_net;
        struct nlmsghdr *nlh;
    } fc_nlinfo;
};

struct fib6_table {};
struct inet6_dev {};
struct nlattr {};

#define nla_for_each_attr(pos, head, len, rem) \
    for (pos = head, rem = len; rem > 0; pos = (void *)pos + nla_total_size(0), rem -= nla_total_size(0))

static inline size_t nla_total_size(int payload) { return 0; }

static inline void *kzalloc(size_t size, int flags) { return NULL; }
static inline void dev_hold(struct net_device *dev) {}
static inline void dev_put(struct net_device *dev) {}
static inline void in6_dev_put(void *idev) {}
static inline void in6_dev_hold(void *idev) {}
static inline struct net_device *dev_get_by_index(struct net *net, int ifindex) { return NULL; }
static inline void *in6_dev_get(struct net_device *dev) { return NULL; }
static inline void *fib6_get_table(struct net *net, int id) { return NULL; }
static inline void *fib6_new_table(struct net *net, int id) { return NULL; }
static inline struct rt6_info *ip6_dst_alloc(struct net *net, void *arg, int flags, void *table) { return NULL; }
static inline void rt6_set_expires(struct rt6_info *rt, unsigned long expires) {}
static inline void rt6_clean_expires(struct rt6_info *rt) {}
static inline void ipv6_addr_prefix(struct in6_addr *pfx, const struct in6_addr *addr, int plen) {}
static inline int ipv6_addr_type(const struct in6_addr *addr) { return 0; }
static inline int ipv6_chk_addr(struct net *net, const struct in6_addr *addr, const struct net_device *dev, int strict) { return 0; }
static inline int ipv6_addr_any(const struct in6_addr *addr) { return 0; }
static inline void dst_init_metrics(struct dst_entry *dst, const u32 *metrics, bool override) {}
static inline void dst_metric_set(struct dst_entry *dst, int metric, u32 val) {}
static inline struct rt6_info *rt6_lookup(struct net *net, const struct in6_addr *daddr, const struct in6_addr *saddr, int oif, int strict) { return NULL; }
static inline void ip6_rt_put(struct rt6_info *rt) {}
static inline int __ip6_ins_rt(struct rt6_info *rt, void *arg) { return 0; }
static inline void dst_free(struct dst_entry *dst) {}
static inline struct net *dev_net(const struct net_device *dev) { return NULL; }
static inline void ip6_mc_input(void *skb) {}
static inline void ip6_input(void *skb) {}
static inline void ip6_forward(void *skb) {}
static inline void ip6_output(void *skb) {}
static inline void dst_discard(void *skb) {}
static inline void ip6_pkt_prohibit_out(void *skb) {}
static inline void ip6_pkt_prohibit(void *skb) {}
static inline void ip6_pkt_discard_out(void *skb) {}
static inline void ip6_pkt_discard(void *skb) {}
static inline int nla_type(const struct nlattr *nla) { return 0; }
static inline u32 nla_get_u32(const struct nlattr *nla) { return 0; }
static inline void pr_warn(const char *fmt, ...) {}
static inline unsigned long clock_t_to_jiffies(unsigned long clk) { return 0; }
extern unsigned long jiffies;