#include <stddef.h>

#define PF_ISDN 0
#define GFP_KERNEL 0
#define SOCK_RAW 0
#define SS_UNCONNECTED 0
#define SOCK_ZAPPED 0
#define MISDN_OPEN 0
#define CAP_NET_RAW 0
#define ESOCKTNOSUPPORT 0
#define EPERM 0
#define ENOMEM 0

struct net;
struct socket {
    int type;
    struct proto_ops *ops;
    int state;
};
struct sock {
    int sk_protocol;
    int sk_state;
};
struct proto {
    int dummy;
};
struct proto_ops {
    int dummy;
};
struct list_head {
    struct list_head *next, *prev;
};

static struct proto mISDN_proto;
static struct proto_ops base_sock_ops;
static struct list_head base_sockets = {&base_sockets, &base_sockets};

static inline int capable(int cap) { return 1; }
static struct sock *sk_alloc(struct net *net, int family, int priority, struct proto *prot, int kern) {
    static struct sock sk;
    return &sk;
}
static void sock_init_data(struct socket *sock, struct sock *sk) {}
static void sock_reset_flag(struct sock *sk, int flag) {}
static void mISDN_sock_link(struct list_head *list, struct sock *sk) {}