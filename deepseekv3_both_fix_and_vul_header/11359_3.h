#include <stdbool.h>
#include <stdatomic.h>
#include <stddef.h>

struct rb_node {
    unsigned long  __rb_parent_color;
    struct rb_node *rb_right;
    struct rb_node *rb_left;
};

struct rb_root {
    struct rb_node *rb_node;
};

struct sock {
    int sk_rcvbuf;
    atomic_int sk_rmem_alloc;
};

struct tcp_options_received {
    bool sack_ok;
};

struct sk_buff {
    struct rb_node rbnode;
    int truesize;
};

struct tcp_sock {
    struct rb_root out_of_order_queue;
    struct sk_buff *ooo_last_skb;
    struct tcp_options_received rx_opt;
};

#define RB_EMPTY_ROOT(root) ((root)->rb_node == NULL)
#define LINUX_MIB_OFOPRUNED 0

static inline int atomic_read(const atomic_int *v) { return *v; }
static inline struct tcp_sock *tcp_sk(const struct sock *sk) { return (struct tcp_sock *)sk; }
static inline void NET_INC_STATS(void *net, int stat) {}
static inline void *sock_net(struct sock *sk) { return NULL; }
static inline struct rb_node *rb_prev(struct rb_node *node) { return NULL; }
static inline void rb_erase(struct rb_node *node, struct rb_root *root) {}
static inline struct sk_buff *rb_to_skb(struct rb_node *node) { return NULL; }
static inline void tcp_drop(struct sock *sk, struct sk_buff *skb) {}
static inline void sk_mem_reclaim(struct sock *sk) {}
static inline bool tcp_under_memory_pressure(struct sock *sk) { return false; }
static inline void tcp_sack_reset(struct tcp_options_received *rx_opt) {}