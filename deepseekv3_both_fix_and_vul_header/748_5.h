#include <stddef.h>
#include <errno.h>
#include <sys/socket.h>
#include <linux/capability.h>

#define SK_PROTOCOL_MAX 256
#define PF_AX25 3
#define AX25_P_TEXT 0
#define AX25_P_SEGMENT 1
#define AX25_P_ARP 2
#define AX25_P_IP 3
#define AX25_P_NETROM 4
#define AX25_P_ROSE 5
#define GFP_ATOMIC 0x20

struct net {
    int dummy;
};
extern struct net init_net;

struct socket {
    int type;
    const struct proto_ops *ops;
};

struct sock {
    int sk_protocol;
    void (*sk_destruct)(struct sock *);
};

struct ax25_cb {
    struct sock *sk;
};

struct ax25_sock {
    struct ax25_cb *cb;
};

struct proto_ops {
    int dummy;
};

struct ax25_proto {
    int dummy;
};

extern struct ax25_proto ax25_proto;
extern const struct proto_ops ax25_proto_ops;

extern int net_eq(struct net *, struct net *);
extern int ax25_protocol_is_registered(int);
extern struct sock *sk_alloc(struct net *, int, int, struct ax25_proto *, int);
extern void sk_free(struct sock *);
extern void sock_init_data(struct socket *, struct sock *);
extern struct ax25_sock *ax25_sk(struct sock *);
extern struct ax25_cb *ax25_create_cb(void);
extern void ax25_free_sock(struct sock *);

typedef struct ax25_cb ax25_cb;