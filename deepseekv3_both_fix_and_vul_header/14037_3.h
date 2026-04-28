#include <stdint.h>
#include <string.h>

#define RTA_MAX 16
#define RTA_SRC 1
#define RTA_DST 2
#define RTA_IIF 3
#define RTA_MARK 8
#define RTA_UID 25
#define RTA_OIF 4
#define RT_TABLE_MAIN 254
#define GFP_KERNEL 0
#define NLMSG_GOODSIZE 4096
#define MAX_HEADER 128
#define ETH_P_IP 0x0800
#define IPPROTO_UDP 17
#define RTM_F_NOTIFY 0x100
#define RTM_F_LOOKUP_TABLE 0x1000
#define RTM_F_FIB_MATCH 0x2000
#define RTM_NEWROUTE 24
#define RTCF_NOTIFY 0x00010000
#define ENOBUFS 105
#define ENODEV 19
#define EHOSTUNREACH 113

typedef uint32_t __be32;
typedef uint32_t u32;
typedef int32_t kuid_t;

struct sk_buff {
    void *sk;
    void *dev;
    uint32_t protocol;
    uint32_t mark;
    unsigned char *head;
    unsigned char *data;
    uint32_t portid;
};

struct nlmsghdr {
    uint32_t nlmsg_seq;
    void *nlmsg_data;
};

struct netlink_ext_ack {
};

struct net {
};

struct rtmsg {
    uint8_t rtm_tos;
    uint32_t rtm_flags;
};

struct nlattr {
};

struct fib_result {
    int type;
    void *fi;
    uint32_t prefix;
    uint32_t prefixlen;
};

struct rtable {
    uint32_t rt_table_id;
    uint32_t rt_type;
    uint32_t rt_flags;
    struct {
        int error;
    } dst;
};

struct flowi4 {
    __be32 daddr;
    __be32 saddr;
    uint8_t flowi4_tos;
    uint32_t flowi4_oif;
    uint32_t flowi4_mark;
    kuid_t flowi4_uid;
};

struct net_device {
};

struct fib_props {
    int error;
};

struct iphdr {
    uint8_t protocol;
    __be32 saddr;
    __be32 daddr;
};

struct netlink_cb {
    uint32_t portid;
};

#define NETLINK_CB(skb) ((struct netlink_cb){.portid = (skb)->portid})

extern struct fib_props fib_props[];
extern kuid_t INVALID_UID;
extern kuid_t current_uid();
extern void *current_user_ns();
extern void *rtm_ipv4_policy;

static inline __be32 nla_get_in_addr(struct nlattr *attr) { return 0; }
static inline u32 nla_get_u32(struct nlattr *attr) { return 0; }
static inline kuid_t make_kuid(void *ns, u32 uid) { return 0; }
static inline void *nlmsg_data(struct nlmsghdr *nlh) { return nlh->nlmsg_data; }
static inline int nlmsg_parse(struct nlmsghdr *nlh, int size, struct nlattr *tb[], int max, void *policy, struct netlink_ext_ack *extack) { return 0; }
static inline void *alloc_skb(int size, int flags) { return NULL; }
static inline void skb_reset_mac_header(struct sk_buff *skb) {}
static inline void skb_reset_network_header(struct sk_buff *skb) {}
static inline struct iphdr *ip_hdr(struct sk_buff *skb) { return (struct iphdr *)skb->data; }
static inline void skb_reserve(struct sk_buff *skb, int len) { skb->data = skb->head + len; }
static inline void *sock_net(void *sk) { return NULL; }
static inline void *dev_get_by_index_rcu(struct net *net, u32 iif) { return NULL; }
static inline uint16_t htons(uint16_t val) { return val; }
static inline int ip_route_input_rcu(struct sk_buff *skb, __be32 dst, __be32 src, uint8_t tos, struct net_device *dev, struct fib_result *res) { return 0; }
static inline void *skb_rtable(struct sk_buff *skb) { return NULL; }
static inline void *ip_route_output_key_hash_rcu(struct net *net, struct flowi4 *fl4, struct fib_result *res, struct sk_buff *skb) { return NULL; }
static inline int IS_ERR(void *ptr) { return 0; }
static inline int PTR_ERR(void *ptr) { return 0; }
static inline void skb_dst_set(struct sk_buff *skb, void *dst) {}
static inline int fib_dump_info(struct sk_buff *skb, uint32_t portid, uint32_t seq, int type, uint32_t table_id, uint32_t rt_type, uint32_t prefix, uint32_t prefixlen, uint8_t tos, void *fi, int flags) { return 0; }
static inline int rt_fill_info(struct net *net, __be32 dst, __be32 src, uint32_t table_id, struct flowi4 *fl4, struct sk_buff *skb, uint32_t portid, uint32_t seq) { return 0; }
static inline int rtnl_unicast(struct sk_buff *skb, struct net *net, uint32_t portid) { return 0; }
static inline void kfree_skb(struct sk_buff *skb) {}
static inline void rcu_read_lock() {}
static inline void rcu_read_unlock() {}

struct fib_props fib_props[] = {};
kuid_t INVALID_UID = {};
void *rtm_ipv4_policy = NULL;