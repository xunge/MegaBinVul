#include <stdint.h>
#include <stddef.h>
#include <netinet/in.h>

typedef uint8_t u8;
typedef uint16_t __be16;
typedef uint32_t __be32;
typedef uint32_t u32;
typedef uint64_t __u64;

struct sk_buff {
    void *data;
    void *dev;
};

struct inet6_skb_parm;
struct in6_addr;

struct ipv6hdr {
    const struct in6_addr daddr;
    const struct in6_addr saddr;
};

struct dccp_hdr {
    __be16 dccph_sport;
    __be16 dccph_dport;
};

struct dccp_sock {
    __u64 dccps_awl;
    __u64 dccps_awh;
};

struct ipv6_pinfo {
    int dst_cookie;
    int recverr;
};

struct sock {
    int sk_state;
    int sk_err;
    int sk_err_soft;
    void (*sk_error_report)(struct sock *);
};

struct net;
struct inet_hashinfo {
    int dummy;
};

struct inet_hashinfo dccp_hashinfo;

struct inet_connection_sock {
    u32 icsk_pmtu_cookie;
};

enum {
    DCCP_TIME_WAIT,
    DCCP_NEW_SYN_RECV,
    DCCP_CLOSED,
    DCCP_REQUESTING,
    DCCP_RESPOND
};

enum {
    DCCPF_REQUESTING,
    DCCPF_LISTEN,
    DCCPF_CLOSED
};

enum {
    ICMP6_MIB_INERRORS,
    LINUX_MIB_LOCKDROPPEDICMPS,
    LINUX_MIB_OUTOFWINDOWICMPS,
    DCCP_MIB_ATTEMPTFAILS
};

enum {
    NDISC_REDIRECT,
    ICMPV6_PKT_TOOBIG
};

struct dst_entry {
    struct dst_ops *ops;
};

struct dst_ops {
    void (*redirect)(struct dst_entry *, struct sock *, struct sk_buff *);
};

#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))
#define offsetofend(type, member) (offsetof(type, member) + sizeof(((type *)0)->member))

struct net *dev_net(void *dev);
struct sock *__inet6_lookup_established(struct net *net, struct inet_hashinfo *hashinfo,
                                      const struct in6_addr *daddr, __be16 dport,
                                      const struct in6_addr *saddr, __be16 sport, int dif);
int inet6_iif(struct sk_buff *skb);
void __ICMP6_INC_STATS(struct net *net, void *dev, int stat);
void *__in6_dev_get(void *dev);
void inet_twsk_put(void *twsk);
void *inet_twsk(struct sock *sk);
__u64 dccp_hdr_seq(const struct dccp_hdr *dh);
void dccp_req_err(struct sock *sk, __u64 seq);
void bh_lock_sock(struct sock *sk);
int sock_owned_by_user(struct sock *sk);
void __NET_INC_STATS(struct net *net, int stat);
struct dccp_sock *dccp_sk(struct sock *sk);
int between48(__u64 seq, __u64 awl, __u64 awh);
struct ipv6_pinfo *inet6_sk(struct sock *sk);
struct dst_entry *__sk_dst_check(struct sock *sk, int cookie);
int ip6_sk_accept_pmtu(struct sock *sk);
struct dst_entry *inet6_csk_update_pmtu(struct sock *sk, u32 pmtu);
struct inet_connection_sock *inet_csk(struct sock *sk);
int dst_mtu(const struct dst_entry *dst);
void dccp_sync_mss(struct sock *sk, int mtu);
void icmpv6_err_convert(u8 type, u8 code, int *err);
void __DCCP_INC_STATS(int stat);
void dccp_done(struct sock *sk);
void bh_unlock_sock(struct sock *sk);
void sock_put(struct sock *sk);