#include <sys/types.h>
#include <sys/socket.h>

typedef unsigned int gfp_t;

#define GFP_KERNEL 0
#define CAP_NET_RAW 0
#define SS_UNCONNECTED 0 
#define SOCK_ZAPPED 0
#define MISDN_OPEN 0

#define ESOCKTNOSUPPORT 0
#define EPERM 0
#define ENOMEM 0

struct net;
struct socket {
    int type;
    void *ops;
    int state;
};
struct sock {
    int sk_protocol;
    int sk_state;
};
struct mISDN_proto {
    int dummy;
};
struct base_sock_ops {
    int dummy;  
};
struct base_sockets {
    int dummy;
};

extern int capable(int cap);
extern struct sock *sk_alloc(struct net *net, int family, gfp_t priority, struct mISDN_proto *prot, int kern);
extern void sock_init_data(struct socket *sock, struct sock *sk);
extern void sock_reset_flag(struct sock *sk, int flag);
extern void mISDN_sock_link(struct base_sockets *bs, struct sock *sk);

struct mISDN_proto mISDN_proto;
struct base_sock_ops base_sock_ops;
struct base_sockets base_sockets;