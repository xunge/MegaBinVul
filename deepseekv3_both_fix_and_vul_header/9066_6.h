#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip6.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define PF_INET6 10
#define CAP_NET_RAW 13
#define GFP_KERNEL 0
#define SK_CAN_REUSE 1
#define INET_PROTOSW_REUSE 0x01
#define INET_PROTOSW_ICSK 0x02
#define IPV6_DEFAULT_MCASTHOPS 1

struct socket {
    int type;
    void *ops;
};

struct net {
    struct {
        struct {
            int bindv6only;
        } sysctl;
    } ipv6;
    struct {
        struct {
            int sysctl_ip_no_pmtu_disc;
        } ipv4;
    };
    void *user_ns;
};

struct sock {
    int sk_family;
    int sk_protocol;
    int sk_reuse;
    int sk_ipv6only;
    struct proto *sk_prot;
    void (*sk_destruct)(struct sock *);
    void (*sk_backlog_rcv)(struct sock *);
};

struct inet_sock {
    int is_icsk;
    int inet_num;
    int hdrincl;
    short inet_sport;
    int uc_ttl;
    int mc_loop;
    int mc_ttl;
    int mc_index;
    void *mc_list;
    int rcv_tos;
    int pmtudisc;
    void *pinet6;
};

struct ipv6_pinfo {
    int hop_limit;
    int mcast_hops;
    int mc_loop;
    int pmtudisc;
    int autoflowlabel;
};

struct inet_protosw {
    int protocol;
    void *ops;
    struct proto *prot;
    unsigned char flags;
    struct list_head *list;
};

struct proto {
    void *slab;
    void (*backlog_rcv)(struct sock *);
    void (*hash)(struct sock *);
    int (*init)(struct sock *);
};

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

#define list_for_each_entry_rcu(pos, head, member) \
    for (pos = (typeof(*pos)*)(head); pos; pos = (typeof(*pos)*)pos->member->next)

extern struct inet_protosw inetsw6[];
extern void rcu_read_lock(void);
extern void rcu_read_unlock(void);
extern void request_module(const char *name, ...);
extern int ns_capable(void *user_ns, int cap);
extern void WARN_ON(int condition);
extern struct sock *sk_alloc(struct net *net, int family, int priority, struct proto *prot, int kern);
extern void sock_init_data(struct socket *sock, struct sock *sk);
extern struct inet_sock *inet_sk(struct sock *sk);
extern void *inet6_sk_generic(struct sock *sk);
extern void sk_refcnt_debug_inc(struct sock *sk);
extern void sk_common_release(struct sock *sk);
extern void inet_sock_destruct(struct sock *sk);
extern void *sock_net(struct sock *sk);
extern int ip6_default_np_autolabel(void *net);