#include <linux/types.h>
#include <linux/module.h>

struct sock {
    int sk_state;
    struct socket *sk_socket;
};

struct socket {
    unsigned long flags;
};

struct tcp_ulp_ops {
    int (*init)(struct sock *sk);
    int (*clone)(struct sock *newsk, const struct sock *oldsk);
    struct module *owner;
};

struct inet_connection_sock {
    struct tcp_ulp_ops *icsk_ulp_ops;
};

#define TCP_LISTEN 10
#define SOCK_SUPPORT_ZC 0
#define EEXIST 17
#define EINVAL 22

static inline struct inet_connection_sock *inet_csk(const struct sock *sk) {
    return (struct inet_connection_sock *)sk;
}

static inline void clear_bit(int nr, volatile unsigned long *addr) {
    *addr &= ~(1UL << nr);
}

static inline void module_put(struct module *module) {
    // Dummy implementation
}