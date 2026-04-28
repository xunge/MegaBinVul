#include <stdint.h>
#include <stdlib.h>

struct sock {
    int sk_filter;
    int sk_drops;
};

struct sk_buff {
    unsigned int len;
    uint8_t cb[48];
};

struct udp_sock {
    int encap_type;
    int (*encap_rcv)(struct sock *sk, struct sk_buff *skb);
    int pcrlen;
};

struct udphdr {
    uint16_t source;
    uint16_t dest;
    uint16_t len;
    uint16_t check;
};

struct udp_skb_cb {
    int partial_cov;
    int cscov;
};

#define IS_UDPLITE(sk) (0)
#define XFRM_POLICY_IN 0
#define UDPLITE_RECV_CC 0
#define UDP_MIB_INDATAGRAMS 0
#define UDP_MIB_INERRORS 0
#define KERN_WARNING ""
#define LIMIT_NETDEBUG(fmt, ...)

#define UDP_SKB_CB(skb) ((struct udp_skb_cb *)&((skb)->cb[0]))

static inline struct udp_sock *udp_sk(const struct sock *sk) { return (struct udp_sock *)sk; }
static inline void nf_reset(struct sk_buff *skb) {}
static inline int xfrm4_policy_check(struct sock *sk, int policy, struct sk_buff *skb) { return 1; }
static inline void UDP_INC_STATS_BH(void *net, int field, int is_udplite) {}
static inline int udp_lib_checksum_complete(struct sk_buff *skb) { return 0; }
static inline void bh_lock_sock(struct sock *sk) {}
static inline void bh_unlock_sock(struct sock *sk) {}
static inline int sock_owned_by_user(struct sock *sk) { return 0; }
static inline int __udp_queue_rcv_skb(struct sock *sk, struct sk_buff *skb) { return 0; }
static inline int sk_add_backlog(struct sock *sk, struct sk_buff *skb) { return 0; }
static inline void *sock_net(struct sock *sk) { return NULL; }
static inline void kfree_skb(struct sk_buff *skb) {}
static inline void atomic_inc(int *counter) { (*counter)++; }