#include <stdint.h>
#include <limits.h>
#include <stddef.h>

typedef uint32_t u32;

#define AF_INET6 10
#define RTF_PREFIX_RT 0x00010000
#define RTF_REJECT 0x0200
#define RTF_DYNAMIC 0x0010
#define RTF_ADDRCONF 0x4000
#define RTF_DEFAULT 0x0002
#define RTF_CACHE 0x0100
#define RTF_EXPIRES 0x0004
#define RT6_TABLE_UNSPEC 0
#define RTM_F_CLONED 0x200
#define RTN_UNREACHABLE 7
#define RTN_LOCAL 2
#define RTN_UNICAST 1
#define RT_SCOPE_UNIVERSE 0
#define RTPROT_REDIRECT 1
#define RTPROT_KERNEL 2
#define RTPROT_RA 3
#define EMSGSIZE 90
#define CONFIG_IPV6_SUBTREES 1
#define CONFIG_IPV6_MROUTE 1
#define IFF_LOOPBACK 0x8
#define RTA_TABLE 15
#define RTA_DST 1
#define RTA_SRC 2
#define RTA_IIF 3
#define RTA_PREFSRC 4
#define RTA_GATEWAY 5
#define RTA_OIF 6
#define RTA_PRIORITY 7

struct sk_buff;
struct neighbour;

struct in6_addr {
    uint8_t s6_addr[16];
};

struct inet6_dev {
    void *dev;
    unsigned int flags;
};

struct dst_entry {
    struct neighbour *neighbour;
    struct inet6_dev *dev;
    void *metrics;
    int error;
};

struct rt6_info {
    union {
        struct dst_entry dst;
    } u;
    struct {
        struct in6_addr addr;
        int plen;
    } rt6i_dst;
    struct {
        struct in6_addr addr;
        int plen;
    } rt6i_src;
    struct {
        int tb6_id;
    } *rt6i_table;
    unsigned int rt6i_flags;
    struct inet6_dev *rt6i_dev;
    int rt6i_protocol;
    unsigned long rt6i_expires;
    int rt6i_metric;
};

struct rtmsg {
    unsigned char rtm_family;
    unsigned char rtm_dst_len;
    unsigned char rtm_src_len;
    unsigned char rtm_tos;
    unsigned char rtm_table;
    unsigned char rtm_protocol;
    unsigned char rtm_scope;
    unsigned char rtm_type;
    unsigned int rtm_flags;
};

struct nlmsghdr;

extern int nlmsg_end(struct sk_buff *skb, struct nlmsghdr *nlh);
extern void nlmsg_cancel(struct sk_buff *skb, struct nlmsghdr *nlh);
extern struct nlmsghdr *nlmsg_put(struct sk_buff *skb, u32 pid, u32 seq, int type, int len, unsigned int flags);
extern struct rtmsg *nlmsg_data(struct nlmsghdr *nlh);
extern int rtnetlink_put_metrics(struct sk_buff *skb, void *metrics);
extern int rtnl_put_cacheinfo(struct sk_buff *skb, void *dst, int nowait, int expires, int error, long expires_jiffies, int dst_error);
extern int ip6mr_get_route(struct sk_buff *skb, struct rtmsg *rtm, int nowait);
extern int ipv6_addr_is_multicast(const struct in6_addr *addr);
extern int ipv6_dev_get_saddr(void *dev, const struct in6_addr *daddr, unsigned int srcprefs, struct in6_addr *saddr);
extern struct inet6_dev *ip6_dst_idev(void *dst);

#define NLA_PUT(skb, attrtype, attrlen, data) 0
#define NLA_PUT_U32(skb, attrtype, value) 0

typedef unsigned long jiffies_t;
extern jiffies_t jiffies;