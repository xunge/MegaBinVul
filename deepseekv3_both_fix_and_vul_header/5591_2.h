#include <stdint.h>
#include <string.h>

typedef uint32_t __be32;
typedef uint32_t u32;

#define AF_INET 2
#define RTAX_MAX 8
#define RTAX_MTU 2
#define RT_TABLE_MAIN 254
#define RT_SCOPE_UNIVERSE 0
#define RTPROT_UNSPEC 0
#define RTM_F_CLONED 0x400
#define RTM_F_NOTIFY 0x100
#define EMSGSIZE 90
#define RTA_TABLE 1
#define RTA_DST 2
#define RTA_SRC 3
#define RTA_OIF 4
#define RTA_PREFSRC 7
#define RTA_GATEWAY 5
#define RTA_MARK 16
#define RTA_IIF 17
#define RTA_FLOW 11

struct net;
struct sk_buff {
    struct {
        int ifindex;
    } *dev;
};
struct rtable {
    int rt_type;
    unsigned int rt_flags;
    __be32 rt_gateway;
    int rt_uses_gateway;
    int rt_pmtu;
    struct {
        unsigned long expires;
        int error;
        struct {
            int ifindex;
            int tclassid;
        } *dev;
    } dst;
};
struct flowi4 {
    __be32 saddr;
    __be32 daddr;
    __be32 flowi4_tos;
    __be32 flowi4_mark;
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
struct IPCB {
    int flags;
};

#define IPCB(skb) ((struct IPCB*)(skb))
#define IPSKB_DOREDIRECT 1
#define RTCF_NOTIFY 0x00010000
#define RTCF_DOREDIRECT 0x00020000

static unsigned long jiffies = 0;

static inline int nla_put_u32(struct sk_buff *skb, int attr, u32 value) { return 0; }
static inline int nla_put_be32(struct sk_buff *skb, int attr, __be32 value) { return 0; }
static inline int rtnetlink_put_metrics(struct sk_buff *skb, u32 *metrics) { return 0; }
static inline int rtnl_put_cacheinfo(struct sk_buff *skb, void *dst, int direct, unsigned long expires, u32 error) { return 0; }
static inline struct nlmsghdr *nlmsg_put(struct sk_buff *skb, u32 portid, u32 seq, int type, int len, int flags) { return 0; }
static inline void *nlmsg_data(struct nlmsghdr *nlh) { return 0; }
static inline int nlmsg_end(struct sk_buff *skb, struct nlmsghdr *nlh) { return 0; }
static inline void nlmsg_cancel(struct sk_buff *skb, struct nlmsghdr *nlh) {}
static inline struct rtable *skb_rtable(struct sk_buff *skb) { return 0; }
static inline int rt_is_input_route(struct rtable *rt) { return 0; }
static inline u32 *dst_metrics_ptr(void *dst) { return 0; }
static inline int ipv4_is_multicast(__be32 addr) { return 0; }
static inline int ipv4_is_local_multicast(__be32 addr) { return 0; }
static inline int ipmr_get_route(struct net *net, struct sk_buff *skb, __be32 saddr, __be32 daddr, struct rtmsg *r, int nowait) { return 0; }
static inline int time_before(unsigned long a, unsigned long b) { return 0; }