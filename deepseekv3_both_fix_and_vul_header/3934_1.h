#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define NET_XMIT_DROP 0
#define NET_XMIT_SUCCESS 1
#define RT_TOS(tos) ((tos)&0x1e)
#define FLOWI_FLAG_ANYSRC 0x01
#define RTN_UNICAST 1
#define RTN_LOCAL 2
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define unlikely(x) (x)

struct iphdr {
    uint8_t tos;
    uint32_t daddr;
    uint32_t saddr;
};

struct net_device {
    int ifindex;
    unsigned long mark;
    struct {
        int tx_errors;
    } stats;
    void *sk;
};

struct net {};

struct rtable {
    int rt_type;
    struct {
        int dst;
    } dst;
};

struct flowi4 {
    int flowi4_oif;
    uint8_t flowi4_tos;
    uint8_t flowi4_flags;
    unsigned long flowi4_mark;
    uint32_t daddr;
    uint32_t saddr;
};

struct sk_buff {
    const struct iphdr *ip_hdr;
    struct net_device *dev;
    unsigned long mark;
    void *sk;
};

static inline const struct iphdr *ip_hdr(const struct sk_buff *skb) { return skb->ip_hdr; }
static inline struct net *dev_net(struct net_device *dev) { return NULL; }
static inline void ip_rt_put(struct rtable *rt) {}
static inline void skb_dst_set(struct sk_buff *skb, int *dst) {}
static inline void *IPCB(struct sk_buff *skb) { return NULL; }
static inline int ip_local_out(struct net *net, void *sk, struct sk_buff *skb) { return 0; }
static inline int net_xmit_eval(int err) { return err; }
static inline void kfree_skb(struct sk_buff *skb) {}
static struct rtable *ip_route_output_flow(struct net *net, struct flowi4 *fl4, void *null) { return NULL; }