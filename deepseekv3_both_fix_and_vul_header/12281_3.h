#include <stdint.h>
#include <stddef.h>
#include <netinet/in.h>

typedef uint32_t __be32;

struct sock {
    int sk_protocol;
    int sk_bound_dev_if;
};

struct inet_sock {
    __be32 inet_daddr;
    __be32 inet_saddr;
    __be32 inet_dport;
    __be32 inet_sport;
    void *inet_opt;
};

struct ip_options_rcu {
    struct {
        __be32 faddr;
        int srr;
    } opt;
};

struct dst_ops {
    int (*check)(struct dst_entry *, int);
};

struct dst_entry {
    int obsolete;
    struct dst_ops *ops;
};

struct flowi4 {
    // flowi4 members would go here
};

struct rtable {
    struct dst_entry dst;
};

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define RT_CONN_FLAGS(sk) 0

static inline struct inet_sock *inet_sk(const struct sock *sk) {
    return (struct inet_sock *)sk;
}

static inline void *rcu_dereference(void *p) {
    return p;
}

static inline void rcu_read_lock(void) {}
static inline void rcu_read_unlock(void) {}

static inline struct dst_entry *__sk_dst_get(struct sock *sk) {
    return NULL;
}

static inline int __sk_dst_check(struct sock *sk, int flag) {
    return 0;
}

static inline void *sock_net(struct sock *sk) {
    return NULL;
}

static inline struct rtable *ip_route_output_ports(void *net, struct flowi4 *fl4,
                                                  struct sock *sk, __be32 daddr,
                                                  __be32 saddr, __be32 dport,
                                                  __be32 sport, int protocol,
                                                  int flags, int oif) {
    return NULL;
}

static inline void sk_dst_set(struct sock *sk, struct dst_entry *dst) {}
static inline void __sk_dst_set(struct sock *sk, struct dst_entry *dst) {}