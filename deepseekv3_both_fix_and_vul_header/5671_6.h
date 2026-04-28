#include <stdint.h>
#include <string.h>

typedef uint8_t __u8;
typedef uint8_t u8;
typedef uint32_t u32;
typedef uint32_t __be32;

struct sk_buff {
    void *transport_header;
    void *tail;
    void *data;
    struct net_device *dev;
    uint8_t ndisc_nodetype;
};

struct net_device {
    char name[16];
    unsigned int mtu;
};

struct in6_addr {
    uint8_t s6_addr[16];
};

struct ipv6hdr {
    struct in6_addr saddr;
};

struct icmp6hdr {
    uint8_t icmp6_type;
    uint8_t icmp6_code;
    uint16_t icmp6_cksum;
    uint8_t icmp6_addrconf_managed;
    uint8_t icmp6_addrconf_other;
    uint16_t icmp6_rt_lifetime;
    uint32_t reachable_time;
    uint32_t retrans_timer;
    uint8_t icmp6_router_pref;
    uint8_t icmp6_hop_limit;
};

struct ra_msg {
    struct icmp6hdr icmph;
    uint32_t retrans_timer;
    uint32_t reachable_time;
};

struct neighbour {
    unsigned int flags;
};

struct inet6_dev {
    unsigned int if_flags;
    struct {
        int accept_ra_defrtr;
        int accept_ra_from_local;
        int accept_ra_rtr_pref;
        int accept_ra_pinfo;
        int accept_ra_mtu;
        int accept_ra_rt_info_max_plen;
        int hop_limit;
        int mtu6;
    } cnf;
    struct net_device *dev;
    struct neigh_parms *nd_parms;
    unsigned long tstamp;
};

struct dst_entry {
    void *__data[0];
};

struct rt6_info {
    unsigned long rt6i_flags;
    struct dst_entry dst;
};

struct ndisc_options {
    void *nd_opts_src_lladdr;
    void *nd_opts_ri;
    void *nd_opts_ri_end;
    void *nd_opts_pi;
    void *nd_opts_pi_end;
    void *nd_opts_mtu;
    void *nd_useropts;
    void *nd_useropts_end;
    void *nd_opts_tgt_lladdr;
    void *nd_opts_rh;
};

struct nd_tbl {
    void *tbl;
};

struct route_info {
    uint8_t prefix_len;
};

struct nd_opt_hdr {
    uint8_t nd_opt_type;
    uint8_t nd_opt_len;
};

struct neigh_parms {
    unsigned long reachable_time;
    unsigned long base_reachable_time;
    unsigned long retrans_time;
    unsigned long gc_staletime;
};

enum {
    NDISC_NODETYPE_HOST = 0,
    NDISC_NODETYPE_NODEFAULT = 1
};

enum {
    ICMPV6_ROUTER_PREF_INVALID = 0,
    ICMPV6_ROUTER_PREF_MEDIUM = 1
};

extern struct nd_tbl nd_tbl;
extern unsigned long jiffies;

#define ND_PRINTK(level, type, fmt, ...)
#define IPV6_ADDR_LINKLOCAL 0x0020U
#define CONFIG_IPV6_NDISC_NODETYPE
#define CONFIG_IPV6_ROUTER_PREF
#define CONFIG_IPV6_ROUTE_INFO
#define RTF_PREF_MASK 0x00030000
#define RTF_PREF(x) ((x) << 16)
#define RTAX_HOPLIMIT 2
#define RTAX_MTU 4
#define IF_RS_SENT (1 << 0)
#define IF_RA_RCVD (1 << 1)
#define IF_RA_MANAGED (1 << 2)
#define IF_RA_OTHERCONF (1 << 3)
#define RETRANS_TIME 0
#define BASE_REACHABLE_TIME 1
#define GC_STALETIME 2
#define NUD_STALE 0x04
#define NTF_ROUTER 0x80
#define NEIGH_UPDATE_F_WEAK_OVERRIDE (1 << 0)
#define NEIGH_UPDATE_F_OVERRIDE (1 << 1)
#define NEIGH_UPDATE_F_OVERRIDE_ISROUTER (1 << 2)
#define NEIGH_UPDATE_F_ISROUTER (1 << 3)
#define IPV6_MIN_MTU 1280
#define RTM_NEWLINK 16
#define HZ 1000
#define MAX_SCHEDULE_TIMEOUT ((long)(~0UL>>1))

static inline struct ipv6hdr *ipv6_hdr(const struct sk_buff *skb) {
    return (struct ipv6hdr *)skb->data;
}

static inline void *skb_transport_header(const struct sk_buff *skb) {
    return skb->transport_header;
}

static inline void *skb_tail_pointer(const struct sk_buff *skb) {
    return skb->tail;
}

static inline uint16_t ntohs(uint16_t x) {
    return ((x & 0xff) << 8) | ((x >> 8) & 0xff);
}

static inline uint32_t ntohl(uint32_t x) {
    return ((x & 0xff) << 24) | ((x & 0xff00) << 8) | 
           ((x >> 8) & 0xff00) | ((x >> 24) & 0xff);
}

static inline int ipv6_addr_type(const struct in6_addr *addr) {
    return IPV6_ADDR_LINKLOCAL;
}

static inline struct inet6_dev *__in6_dev_get(struct net_device *dev) {
    return NULL;
}

static inline int ndisc_parse_options(__u8 *opt, int optlen, struct ndisc_options *ndopts) {
    return 1;
}

static inline int ipv6_accept_ra(struct inet6_dev *in6_dev) {
    return 1;
}

static inline int ipv6_chk_addr(void *net, struct in6_addr *addr, void *dev, int strict) {
    return 0;
}

static inline void *dev_net(struct net_device *dev) {
    return NULL;
}

static inline struct rt6_info *rt6_get_dflt_router(struct in6_addr *addr, struct net_device *dev) {
    return NULL;
}

static inline struct neighbour *dst_neigh_lookup(void *dst, struct in6_addr *addr) {
    return NULL;
}

static inline void ip6_rt_put(struct rt6_info *rt) {}

static inline void ip6_del_rt(struct rt6_info *rt) {}

static inline struct rt6_info *rt6_add_dflt_router(struct in6_addr *addr, struct net_device *dev, unsigned int pref) {
    return NULL;
}

static inline void rt6_set_expires(struct rt6_info *rt, unsigned long expires) {}

static inline void dst_metric_set(void *dst, int metric, int val) {}

static inline void NEIGH_VAR_SET(void *parms, int var, unsigned long val) {}

static inline unsigned long NEIGH_VAR(void *parms, int var) {
    return 0;
}

static inline void inet6_ifinfo_notify(int event, struct inet6_dev *idev) {}

static inline unsigned long neigh_rand_reach_time(unsigned long base) {
    return base;
}

static inline struct neighbour *__neigh_lookup(struct nd_tbl *tbl, struct in6_addr *addr, struct net_device *dev, int creat) {
    return NULL;
}

static inline u8 *ndisc_opt_addr_data(void *opt, struct net_device *dev) {
    return NULL;
}

static inline void neigh_update(struct neighbour *neigh, u8 *lladdr, int state, int flags) {}

static inline struct nd_opt_hdr *ndisc_next_option(struct nd_opt_hdr *cur, void *end) {
    return NULL;
}

static inline void rt6_route_rcv(struct net_device *dev, u8 *opt, int optlen, struct in6_addr *gwaddr) {}

static inline void addrconf_prefix_rcv(struct net_device *dev, u8 *opt, int optlen, int lladdr) {}

static inline void rt6_mtu_change(struct net_device *dev, unsigned mtu) {}

static inline struct nd_opt_hdr *ndisc_next_useropt(struct nd_opt_hdr *cur, void *end) {
    return NULL;
}

static inline void ndisc_ra_useropt(struct sk_buff *skb, struct nd_opt_hdr *opt) {}

static inline void neigh_release(struct neighbour *neigh) {}