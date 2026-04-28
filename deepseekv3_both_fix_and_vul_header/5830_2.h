#include <stdint.h>

struct hlist_nulls_node {
    struct hlist_nulls_node *next;
    struct hlist_nulls_node **pprev;
};

struct sock {
    struct hlist_nulls_node sk_nulls_node;
    void *sk_prot;
    void *sk_net;
};

struct inet_sock {
    uint16_t inet_num;
    uint16_t inet_sport;
};

struct net;

struct ping_table {
    int lock;
};

extern struct ping_table ping_table;

#define inet_sk(sk) ((struct inet_sock *)(sk))
#define sk_hashed(sk) ((sk)->sk_nulls_node.pprev)
#define sock_put(sk) 
#define sock_prot_inuse_add(net, prot, cnt) 
#define sock_net(sk) ((struct net *)((sk)->sk_net))
#define pr_debug(fmt, ...) 
#define write_lock_bh(lock) 
#define write_unlock_bh(lock) 
#define hlist_nulls_del(node) \
    do { \
        if ((node)->pprev) { \
            *(node)->pprev = (node)->next; \
            if ((node)->next) \
                (node)->next->pprev = (node)->pprev; \
        } \
    } while (0)