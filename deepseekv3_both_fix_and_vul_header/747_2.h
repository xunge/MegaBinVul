#include <sys/socket.h>
#include <errno.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ax25_cb {
    struct sock *sk;
} ax25_cb;

struct net;
struct socket {
    int type;
    const struct proto_ops *ops;
};
struct sock {
    ax25_cb *sk_protinfo;
    void (*sk_destruct)(struct sock *);
    int sk_protocol;
};
struct proto;
struct proto_ops;

extern struct net init_net;
extern struct proto ax25_proto;
extern const struct proto_ops ax25_proto_ops;

typedef unsigned int gfp_t;

#define SK_PROTOCOL_MAX 256
#define PF_AX25 3
#define AX25_P_TEXT 0
#define AX25_P_SEGMENT 1
#define AX25_P_ARP 2
#define AX25_P_IP 3
#define AX25_P_NETROM 4
#define AX25_P_ROSE 5

#define GFP_ATOMIC 0
#define EINVAL 22
#define EAFNOSUPPORT 97
#define ENOMEM 12
#define EPERM 1
#define CAP_NET_RAW 13

static inline bool net_eq(const struct net *net1, const struct net *net2) { return false; }
static inline struct sock *sk_alloc(struct net *net, int family, gfp_t priority, struct proto *prot) { return NULL; }
static inline void sk_free(struct sock *sk) {}
static inline void sock_init_data(struct socket *sock, struct sock *sk) {}
static inline void ax25_free_sock(struct sock *sk) {}
static inline ax25_cb *ax25_create_cb(void) { return malloc(sizeof(ax25_cb)); }
static inline bool ax25_protocol_is_registered(int protocol) { return false; }
static inline bool capable(int cap) { return true; }