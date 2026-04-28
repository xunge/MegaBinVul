#include <stdint.h>

#define UDP_HTABLE_SIZE 128

struct sock {
    unsigned short sk_family;
};

struct net;

struct seq_file {
    void *private;
};

struct udp_table {
    struct {
        uint32_t lock;
    } hash[UDP_HTABLE_SIZE];
};

struct udp_iter_state {
    unsigned int bucket;
    unsigned short family;
    struct udp_table *udp_table;
};

static inline struct net *sock_net(struct sock *sk) { return (struct net *)0; }
static inline int net_eq(struct net *net1, struct net *net2) { return 1; }
static inline struct sock *sk_nulls_next(struct sock *sk) { return sk; }
static inline struct net *seq_file_net(struct seq_file *seq) { return (struct net *)0; }
static inline void spin_unlock_bh(uint32_t *lock) { *lock = 0; }

struct sock *udp_get_first(struct seq_file *seq, int bucket);