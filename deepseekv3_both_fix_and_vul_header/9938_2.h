#include <stdint.h>
#include <stdlib.h>

struct sock {
    int sk_filter;
    int sk_drops;
};

struct sk_buff {
    int len;
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

struct net;

#define IS_UDPLITE(sk) 0
#define UDPLITE_RECV_CC 1
#define XFRM_POLICY_IN 0
#define UDP_MIB_INDATAGRAMS 0
#define UDP_MIB_INERRORS 0
#define KERN_WARNING 0

#define LIMIT_NETDEBUG(fmt, ...)
#define UDP_INC_STATS_BH(net, metric, is_udplite)
#define UDP_SKB_CB(skb) ((struct udp_skb_cb *)0)
#define sock_net(sk) ((struct net *)0)
#define sock_owned_by_user(sk) 0
#define bh_lock_sock(sk)
#define bh_unlock_sock(sk)
#define kfree_skb(skb)
#define atomic_inc(v)
#define nf_reset(skb)
#define sk_add_backlog(sk, skb) 0
#define udp_sk(sk) ((struct udp_sock *)0)
#define xfrm4_policy_check(sk, dir, skb) 1
#define udp_lib_checksum_complete(skb) 0

int __udp_queue_rcv_skb(struct sock *sk, struct sk_buff *skb);