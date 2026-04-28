#include <stddef.h>
#include <stdint.h>
#include <netinet/in.h>
#include <netinet/ip6.h>
#include <netinet/tcp.h>

typedef uint32_t __u32;
typedef uint16_t __u16;
typedef uint8_t __u8;

struct sock {
    int sk_state;
    void *sk_rx_dst;
    // other members...
};

struct inet_sock {
    int rx_dst_ifindex;
    // other members...
};

struct sk_buff {
    __u16 protocol;
    int skb_iif;
    int len;
    // other members...
};

struct ipv6_pinfo {
    struct {
        int all;
        struct {
            int rxinfo;
            int rxoinfo;
            int rxhlim;
            int rxohlim;
            int rxflow;
            int rxtclass;
        } bits;
    } rxopt;
    int mcast_oif;
    int mcast_hops;
    __u32 rcv_flowinfo;
    int repflow;
    __u32 flow_label;
    __u32 rx_dst_cookie;
    struct sk_buff *pktoptions;
    // other members...
};

struct tcp_sock {
    __u32 rcv_nxt;
    // other members...
};

struct dst_entry {
    struct dst_ops *ops;
    // other members...
};

struct dst_ops {
    int (*check)(struct dst_entry *, __u32);
    // other members...
};

struct ipv6hdr {
    __u8 hop_limit;
    // other members...
};

#define ETH_P_IP 0x0800
#define TCP_ESTABLISHED 1
#define TCP_LISTEN 2
#define TCPF_CLOSE (1<<3)
#define TCPF_LISTEN (1<<4)
#define GFP_ATOMIC 0
#define TCP_MIB_CSUMERRORS 0
#define TCP_MIB_INERRS 1

static inline struct ipv6_pinfo *inet6_sk(struct sock *sk) { return (struct ipv6_pinfo *)sk; }
static inline struct inet_sock *inet_sk(struct sock *sk) { return (struct inet_sock *)sk; }
static inline struct tcp_sock *tcp_sk(struct sock *sk) { return (struct tcp_sock *)sk; }
static inline struct ipv6hdr *ipv6_hdr(struct sk_buff *skb) { return (struct ipv6hdr *)skb; }
static inline __u32 ip6_flowinfo(struct ipv6hdr *hdr) { return 0; }
static inline __u32 ip6_flowlabel(struct ipv6hdr *hdr) { return 0; }
static inline int tcp_v6_iif(struct sk_buff *skb) { return 0; }
static inline void *tcp_hdr(struct sk_buff *skb) { return (void *)skb; }

// Dummy function implementations
static inline int sk_filter(struct sock *sk, struct sk_buff *skb) { return 0; }
static inline struct sk_buff *skb_clone(struct sk_buff *skb, int flags) { return skb; }
static inline int sk_gfp_mask(struct sock *sk, int flags) { return 0; }
static inline void sock_rps_save_rxhash(struct sock *sk, struct sk_buff *skb) {}
static inline void sk_mark_napi_id(struct sock *sk, struct sk_buff *skb) {}
static inline void dst_release(struct dst_entry *dst) {}
static inline int tcp_rcv_established(struct sock *sk, struct sk_buff *skb, void *hdr, int len) { return 0; }
static inline int tcp_checksum_complete(struct sk_buff *skb) { return 0; }
static inline struct sock *tcp_v6_cookie_check(struct sock *sk, struct sk_buff *skb) { return sk; }
static inline int tcp_child_process(struct sock *sk, struct sock *nsk, struct sk_buff *skb) { return 0; }
static inline void __kfree_skb(struct sk_buff *skb) {}
static inline void kfree_skb(struct sk_buff *skb) {}
static inline int tcp_rcv_state_process(struct sock *sk, struct sk_buff *skb) { return 0; }
static inline void tcp_v6_send_reset(struct sock *sk, struct sk_buff *skb) {}
static inline void TCP_INC_STATS(void *net, int stat) {}
static inline void *sock_net(struct sock *sk) { return NULL; }
static inline void skb_set_owner_r(struct sk_buff *skb, struct sock *sk) {}
static inline void tcp_v6_restore_cb(struct sk_buff *skb) {}
static inline struct sk_buff *xchg(struct sk_buff **ptr, struct sk_buff *skb) { return *ptr; }
static inline int ipv6_opt_accepted(struct sock *sk, struct sk_buff *skb, void *hdr) { return 0; }
static inline int tcp_v4_do_rcv(struct sock *sk, struct sk_buff *skb) { return 0; }

#define TCP_SKB_CB(skb) ((struct tcp_skb_cb *)skb)
struct tcp_skb_cb {
    __u32 end_seq;
    struct {
        struct ipv6hdr h6;
    } header;
};