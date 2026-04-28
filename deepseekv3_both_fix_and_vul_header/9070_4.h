#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

struct sk_buff;

struct net {
    struct {
        struct {
            int sysctl_ip_no_pmtu_disc;
        } ipv4;
    };
    void *user_ns;
};

struct socket {
    int type;
    int state;
    void *ops;
};

struct sock {
    int sk_reuse;
    int sk_protocol;
    struct proto *sk_prot;
    void (*sk_destruct)(struct sock *);
    int (*sk_backlog_rcv)(struct sock *, struct sk_buff *);
};

struct inet_protosw {
    int protocol;
    void *ops;
    struct proto *prot;
    unsigned char flags;
    struct inet_protosw *next;
};

struct inet_sock {
    int is_icsk;
    int nodefrag;
    int inet_num;
    int hdrincl;
    int pmtudisc;
    int inet_id;
    short inet_sport;
    int uc_ttl;
    int mc_loop;
    int mc_ttl;
    int mc_all;
    int mc_index;
    void *mc_list;
    int rcv_tos;
};

struct proto {
    void *slab;
    int (*hash)(struct sock *);
    int (*init)(struct sock *);
    int (*backlog_rcv)(struct sock *, struct sk_buff *);
};

#define SS_UNCONNECTED 1
#define INET_PROTOSW_REUSE 0x01
#define INET_PROTOSW_ICSK 0x02
#define SK_CAN_REUSE 1
#define GFP_KERNEL 0
#define CAP_NET_RAW 13

#define list_for_each_entry_rcu(pos, head, member) \
    for (pos = (head); pos != NULL; pos = pos->next)

#define unlikely(x) (x)
#define WARN_ON(cond) do { if (cond) {} } while (0)

extern struct inet_protosw *inetsw[];
extern void rcu_read_lock(void);
extern void rcu_read_unlock(void);
extern void request_module(const char *name, ...);
extern int ns_capable(void *user_ns, int cap);
extern void sock_init_data(struct socket *sock, struct sock *sk);
extern void sk_refcnt_debug_inc(struct sock *sk);
extern void sk_common_release(struct sock *sk);
extern struct sock *sk_alloc(struct net *net, int family, int priority, struct proto *prot, int kern);
extern struct inet_sock *inet_sk(const struct sock *sk);
extern void inet_sock_destruct(struct sock *sk);