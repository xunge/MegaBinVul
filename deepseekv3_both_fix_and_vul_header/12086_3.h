#include <stddef.h>
#include <stdint.h>
#include <netinet/ip.h>
#include <netinet/igmp.h>
#include <arpa/inet.h>

typedef uint8_t u8;

struct sk_buff {
    unsigned int priority;
    void *dev;
    void *transport_header;
    void *network_header;
};

struct rtable {
    struct {
        void *dst;
    } dst;
};

struct net_device {
    unsigned int ifindex;
    int needed_tailroom;
};

struct net;
struct flowi4 {
    uint32_t daddr;
};

struct igmpv3_report {
    uint8_t type;
    uint8_t resv1;
    uint16_t csum;
    uint16_t resv2;
    uint16_t ngrec;
};

#define GFP_ATOMIC 0
#define __GFP_NOWARN 0
#define TC_PRIO_CONTROL 0
#define IGMPV3_ALL_MCR 0
#define IGMPV3_HOST_MEMBERSHIP_REPORT 0

#define IS_ERR(x) (0)
#define LL_RESERVED_SPACE(x) (0)
#define IP_MAX_MTU 1500
#define min(a, b) ((a) < (b) ? (a) : (b))

static inline struct net *dev_net(struct net_device *dev) { return NULL; }
static inline void *alloc_skb(int size, int flags) { return NULL; }
static inline void kfree_skb(void *skb) {}
static inline void *ip_route_output_ports(struct net *net, struct flowi4 *fl4, void *a, int b, int c, int d, int e, int f, int g, int h) { return NULL; }
static inline void skb_dst_set(struct sk_buff *skb, void *dst) {}
static inline void skb_reserve(struct sk_buff *skb, int len) {}
static inline void skb_tailroom_reserve(struct sk_buff *skb, int mtu, int tlen) {}
static inline void skb_reset_network_header(struct sk_buff *skb) {}
static inline struct iphdr *ip_hdr(struct sk_buff *skb) { return NULL; }
static inline void *skb_put(struct sk_buff *skb, int len) { return NULL; }
static inline void rcu_read_lock() {}
static inline void rcu_read_unlock() {}
static inline uint32_t igmpv3_get_srcaddr(struct net_device *dev, struct flowi4 *fl4) { return 0; }
static inline void ip_select_ident(struct net *net, struct sk_buff *skb, void *null) {}
static inline struct igmpv3_report *igmpv3_report_hdr(struct sk_buff *skb) { return NULL; }