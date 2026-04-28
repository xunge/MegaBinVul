#include <sys/types.h>
#include <sys/socket.h>
#include <stddef.h>

struct socket {
    int type;
    void *ops;
    int state;
};

struct sock {
    int sk_protocol;
    int sk_state;
};

struct net;
struct mISDN_proto {
    int dummy;
};
struct base_sock_ops {
    int dummy;
};
struct base_sockets {
    int dummy;
};

extern struct mISDN_proto mISDN_proto;
extern struct base_sock_ops base_sock_ops;
extern struct base_sockets base_sockets;

#define GFP_KERNEL 0
#define SS_UNCONNECTED 0
#define SOCK_ZAPPED 0
#define MISDN_OPEN 0
#define CAP_NET_RAW 0

enum {
    ESOCKTNOSUPPORT = -1,
    EPERM = -2,
    ENOMEM = -3
};

static inline int capable(int cap) { return 1; }
static inline struct sock *sk_alloc(struct net *net, int family, int priority, struct mISDN_proto *prot, int kern) { return NULL; }
static inline void sock_init_data(struct socket *sock, struct sock *sk) {}
static inline void sock_reset_flag(struct sock *sk, int flag) {}
static inline void mISDN_sock_link(struct base_sockets *list, struct sock *sk) {}