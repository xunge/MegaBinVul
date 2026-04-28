#include <sys/types.h>
#include <stddef.h>
#include <stdint.h>

typedef uint32_t u32;

struct sock {
    int sk_state;
};

struct sk_buff {
    u32 len;
};

struct tcp_sock {
    u32 copied_seq;
    u32 urg_data;
    u32 urg_seq;
};

struct tcphdr {
    int fin;
};

typedef struct {
    int count;
} read_descriptor_t;

typedef int (*sk_read_actor_t)(read_descriptor_t *, struct sk_buff *, unsigned int, size_t);

#define TCP_LISTEN 10
#define ENOTCONN 107

static inline struct tcp_sock *tcp_sk(const struct sock *sk) { return (struct tcp_sock *)sk; }
static inline struct sk_buff *tcp_recv_skb(struct sock *sk, u32 seq, u32 *offset) { return NULL; }
static inline void sk_eat_skb(struct sock *sk, struct sk_buff *skb, int flags) {}
static inline void tcp_rcv_space_adjust(struct sock *sk) {}
static inline void tcp_cleanup_rbuf(struct sock *sk, int copied) {}
static inline struct tcphdr *tcp_hdr(const struct sk_buff *skb) { return NULL; }