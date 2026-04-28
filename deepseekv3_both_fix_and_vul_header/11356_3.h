#include <stdbool.h>
#include <stddef.h>

#define unlikely(x) (x)

typedef unsigned int u32;

struct sock;
struct rb_node {
    struct rb_node *rb_left;
    struct rb_node *rb_right;
};

struct rb_root {
    struct rb_node *rb_node;
};

struct sk_buff {
    unsigned int truesize;
    struct rb_node rbnode;
    char cb[48];
};

struct tcp_sock {
    unsigned int pred_flags;
    struct rb_root out_of_order_queue;
    struct sk_buff *ooo_last_skb;
    u32 rcv_nxt;
    struct {
        int num_sacks;
    } rx_opt;
    struct {
        u32 start_seq;
        u32 end_seq;
    } selective_acks[1];
};

struct tcp_skb_cb {
    u32 seq;
    u32 end_seq;
};

#define TCP_SKB_CB(__skb) ((struct tcp_skb_cb *)&((__skb)->cb[0]))

#define RB_EMPTY_ROOT(root) ((root)->rb_node == NULL)
#define rb_to_skb(node) ((struct sk_buff *)((char *)(node) - offsetof(struct sk_buff, rbnode)))
#define skb_rb_next(skb) ((struct sk_buff *)rb_next(&(skb)->rbnode))

#define before(seq1, seq2) ((int)((seq1)-(seq2)) < 0)
#define after(seq1, seq2) ((int)((seq1)-(seq2)) > 0)

#define NET_INC_STATS(net, field) do { } while (0)
#define SOCK_DEBUG(sk, fmt, ...) do { } while (0)

#define LINUX_MIB_TCPOFODROP 0
#define LINUX_MIB_TCPOFOQUEUE 0
#define LINUX_MIB_TCPOFOMERGE 0

static inline struct tcp_sock *tcp_sk(const struct sock *sk) { return (struct tcp_sock *)sk; }
static inline void *sock_net(const struct sock *sk) { return NULL; }
static inline void tcp_ecn_check_ce(struct sock *sk, struct sk_buff *skb) {}
static inline bool tcp_try_rmem_schedule(struct sock *sk, struct sk_buff *skb, int size) { return false; }
static inline void tcp_drop(struct sock *sk, struct sk_buff *skb) {}
static inline void inet_csk_schedule_ack(struct sock *sk) {}
static inline bool tcp_is_sack(const struct tcp_sock *tp) { return false; }
static inline bool tcp_ooo_try_coalesce(struct sock *sk, struct sk_buff *skb1, struct sk_buff *skb2, bool *fragstolen) { return false; }
static inline bool tcp_try_coalesce(struct sock *sk, struct sk_buff *skb1, struct sk_buff *skb2, bool *fragstolen) { return false; }
static inline void tcp_grow_window(struct sock *sk, struct sk_buff *skb) {}
static inline void kfree_skb_partial(struct sk_buff *skb, bool fragstolen) {}
static inline void tcp_dsack_set(struct sock *sk, u32 start_seq, u32 end_seq) {}
static inline void tcp_dsack_extend(struct sock *sk, u32 start_seq, u32 end_seq) {}
static inline void tcp_sack_new_ofo_skb(struct sock *sk, u32 seq, u32 end_seq) {}
static inline void skb_condense(struct sk_buff *skb) {}
static inline void skb_set_owner_r(struct sk_buff *skb, struct sock *sk) {}
static inline void __kfree_skb(struct sk_buff *skb) {}

static inline void rb_link_node(struct rb_node *node, struct rb_node *parent, struct rb_node **rb_link) {}
static inline void rb_insert_color(struct rb_node *node, struct rb_root *root) {}
static inline void rb_replace_node(struct rb_node *victim, struct rb_node *new, struct rb_root *root) {}
static inline void rb_erase(struct rb_node *node, struct rb_root *root) {}
static inline struct rb_node *rb_next(const struct rb_node *node) { return NULL; }