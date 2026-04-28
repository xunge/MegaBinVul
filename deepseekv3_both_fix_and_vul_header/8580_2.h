#include <cstddef>

struct sock {
    void *sk_send_head;
};

struct tcp_sock {
    void *highest_sack;
};

struct sk_buff;

static inline struct tcp_sock *tcp_sk(const struct sock *sk) {
    return (struct tcp_sock *)sk;
}