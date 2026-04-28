#include <stdint.h>
#include <stdatomic.h>
#include <stddef.h>

struct sk_buff;
struct sk_buff_head {
    struct sk_buff *next;
    struct sk_buff *prev;
};

struct sock {
    _Atomic int sk_rmem_alloc;
    int sk_rcvbuf;
    struct sk_buff_head sk_receive_queue;
};

struct tcp_sock {
    uint32_t copied_seq;
    uint32_t rcv_ssthresh;
    uint32_t advmss;
    uint32_t rcv_nxt;
    int pred_flags;
};

#define SOCK_DEBUG(sk, fmt, ...)
#define NET_INC_STATS(net, stat)
#define LINUX_MIB_PRUNECALLED 0
#define LINUX_MIB_RCVPRUNED 0

static inline struct tcp_sock *tcp_sk(const struct sock *sk) { return (struct tcp_sock *)sk; }
static inline void *sock_net(const struct sock *sk) { return NULL; }
static inline int tcp_under_memory_pressure(const struct sock *sk) { return 0; }
static inline void tcp_clamp_window(struct sock *sk) {}
static inline void tcp_collapse_ofo_queue(struct sock *sk) {}
static inline int skb_queue_empty(const struct sk_buff_head *list) { return list->next == (struct sk_buff *)list; }
static inline void *skb_peek(const struct sk_buff_head *list) { return list->next; }
static inline void tcp_collapse(struct sock *sk, struct sk_buff_head *list, void *a, void *b, void *c, uint32_t d, uint32_t e) {}
static inline void sk_mem_reclaim(struct sock *sk) {}
static inline void tcp_prune_ofo_queue(struct sock *sk) {}
static inline int atomic_read(const _Atomic int *v) { return *v; }
#define min(a, b) ((a) < (b) ? (a) : (b))