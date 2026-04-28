#include <sys/socket.h>

struct socket {
    struct sock *sk;
};

struct sock {
    struct proto *sk_prot;
    int (*getsockopt)(struct sock *sk, int level, int optname, char *optval, int *optlen);
};

struct proto {
    int (*getsockopt)(struct sock *sk, int level, int optname, char *optval, int *optlen);
};

#define __user
#define READ_ONCE(x) (x)