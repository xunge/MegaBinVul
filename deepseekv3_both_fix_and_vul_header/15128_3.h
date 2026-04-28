#include <stdint.h>
#include <stddef.h>

typedef uint16_t __u16;
typedef uint32_t __u32;
typedef uint64_t __u64;
typedef uint8_t __u8;

typedef __u16 __portpair;
typedef __u32 __addrpair;

struct inet_timewait_death_row {
    struct inet_hashinfo *hashinfo;
};

struct sock {
    int sk_bound_dev_if;
    unsigned int sk_hash;
    void *sk_prot;
};

struct inet_timewait_sock;
struct inet_hashinfo;

struct inet_sock {
    __u16 dport;
    __u16 sport;
    __u16 num;
};

struct in6_addr {
    __u8 s6_addr[16];
};

struct ipv6_pinfo {
    struct in6_addr rcv_saddr;
    struct in6_addr daddr;
};

struct net;

struct hlist_nulls_node {
    struct hlist_nulls_node *next;
    struct hlist_nulls_node **pprev;
};

struct inet_ehash_bucket {
    struct hlist_nulls_node twchain;
    struct hlist_nulls_node chain;
};

typedef struct {
    int lock;
} spinlock_t;

#define spin_lock(lock) ((void)0)
#define spin_unlock(lock) ((void)0)
#define WARN_ON(cond) ((void)0)

#define INET_COMBINED_PORTS(dport, lport) ((__portpair)(((__u32)(dport) << 16) | (__u32)(lport)))
#define htons(x) (x)
#define sk_unhashed(sk) (1)
#define __sk_nulls_add_node_rcu(sk, chain) ((void)0)
#define sock_prot_inuse_add(net, prot, cnt) ((void)0)
#define NET_INC_STATS_BH(net, stat) ((void)0)
#define LINUX_MIB_TIMEWAITRECYCLED 0
#define EADDRNOTAVAIL 1

static inline struct net *sock_net(struct sock *sk) { return NULL; }
static inline struct net *twsk_net(struct inet_timewait_sock *tw) { return NULL; }
static inline struct inet_sock *inet_sk(struct sock *sk) { return (struct inet_sock *)sk; }
static inline struct ipv6_pinfo *inet6_sk(struct sock *sk) { return NULL; }
static inline unsigned int inet6_ehashfn(struct net *net, const struct in6_addr *daddr, __u16 lport, const struct in6_addr *saddr, __u16 dport) { return 0; }
static inline struct inet_ehash_bucket *inet_ehash_bucket(struct inet_hashinfo *hinfo, unsigned int hash) { return NULL; }
static inline spinlock_t *inet_ehash_lockp(struct inet_hashinfo *hinfo, unsigned int hash) { return NULL; }
static inline struct inet_timewait_sock *inet_twsk(struct sock *sk) { return NULL; }
static inline int twsk_unique(struct sock *sk, struct sock *sk2, struct inet_timewait_sock **twp) { return 1; }
static inline void inet_twsk_deschedule(struct inet_timewait_sock *tw, struct inet_timewait_death_row *death_row) {}
static inline void inet_twsk_put(struct inet_timewait_sock *tw) {}

#define INET6_TW_MATCH(sk, net, hash, saddr, daddr, ports, dif) (0)
#define INET6_MATCH(sk, net, hash, saddr, daddr, ports, dif) (0)

#define sk_nulls_for_each(sk, node, list) \
    for ((sk) = NULL, (node) = NULL; (sk) != NULL; (sk) = NULL)