#include <stdbool.h>
#include <stdint.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

typedef uint32_t __be32;

struct sockaddr_l2tpip6 {
    sa_family_t l2tp_family;
    struct in6_addr l2tp_addr;
    uint32_t l2tp_conn_id;
    uint32_t l2tp_scope_id;
};

struct inet_sock {
    __be32 inet_rcv_saddr;
    __be32 inet_saddr;
};

struct ipv6_pinfo {
    struct in6_addr saddr;
};

struct sock {
    int sk_bound_dev_if;
    int sk_state;
    struct in6_addr sk_v6_rcv_saddr;
};

struct net;
struct net_device;
struct hlist_head {
    struct hlist_node *first;
};
struct hlist_node {
    struct hlist_node *next, **pprev;
};

#define IPV6_ADDR_MAPPED 0
#define IPV6_ADDR_MULTICAST 0
#define IPV6_ADDR_ANY 0
#define IPV6_ADDR_LINKLOCAL 0
#define TCP_CLOSE 0
#define SOCK_ZAPPED 0
#define LOOPBACK4_IPV6 0x0100007F
#define EINVAL 22
#define EADDRNOTAVAIL 99
#define EADDRINUSE 98
#define ENODEV 19

pthread_rwlock_t l2tp_ip6_lock;
struct hlist_head l2tp_ip6_bind_table = { NULL };

static inline struct inet_sock *inet_sk(const struct sock *sk) { return (struct inet_sock *)sk; }
static inline struct ipv6_pinfo *inet6_sk(const struct sock *sk) { return NULL; }
static inline struct net *sock_net(const struct sock *sk) { return NULL; }
static inline int sock_flag(const struct sock *sk, int flag) { return 0; }
static inline int ipv6_addr_type(const struct in6_addr *addr) { return 0; }
static inline bool ipv6_chk_addr(struct net *net, const struct in6_addr *addr, const struct net_device *dev, int strict) { return false; }
static inline void read_lock_bh(pthread_rwlock_t *lock) {}
static inline void read_unlock_bh(pthread_rwlock_t *lock) {}
static inline void write_lock_bh(pthread_rwlock_t *lock) {}
static inline void write_unlock_bh(pthread_rwlock_t *lock) {}
static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}
static inline void sock_reset_flag(struct sock *sk, int flag) {}
static inline void sk_add_bind_node(struct sock *sk, struct hlist_head *head) {}
static inline void sk_del_node_init(struct sock *sk) {}
static inline struct net_device *dev_get_by_index_rcu(struct net *net, int ifindex) { return NULL; }
static inline void rcu_read_lock() {}
static inline void rcu_read_unlock() {}

struct l2tp_ip6_sock {
    struct inet_sock inet;
    uint32_t conn_id;
};

static inline struct l2tp_ip6_sock *l2tp_ip6_sk(const struct sock *sk) {
    return (struct l2tp_ip6_sock *)sk;
}

static bool __l2tp_ip6_bind_lookup(struct net *net, const struct in6_addr *laddr,
                                  int dif, uint32_t conn_id) {
    return false;
}