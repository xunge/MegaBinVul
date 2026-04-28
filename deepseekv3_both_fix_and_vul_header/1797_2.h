#include <stddef.h>

typedef struct { 
    void *kernel; 
} sockptr_t;

struct sock {
    struct proto *sk_prot;
};

struct socket {
    struct sock *sk;
};

struct proto {
    int (*setsockopt)(struct sock *sk, int level, int optname,
                     sockptr_t optval, unsigned int optlen);
};

#define READ_ONCE(x) (x)