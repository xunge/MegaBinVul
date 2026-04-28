#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;
typedef uint8_t u8;

struct sock {
    u32 sk_rcvbuf;
};

struct sk_buff {
    u32 truesize;
    u8 cb[48];
    struct sk_buff *rb_node;
};

struct rb_root {
    struct sk_buff *rb_node;
};

struct tcp_sock {
    struct rb_root out_of_order_queue;
    struct sk_buff *ooo_last_skb;
};

struct tcp_skb_cb {
    u32 seq;
    u32 end_seq;
};

#define TCP_SKB_CB(__skb) ((struct tcp_skb_cb *)&((__skb)->cb[0]))

static inline struct sk_buff *skb_rb_first(struct rb_root *root) { return root ? root->rb_node : NULL; }
static inline struct sk_buff *skb_rb_last(struct rb_root *root) { return NULL; }
static inline struct sk_buff *skb_rb_next(struct sk_buff *skb) { return skb ? skb->rb_node : NULL; }

static inline int after(u32 a, u32 b) { return (int32_t)(b) - (int32_t)(a) < 0; }
static inline int before(u32 a, u32 b) { return (int32_t)(a) - (int32_t)(b) < 0; }
static inline int unlikely(int x) { return x; }

#define SKB_WITH_OVERHEAD(x) (x)
#define SK_MEM_QUANTUM 4096

static inline struct tcp_sock *tcp_sk(const struct sock *sk) { return (struct tcp_sock *)sk; }

static void tcp_collapse(struct sock *sk, void *a, struct rb_root *b, struct sk_buff *c, struct sk_buff *d, u32 e, u32 f) {}