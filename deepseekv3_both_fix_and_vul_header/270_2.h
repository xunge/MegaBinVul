#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>

struct sock;
struct sk_buff {
    unsigned int len;
    unsigned char *data;
    unsigned char cb[48];
    struct sk_buff *next;
};

struct tcp_sock {
    struct sk_buff *retransmit_skb_hint;
};

struct tcp_skb_cb {
    unsigned int end_seq;
    unsigned char tcp_flags;
    unsigned char sacked;
    bool eor;
};

#define TCP_SKB_CB(__skb) ((struct tcp_skb_cb *)&((__skb)->cb[0]))
#define TCPCB_EVER_RETRANS 0x80
#define BUG_ON(condition) do { if (condition) abort(); } while (0)

static inline struct sk_buff *skb_rb_next(struct sk_buff *skb) { return skb->next; }
static inline int tcp_skb_pcount(const struct sk_buff *skb) { return 1; }
static inline int skb_availroom(const struct sk_buff *skb) { return 0; }
static inline void *skb_put(struct sk_buff *skb, unsigned int len) { return NULL; }
static inline void skb_copy_bits(const struct sk_buff *skb, int offset, void *to, int len) {}
static inline bool skb_shift(struct sk_buff *skb, struct sk_buff *newskb, int shiftlen) { return false; }
static inline void tcp_highest_sack_replace(struct sock *sk, struct sk_buff *old, struct sk_buff *newskb) {}
static inline void tcp_clear_retrans_hints_partial(struct tcp_sock *tp) {}
static inline void tcp_adjust_pcount(struct sock *sk, struct sk_buff *skb, int decr) {}
static inline void tcp_skb_collapse_tstamp(struct sk_buff *skb, const struct sk_buff *next_skb) {}
static inline void tcp_rtx_queue_unlink_and_free(struct sk_buff *skb, struct sock *sk) {}
static inline struct tcp_sock *tcp_sk(const struct sock *sk) { return (struct tcp_sock *)sk; }