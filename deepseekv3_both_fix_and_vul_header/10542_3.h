#include <sys/socket.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <string.h>

#define GFP_KERNEL 0
#define SOCK_ZAPPED 0
#define PF_INET6 10

struct sock {
    struct {
        int (*init)(struct sock *);
    } *sk_prot;
    int sk_v6_rcv_saddr;
    struct ipv6_pinfo *pinet6;
};

struct sctp_association {
    struct {
        struct {
            int primary_addr;
        } peer;
    };
};

struct ipv6_pinfo {
    void *ipv6_mc_list;
    void *ipv6_ac_list;
    void *ipv6_fl_list;
    struct ipv6_txoptions *opt;
};

struct sctp6_sock {
    struct ipv6_pinfo inet6;
    bool v4mapped;
};

struct ipv6_txoptions;

static inline struct ipv6_pinfo *inet6_sk(struct sock *sk) { return NULL; }
static inline void *sk_alloc(void *net, int family, int flags, int prot, bool kern) { return NULL; }
static inline void *sock_net(struct sock *sk) { return NULL; }
static inline void sock_init_data(void *a, struct sock *b) {}
static inline void sctp_copy_sock(struct sock *a, struct sock *b, struct sctp_association *c) {}
static inline void sock_reset_flag(struct sock *a, int b) {}
static inline struct sock *inet_sk(struct sock *sk) { return sk; }
static inline struct sctp6_sock *sctp_sk(struct sock *sk) { return (struct sctp6_sock *)sk; }
static inline void rcu_read_lock(void) {}
static inline void rcu_read_unlock(void) {}
static inline struct ipv6_txoptions *rcu_dereference(struct ipv6_txoptions *opt) { return NULL; }
static inline struct ipv6_txoptions *ipv6_dup_options(struct sock *sk, struct ipv6_txoptions *opt) { return NULL; }
static inline void RCU_INIT_POINTER(void *a, void *b) {}
static inline void sctp_v6_to_sk_daddr(void *a, struct sock *b) {}
static inline void sk_refcnt_debug_inc(struct sock *sk) {}
static inline void sk_common_release(struct sock *sk) {}