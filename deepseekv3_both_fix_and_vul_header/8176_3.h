#include <stdint.h>
#include <stddef.h>
#include <arpa/inet.h>

typedef uint32_t u32;
typedef uint8_t u8;
typedef uint64_t __u64;

struct icmphdr {
    u8 type;
    u8 code;
};

struct sk_buff {
    void *data;
    void *dev;
};

struct iphdr {
    u8 ihl;
    u32 saddr;
    u32 daddr;
};

struct dccp_hdr {
    uint16_t dccph_sport;
    uint16_t dccph_dport;
};

struct sock {
    int sk_state;
    int sk_err;
    int sk_err_soft;
    void (*sk_error_report)(struct sock *);
};

struct dccp_sock {
    __u64 dccps_awl;
    __u64 dccps_awh;
};

struct inet_sock {
    int recverr;
};

struct net {};

struct icmp_err {
    int errno;
};

extern struct icmp_err icmp_err_convert[];
extern struct net *dev_net(void *dev);
extern int inet_iif(struct sk_buff *skb);
extern struct sock *__inet_lookup_established(struct net *net, void *hashinfo,
                                            u32 saddr, uint16_t sport,
                                            u32 daddr, uint16_t dport,
                                            int dif);
extern void inet_twsk_put(void *twsk);
extern void *inet_twsk(struct sock *sk);
extern __u64 dccp_hdr_seq(const struct dccp_hdr *dh);
extern void dccp_req_err(struct sock *sk, __u64 seq);
extern void bh_lock_sock(struct sock *sk);
extern int sock_owned_by_user(struct sock *sk);
extern struct dccp_sock *dccp_sk(struct sock *sk);
extern int between48(__u64 seq, __u64 a, __u64 b);
extern void dccp_do_redirect(struct sk_buff *skb, struct sock *sk);
extern void dccp_do_pmtu_discovery(struct sock *sk, const struct iphdr *iph, u32 info);
extern void dccp_done(struct sock *sk);
extern void bh_unlock_sock(struct sock *sk);
extern void sock_put(struct sock *sk);
extern struct inet_sock *inet_sk(struct sock *sk);
extern struct icmphdr *icmp_hdr(const struct sk_buff *skb);

void *dccp_hashinfo;

#define BUILD_BUG_ON(cond) ((void)sizeof(char[1 - 2*!!(cond)]))
#define offsetofend(type, member) (offsetof(type, member) + sizeof(((type *)0)->member))
#define __ICMP_INC_STATS(net, field) 
#define __NET_INC_STATS(net, field) 
#define __DCCP_INC_STATS(field) 
#define DCCP_TIME_WAIT 0
#define DCCP_NEW_SYN_RECV 1
#define DCCP_CLOSED 2
#define DCCPF_REQUESTING 3
#define DCCPF_LISTEN 4
#define DCCP_REQUESTING 5
#define DCCP_RESPOND 6
#define ICMP_REDIRECT 0
#define ICMP_SOURCE_QUENCH 1
#define ICMP_PARAMETERPROB 2
#define ICMP_DEST_UNREACH 3
#define ICMP_TIME_EXCEEDED 4
#define ICMP_FRAG_NEEDED 5
#define NR_ICMP_UNREACH 6
#define LINUX_MIB_LOCKDROPPEDICMPS 0
#define LINUX_MIB_OUTOFWINDOWICMPS 1
#define DCCP_MIB_ATTEMPTFAILS 0
#define EPROTO 0
#define EHOSTUNREACH 0