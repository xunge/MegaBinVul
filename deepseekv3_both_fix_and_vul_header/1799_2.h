#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>

struct socket {
    struct sock *sk;
};

struct sock {
    struct proto *sk_prot;
    int sk_family;
};

struct proto {
    int (*connect)(struct sock *, struct sockaddr *, int);
    int (*disconnect)(struct sock *, int);
    int (*pre_connect)(struct sock *, struct sockaddr *, int);
};

struct inet_sock {
    int inet_num;
};

#define BPF_CGROUP_PRE_CONNECT_ENABLED(sk) (0)
#define data_race(x) (x)

static inline struct inet_sock *inet_sk(const struct sock *sk) {
    return (struct inet_sock *)sk;
}

static inline int inet_autobind(struct sock *sk) {
    return 0;
}