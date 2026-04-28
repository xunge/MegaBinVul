#include <stddef.h>

#define SK_PROTOCOL_MAX 256
#define PF_AX25 3
#define AX25_P_TEXT 0
#define AX25_P_SEGMENT 1
#define AX25_P_ARP 2
#define AX25_P_IP 3
#define AX25_P_NETROM 4
#define AX25_P_ROSE 5
#define SOCK_DGRAM 1
#define SOCK_SEQPACKET 2
#define SOCK_RAW 3
#define GFP_ATOMIC 0
#define EINVAL 22
#define EAFNOSUPPORT 97
#define ESOCKTNOSUPPORT 44
#define ENOMEM 12

struct net {
    int dummy;
};

struct socket {
    int type;
    struct proto_ops *ops;
};

struct sock {
    void (*sk_destruct)(struct sock *);
    int sk_protocol;
};

struct ax25_cb {
    struct sock *sk;
};

struct ax25_sock {
    struct ax25_cb *cb;
};

typedef struct ax25_cb ax25_cb;
typedef struct ax25_sock ax25_sock;

struct ax25_proto_struct {
    int dummy;
};

struct proto_ops {
    int dummy;
};

struct net init_net;
struct ax25_proto_struct ax25_proto;
struct proto_ops ax25_proto_ops;

static inline int net_eq(struct net *net1, struct net *net2) { return net1 == net2; }
static struct sock *sk_alloc(struct net *net, int family, int priority, struct ax25_proto_struct *prot, int kern) { return NULL; }
static void sk_free(struct sock *sk) {}
static void sock_init_data(struct socket *sock, struct sock *sk) {}
static void ax25_free_sock(struct sock *sk) {}
static struct ax25_cb *ax25_create_cb(void) { return NULL; }
static int ax25_protocol_is_registered(int protocol) { return 0; }
static inline struct ax25_sock *ax25_sk(struct sock *sk) { return (struct ax25_sock *)sk; }