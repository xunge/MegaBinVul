#include <stdbool.h>

struct sock;

typedef struct sockptr_t {
    union {
        void *user;
        void *kernel;
    };
    bool is_user;
} sockptr_t;

struct inet_connection_sock_af_ops {
    int (*setsockopt)(struct sock *sk, int level, int optname,
                     sockptr_t optval, unsigned int optlen);
};

struct inet_connection_sock {
    struct inet_connection_sock_af_ops *icsk_af_ops;
};

#define SOL_TCP 6
#define READ_ONCE(x) (x)

struct inet_connection_sock *inet_csk(struct sock *sk);
int do_tcp_setsockopt(struct sock *sk, int level, int optname, sockptr_t optval, unsigned int optlen);