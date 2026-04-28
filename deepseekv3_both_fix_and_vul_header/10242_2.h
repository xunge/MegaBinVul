#include <stddef.h>

struct sock {
    void *sk_nulls_node;
    void *sk_prot;
};

struct inet_sock {
    unsigned int inet_num;
    unsigned short inet_sport;
};

struct ping_table {
    int lock;
};

extern struct ping_table ping_table;

#define sk_hashed(sk) 0
#define write_lock_bh(lock) (void)0
#define write_unlock_bh(lock) (void)0
#define hlist_nulls_del(node) (void)0
#define sk_nulls_node_init(node) (void)0
#define sock_put(sk) (void)0
#define sock_prot_inuse_add(net, prot, val) (void)0
#define sock_net(sk) NULL
#define pr_debug(fmt, ...) (void)0

static inline struct inet_sock *inet_sk(const struct sock *sk) { 
    return (struct inet_sock *)sk; 
}