#include <sys/socket.h>
#include <stdbool.h>

#define PF_APPLETALK 5
#define GFP_KERNEL 0
#define CAP_NET_RAW 13
#define SOCK_ZAPPED 0x10000000

#define EAFNOSUPPORT 97
#define ESOCKTNOSUPPORT 94
#define EPERM 1
#define ENOMEM 12

struct net {
    int dummy;
};
struct proto {
    int dummy;
};
struct socket_ops {
    int dummy;
};
struct sock {
    int dummy;
};
struct socket {
    int type;
    struct socket_ops *ops;
};

static struct net init_net;
static struct proto ddp_proto;
static struct socket_ops atalk_dgram_ops;

static inline bool net_eq(const struct net *net1, const struct net *net2)
{
    return net1 == net2;
}

static inline bool capable(int cap)
{
    return true;
}

static inline struct sock *sk_alloc(struct net *net, int family, int priority, struct proto *prot, bool kern)
{
    return 0;
}

static inline void sock_init_data(struct socket *sock, struct sock *sk)
{
}

static inline void sock_set_flag(struct sock *sk, int flag)
{
}