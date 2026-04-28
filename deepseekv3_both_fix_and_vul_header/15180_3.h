#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

typedef uint16_t __u16;

struct sk_buff {
    unsigned int len;
    void *sk;
};

struct ddpehdr {
    __u16 deh_len_hops;
    __u16 deh_sum;
    __u16 deh_dnet;
    __u16 deh_dnode;
    __u16 deh_dport;
};

struct sockaddr_at {
    struct {
        __u16 s_net;
        __u16 s_node;
    } sat_addr;
    __u16 sat_port;
};

struct init_net {};

extern struct init_net init_net;

#define GFP_ATOMIC 0
#define NET_RX_SUCCESS 0
#define NET_RX_DROP 1

static inline bool net_eq(void *a, void *b) { return false; }
static inline void *dev_net(struct net_device *dev) { return NULL; }
static inline struct sk_buff *skb_share_check(struct sk_buff *skb, int flags) { return NULL; }
static inline bool pskb_may_pull(struct sk_buff *skb, unsigned int size) { return false; }
static inline struct ddpehdr *ddp_hdr(struct sk_buff *skb) { return NULL; }
static inline uint16_t ntohs(uint16_t x) { return x; }
static inline void skb_trim(struct sk_buff *skb, unsigned int len) {}
static inline int atalk_checksum(struct sk_buff *skb, int len) { return 0; }
static inline struct atalk_iface *atalk_find_anynet(int node, struct net_device *dev) { return NULL; }
static inline struct atalk_iface *atalk_find_interface(int net, int node) { return NULL; }
static inline int atalk_route_packet(struct sk_buff *skb, struct net_device *dev, struct ddpehdr *ddp, uint16_t len_hops, int origlen) { return 0; }
static inline bool is_ip_over_ddp(struct sk_buff *skb) { return false; }
static inline int handle_ip_over_ddp(struct sk_buff *skb) { return 0; }
static inline struct sock *atalk_search_socket(struct sockaddr_at *addr, struct atalk_iface *atif) { return NULL; }
static inline int sock_queue_rcv_skb(struct sock *sk, struct sk_buff *skb) { return 0; }
static inline void kfree_skb(struct sk_buff *skb) {}

#define min_t(type, x, y) ((x) < (y) ? (x) : (y))
#define pr_debug(fmt, ...) printf(fmt, ##__VA_ARGS__)