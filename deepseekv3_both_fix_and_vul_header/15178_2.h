#include <stdint.h>
#include <stddef.h>
#include <netinet/in.h>

typedef uint32_t __be32;
typedef uint16_t __be16;
typedef uint8_t __u8;

typedef int netdev_tx_t;
typedef int spinlock_t;

#define NETDEV_TX_OK 0
#define ARPHRD_LOCALTLK 1
#define ETH_P_ATALK 0x809B
#define IPDDP_DECAP 1

struct sk_buff {
    void *data;
    unsigned int len;
    __be16 protocol;
    void *rtable;
};

struct net_device {
    unsigned int type;
    struct {
        unsigned long tx_packets;
        unsigned long tx_bytes;
    } stats;
};

struct atalk_addr {
    __be16 s_net;
    __u8 s_node;
};

struct ddpehdr {
    __be16 deh_len_hops;
    __be16 deh_sum;
    __be16 deh_dnet;
    __be16 deh_snet;
    __u8 deh_dnode;
    __u8 deh_snode;
    __be16 deh_dport;
    __be16 deh_sport;
};

struct ipddp_route {
    __be32 ip;
    struct atalk_addr at;
    struct net_device *dev;
    struct ipddp_route *next;
};

struct rtable {
    __be32 rt_gateway;
};

static spinlock_t ipddp_route_lock;
static struct ipddp_route *ipddp_route_list = NULL;
static int ipddp_mode;

static inline struct rtable *skb_rtable(struct sk_buff *skb) {
    return (struct rtable *)skb->rtable;
}

static inline void skb_pull(struct sk_buff *skb, unsigned int len) {
    skb->data += len;
    skb->len -= len;
}

static inline void spin_lock(spinlock_t *lock) {}
static inline void spin_unlock(spinlock_t *lock) {}

static struct atalk_addr *atalk_find_dev_addr(struct net_device *dev) {
    return NULL;
}

static int aarp_send_ddp(struct net_device *dev, struct sk_buff *skb,
                        struct atalk_addr *sa, void *unused) {
    return 0;
}

static void dev_kfree_skb(struct sk_buff *skb) {}