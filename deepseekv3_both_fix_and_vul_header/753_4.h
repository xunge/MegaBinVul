#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

#define EAFNOSUPPORT 97
#define ESOCKTNOSUPPORT 94 
#define ENOMEM 12
#define EPERM 1
#define GFP_KERNEL 0
#define PF_IEEE802154 36
#define SOCK_ZAPPED 0x1000
#define CAP_NET_RAW 13

struct net {
    // dummy net structure
};
struct socket {
    int type;
    const struct proto_ops *ops;
};
struct sock {
    int sk_family;
    struct proto *sk_prot;
};
struct proto {
    int (*hash)(struct sock *sk);
    int (*init)(struct sock *sk);
};
struct proto_ops {
    // dummy proto_ops structure  
};

extern struct net init_net;
extern struct proto ieee802154_raw_prot;
extern struct proto ieee802154_dgram_prot;
extern const struct proto_ops ieee802154_raw_ops;
extern const struct proto_ops ieee802154_dgram_ops;

int net_eq(struct net *net1, struct net *net2);
int capable(int cap);
struct sock *sk_alloc(struct net *net, int family, int priority, struct proto *prot, int kern);
void sock_init_data(struct socket *sock, struct sock *sk);
void sock_set_flag(struct sock *sk, int flag);
void sk_common_release(struct sock *sk);