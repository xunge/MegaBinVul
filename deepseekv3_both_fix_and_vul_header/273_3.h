#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint32_t u32;
typedef uint8_t u8;

enum tcp_queue {
    TCP_FRAG_IN_RTX_QUEUE,
    TCP_FRAG_IN_WRITE_QUEUE
};

typedef unsigned int gfp_t;

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

struct tcp_skb_cb {
    u32 seq;
    u32 end_seq;
    u8 tcp_flags;
    u8 sacked;
    u32 tx;
};

struct sk_buff {
    unsigned int len;
    unsigned int truesize;
    u8 ip_summed;
    struct tcp_skb_cb cb;
    struct sk_buff *next;
    struct sk_buff *prev;
    struct sock *sk;
    unsigned char *head;
    unsigned char *data;
    unsigned char *tail;
    unsigned char *end;
    uint64_t tstamp;
    struct list_head tcp_tsorted_anchor;
};

struct sock {
    unsigned int sk_wmem_queued;
    unsigned int sk_sndbuf;
    struct net *sk_net;
};

struct tcp_sock {
    u32 snd_nxt;
};

struct net {
    // Placeholder for net stats
};

#define WARN_ON(condition) ((condition) ? 1 : 0)
#define unlikely(x) (x)
#define NET_INC_STATS(net, stat) do { } while (0)
#define LINUX_MIB_TCPWQUEUETOOBIG 0
#define TCPHDR_FIN 0x01
#define TCPHDR_PSH 0x08
#define CHECKSUM_PARTIAL 1
#define EINVAL 22
#define ENOMEM 12

#define TCP_SKB_CB(__skb) (&((__skb)->cb))

static inline unsigned int skb_headlen(const struct sk_buff *skb) {
    return skb->len - (skb->data - skb->head);
}

static inline struct tcp_sock *tcp_sk(const struct sock *sk) {
    return (struct tcp_sock *)sk;
}

static inline struct net *sock_net(const struct sock *sk) {
    return sk->sk_net;
}

static inline int skb_unclone(struct sk_buff *skb, gfp_t gfp) {
    return 0;
}

static inline struct sk_buff *sk_stream_alloc_skb(struct sock *sk, int size, gfp_t gfp, bool force) {
    return NULL;
}

static inline void sk_mem_charge(struct sock *sk, int size) {
}

static inline void tcp_skb_fragment_eor(struct sk_buff *skb1, struct sk_buff *skb2) {
}

static inline void skb_split(struct sk_buff *skb, struct sk_buff *skb2, int len) {
}

static inline void tcp_fragment_tstamp(struct sk_buff *skb, struct sk_buff *skb2) {
}

static inline int tcp_skb_pcount(const struct sk_buff *skb) {
    return 0;
}

static inline void tcp_set_skb_tso_segs(struct sk_buff *skb, unsigned int mss_now) {
}

static inline void tcp_adjust_pcount(struct sock *sk, struct sk_buff *skb, int diff) {
}

static inline void __skb_header_release(struct sk_buff *skb) {
}

static inline void tcp_insert_write_queue_after(struct sk_buff *skb1, struct sk_buff *skb2, struct sock *sk, enum tcp_queue queue) {
}

static inline void list_add(struct list_head *new, struct list_head *head) {
    new->next = head->next;
    new->prev = head;
    head->next->prev = new;
    head->next = new;
}

#define before(a, b) ((a) < (b))