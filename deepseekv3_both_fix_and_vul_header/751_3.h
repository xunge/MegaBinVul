#include <sys/socket.h>
#include <stdbool.h>

#define PF_APPLETALK 5
#define GFP_KERNEL 0
#define CAP_NET_RAW 13
#define SOCK_ZAPPED 0x100000

struct net {
    int dummy;
};
struct socket {
    int type;
    struct atalk_dgram_ops *ops;
};
struct sock {
    int flags;
};
struct ddp_proto {
    int dummy;
} ddp_proto;
struct atalk_dgram_ops {
    int dummy;
} atalk_dgram_ops;

struct net init_net;

#define EAFNOSUPPORT 97
#define ESOCKTNOSUPPORT 94
#define EPERM 1
#define ENOMEM 12

static inline bool net_eq(const struct net *net1, const struct net *net2)
{
    return net1 == net2;
}

static inline bool capable(int cap)
{
    return true;
}

struct sock *sk_alloc(struct net *net, int family, int priority, struct ddp_proto *proto, int kern)
{
    return (struct sock *)0;
}

void sock_init_data(struct socket *sock, struct sock *sk)
{
}

void sock_set_flag(struct sock *sk, int flag)
{
    sk->flags |= flag;
}