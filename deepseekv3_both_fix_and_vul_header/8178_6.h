#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <netinet/ip6.h>
#include <netinet/tcp.h>

typedef uint32_t __u32;
typedef uint16_t __be16;
typedef uint32_t __be32;
typedef uint8_t u8;

struct sk_buff {
    void *data;
    struct net_device *dev;
};

struct net_device {
    int ifindex;
    void *ip6_ptr;
};

struct net;
struct inet6_skb_parm;
struct request_sock {
    struct sock *sk;
    __u32 snt_isn;
};
struct ipv6_pinfo {
    int dst_cookie;
    bool recverr;
    int min_hopcount;
};
struct tcp_sock {
    struct request_sock *fastopen_rsk;
    __u32 snd_una;
    __u32 snd_nxt;
    __u32 mtu_info;
};
struct sock {
    int sk_state;
    int sk_err;
    int sk_err_soft;
    unsigned long sk_tsq_flags;
    void (*sk_error_report)(struct sock *);
};
struct dst_entry {
    struct dst_ops *ops;
};
struct dst_ops {
    void (*redirect)(struct dst_entry *, struct sock *, struct sk_buff *);
};
struct ipv6hdr {
    struct in6_addr saddr;
    struct in6_addr daddr;
    u8 hop_limit;
};
struct tcp_hashinfo {
    // Minimal definition to satisfy compilation
    int dummy;
};

static struct tcp_hashinfo tcp_hashinfo = {0};

static inline struct net *dev_net(struct net_device *dev) { return NULL; }
static inline void *__in6_dev_get(struct net_device *dev) { return dev->ip6_ptr; }
static inline void *inet_twsk(struct sock *sk) { return (void *)sk; }
static inline struct sock *__inet6_lookup_established(struct net *net, struct tcp_hashinfo *hashinfo, 
    const struct in6_addr *daddr, __be16 dest, const struct in6_addr *saddr, __be16 source, int ifindex) { return NULL; }
static inline void __ICMP6_INC_STATS(struct net *net, void *dev, int type) {}
static inline void inet_twsk_put(void *sk) {}
static inline bool icmpv6_err_convert(u8 type, u8 code, int *err) { return false; }
static inline void tcp_req_err(struct sock *sk, __u32 seq, bool fatal) {}
static inline void bh_lock_sock(struct sock *sk) {}
static inline bool sock_owned_by_user(struct sock *sk) { return false; }
static inline void __NET_INC_STATS(struct net *net, int type) {}
static inline struct ipv6hdr *ipv6_hdr(const struct sk_buff *skb) { return NULL; }
static inline struct ipv6_pinfo *inet6_sk(const struct sock *sk) { return NULL; }
static inline struct tcp_sock *tcp_sk(const struct sock *sk) { return NULL; }
static inline struct request_sock *tcp_rsk(const struct request_sock *req) { return NULL; }
static inline bool between(__u32 seq, __u32 lower, __u32 upper) { return false; }
static inline struct dst_entry *__sk_dst_check(struct sock *sk, int cookie) { return NULL; }
static inline bool ip6_sk_accept_pmtu(const struct sock *sk) { return false; }
static inline void tcp_v6_mtu_reduced(struct sock *sk) {}
static inline bool test_and_set_bit(int nr, unsigned long *addr) { return false; }
static inline void sock_hold(struct sock *sk) {}
static inline void tcp_done(struct sock *sk) {}
static inline void bh_unlock_sock(struct sock *sk) {}
static inline void sock_put(struct sock *sk) {}

#define TCP_TIME_WAIT 0
#define TCP_NEW_SYN_RECV 1
#define TCP_CLOSE 2
#define TCP_LISTEN 3
#define TCP_SYN_SENT 4
#define TCP_SYN_RECV 5
#define ICMPV6_PKT_TOOBIG 6
#define NDISC_REDIRECT 7
#define ICMP6_MIB_INERRORS 8
#define LINUX_MIB_LOCKDROPPEDICMPS 9
#define LINUX_MIB_TCPMINTTLDROP 10
#define LINUX_MIB_OUTOFWINDOWICMPS 11
#define TCP_MTU_REDUCED_DEFERRED 12