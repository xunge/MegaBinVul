#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef uint32_t __u32;
typedef uint16_t __u16;
typedef uint8_t __u8;
typedef uint8_t u8;

#define ETH_P_IP 0x0800
#define LOOPBACK4_IPV6 0x7f000001
#define NETIF_F_IP_CSUM 0x01
#define NETIF_F_TSO 0x04
#define GFP_ATOMIC 0x20
#define LINUX_MIB_LISTENOVERFLOWS 0
#define LINUX_MIB_LISTENDROPS 1

struct sock {
    struct in6_addr sk_v6_rcv_saddr;
    struct in6_addr sk_v6_daddr;
    int sk_bound_dev_if;
    void (*sk_backlog_rcv)(struct sock *sk, void *skb);
    unsigned int sk_route_caps;
    void *icsk_af_ops;
    int icsk_pmtu_cookie;
    int icsk_ext_hdr_len;
};

struct sk_buff {
    __u16 protocol;
    void *ipv6_hdr;
};

struct request_sock {
    void *pktopts;
};

struct dst_entry {
    struct {
        unsigned int features;
    } *dev;
};

struct flowi6 {
    __u8 dummy;
};

struct ipv6_txoptions {
    __u16 opt_nflen;
    __u16 opt_flen;
    __u8 hop_limit;
};

struct inet_sock {
    void *pinet6;
    __u32 inet_daddr;
    __u32 inet_saddr;
    __u32 inet_rcv_saddr;
    void *inet_opt;
};

struct ipv6_pinfo {
    struct in6_addr saddr;
    struct in6_addr rcv_saddr;
    struct in6_addr daddr;
    struct ipv6_txoptions *opt;
    struct sk_buff *pktoptions;
    __u32 rxopt_all;
    __u8 mcast_hops;
    __u8 mcast_oif;
    struct {
        __u32 all;
    } rxopt;
    void *ipv6_mc_list;
    void *ipv6_ac_list;
    void *ipv6_fl_list;
};

struct inet_request_sock {
    struct request_sock *req;
    struct in6_addr ir_v6_rmt_addr;
    struct in6_addr ir_v6_loc_addr;
    int ir_iif;
    struct ipv6_txoptions *ipv6_opt;
    struct sk_buff *pktopts;
};

struct dccp6_sock {
    struct ipv6_pinfo inet6;
};

struct dccp_af_ops {
    __u8 dummy;
};

static struct dccp_af_ops dccp_ipv6_mapped;

static inline struct inet_request_sock *inet_rsk(const struct request_sock *sk)
{
    return (struct inet_request_sock *)sk;
}

static inline struct ipv6_pinfo *inet6_sk(const struct sock *sk)
{
    return (struct ipv6_pinfo *)sk;
}

static inline struct inet_sock *inet_sk(const struct sock *sk)
{
    return (struct inet_sock *)sk;
}

static inline struct sock *inet_csk(struct sock *sk)
{
    return sk;
}

static inline int inet6_iif(const struct sk_buff *skb)
{
    return 0;
}

static inline struct ipv6_txoptions *ipv6_hdr(const struct sk_buff *skb)
{
    return (struct ipv6_txoptions *)skb->ipv6_hdr;
}

static inline void dccp_sync_mss(struct sock *sk, int mtu) {}
static inline int sk_acceptq_is_full(const struct sock *sk) { return 0; }
static inline struct dst_entry *inet6_csk_route_req(const struct sock *sk, 
                                                  struct flowi6 *fl6,
                                                  const struct request_sock *req,
                                                  u8 proto) { return NULL; }
static inline struct sock *dccp_create_openreq_child(const struct sock *sk,
                                                   struct request_sock *req,
                                                   struct sk_buff *skb) { return NULL; }
static inline void ip6_dst_store(struct sock *sk, struct dst_entry *dst,
                               struct in6_addr *daddr, struct in6_addr *saddr) {}
static inline void *rcu_dereference(void *p) { return p; }
static inline struct ipv6_txoptions *ipv6_dup_options(struct sock *sk,
                                                     struct ipv6_txoptions *opt) { return opt; }
static inline void RCU_INIT_POINTER(void *p, void *v) {}
static inline int dst_mtu(const struct dst_entry *dst) { return 0; }
static inline int __inet_inherit_port(const struct sock *sk, struct sock *child) { return 0; }
static inline void inet_csk_prepare_forced_close(struct sock *sk) {}
static inline void dccp_done(struct sock *sk) {}
static inline bool inet_ehash_nolisten(struct sock *sk, struct sock *child) { return false; }
static inline struct sock *req_to_sk(struct request_sock *req) { return NULL; }
static inline struct sk_buff *skb_clone(struct sk_buff *skb, int priority) { return NULL; }
static inline void consume_skb(struct sk_buff *skb) {}
static inline void skb_set_owner_r(struct sk_buff *skb, struct sock *sk) {}
static inline void __NET_INC_STATS(void *net, int stat) {}
static inline void *sock_net(const struct sock *sk) { return NULL; }
static inline void dst_release(struct dst_entry *dst) {}
static inline struct sock *dccp_v4_request_recv_sock(const struct sock *sk,
                                                   struct sk_buff *skb,
                                                   struct request_sock *req,
                                                   struct dst_entry *dst,
                                                   struct request_sock *req_unhash,
                                                   bool *own_req) { return NULL; }
static inline void dccp_v4_do_rcv(struct sock *sk, void *skb) {}