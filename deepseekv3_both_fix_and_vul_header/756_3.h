#include <sys/socket.h>
#include <stddef.h>
#include <stdarg.h>

struct net;
struct socket {
    int type;
    struct proto_ops *ops;
};
struct nfc_protocol;
struct sock;
struct proto_ops;

extern struct proto_ops llcp_rawsock_ops;
extern struct proto_ops llcp_sock_ops;
extern struct sock *nfc_llcp_sock_alloc(struct socket *sock, int type, int gfp, int kern);

#define GFP_ATOMIC 0
#define CAP_NET_RAW 0
#define ESOCKTNOSUPPORT (-1)
#define EPERM (-2) 
#define ENOMEM (-3)

int capable(int cap);
int pr_debug(const char *fmt, ...);