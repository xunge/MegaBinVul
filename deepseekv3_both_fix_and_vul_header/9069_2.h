#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>

#define SK_PROTOCOL_MAX 0
#define EINVAL 1
#define EAFNOSUPPORT 2
#define ESOCKTNOSUPPORT 3
#define ENOMEM 4
#define TTP_SAR_DISABLE 0
#define TTP_SAR_UNBOUND 0
#define ULTRA_MAX_DATA 0
#define LMP_PID_HEADER 0
#define IRDA_MAX_HEADER 0
#define FLOW_START 0
#define DISCOVERY_DEFAULT_SLOTS 0
#define DEV_ADDR_ANY 0
#define CONFIG_IRDA_ULTRA 0
#define IRDAPROTO_ULTRA 1
#define IRDAPROTO_UNITDATA 2
#define GFP_KERNEL 0

struct net {
    int dummy;
};
struct net init_net;

struct proto {
    int dummy;
};
struct proto irda_proto;

struct irda_sock {
    int query_wait;
    unsigned int max_sdu_size_rx;
    unsigned int max_data_size;
    unsigned int max_header_size;
    int ckey;
    struct {
        unsigned int word;
    } mask;
    int rx_flow;
    int tx_flow;
    int nslots;
    int daddr;
    int saddr;
};

struct sock {
    int sk_family;
    int sk_protocol;
};

struct socket {
    int type;
    void *ops;
};

struct proto_ops {
    int dummy;
};

struct proto_ops irda_stream_ops;
struct proto_ops irda_seqpacket_ops;
struct proto_ops irda_ultra_ops;
struct proto_ops irda_dgram_ops;

static inline struct irda_sock *irda_sk(struct sock *sk) { return (struct irda_sock *)sk; }
static inline void sk_free(struct sock *sk) { free(sk); }
static inline struct sock *sk_alloc(struct net *net, int family, int priority, struct proto *prot, int kern) { return malloc(sizeof(struct sock)); }
static inline void sock_init_data(struct socket *sock, struct sock *sk) {}
static inline int irlmp_register_client(int a, void *b, void *c, void *d) { return 0; }
static inline void init_waitqueue_head(int *q) {}
#define pr_debug(fmt, ...)