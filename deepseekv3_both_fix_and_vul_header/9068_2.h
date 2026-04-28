#include <sys/socket.h>
#include <errno.h>
#include <stddef.h>

#define SK_PROTOCOL_MAX 255
#define DNPROTO_NSP 1
#define GFP_KERNEL 0

struct net {
    // dummy definition
};
struct sock {
    int sk_protocol;
    // dummy definition
};
struct socket {
    int type;
    // dummy definition
};

extern struct net init_net;
extern int net_eq(struct net *net1, struct net *net2);
extern struct sock *dn_alloc_sock(struct net *net, struct socket *sock, int flags, int kern);