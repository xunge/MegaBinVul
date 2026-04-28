#include <stdint.h>
#include <string.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

typedef uint32_t u32;
typedef uint8_t u8;

#define unlikely(x) (x)

struct sk_buff {
    void *dev;
    unsigned int len;
    unsigned char *data;
    unsigned char cb[48];
};

struct net_device;
struct in_device;
struct ip_options {
    unsigned char optlen;
    unsigned char srr;
};

struct inet_skb_parm {
    struct ip_options opt;
};

#define IPCB(skb) ((struct inet_skb_parm*)((skb)->cb))
#define IP_INC_STATS_BH(net, field) 
#define IPSTATS_MIB_INTRUNCATEDPKTS 0
#define IPSTATS_MIB_INDISCARDS 0 
#define IPSTATS_MIB_INHDRERRORS 0
#define IN_DEV_SOURCE_ROUTE(in_dev) 0

static inline struct iphdr *ip_hdr(const struct sk_buff *skb) {
    return (struct iphdr *)skb->data;
}

static inline int pskb_may_pull(struct sk_buff *skb, unsigned int len) {
    return 1;
}

static inline int ip_fast_csum(const u8 *iph, unsigned int ihl) {
    return 0;
}

static inline int pskb_trim_rcsum(struct sk_buff *skb, unsigned int len) {
    return 0;
}

static inline void *dev_net(struct net_device *dev) {
    return 0;
}

static inline struct in_device *__in_dev_get_rcu(struct net_device *dev) {
    return 0;
}

static inline int ip_options_compile(void *net, struct ip_options *opt, struct sk_buff *skb) {
    return 0;
}

static inline int ip_options_rcv_srr(struct sk_buff *skb) {
    return 0;
}