#include <stddef.h>
#include <errno.h>
#include <sys/socket.h>
#include <net/if.h>

#define CAN_ERR_FLAG 0x20000000U
#define CAN_RTR_FLAG 0x40000000U
#define CAN_ISOTP_SF_BROADCAST 0x01
#define ARPHRD_CAN 280
#define ENETDOWN 100
#define EADDRNOTAVAIL 99
#define ENODEV 19
#define EINVAL 22
#define SOCK_DEAD 0x01

#define ISOTP_MIN_NAMELEN (sizeof(struct sockaddr_can))
#define SINGLE_MASK(id) (~0U)

struct socket {
    struct sock *sk;
};

struct sock {
    int sk_err;
    unsigned int sk_flags;
    void (*sk_error_report)(struct sock *);
};

struct net_device {
    unsigned int type;
    unsigned int mtu;
    unsigned int flags;
    int ifindex;
};

struct net;

struct isotp_sock {
    struct {
        unsigned int flags;
    } opt;
    unsigned int ifindex;
    unsigned int rxid;
    unsigned int txid;
    int bound;
    struct {
        int mtu;
    } ll;
};

struct sockaddr_can {
    int can_ifindex;
    struct {
        struct {
            unsigned int rx_id;
            unsigned int tx_id;
        } tp;
    } can_addr;
};

struct sk_buff;

static inline struct isotp_sock *isotp_sk(const struct sock *sk)
{
    return (struct isotp_sock *)sk;
}

static inline struct net *sock_net(const struct sock *sk)
{
    return NULL;
}

static void isotp_rcv(struct sk_buff *skb, void *data) {}

static void can_rx_register(struct net *net, struct net_device *dev,
                          unsigned int rx_id, unsigned int mask,
                          void (*func)(struct sk_buff *, void *),
                          void *data, const char *ident, void *sk) {}

static void can_rx_unregister(struct net *net, struct net_device *dev,
                            unsigned int rx_id, unsigned int mask,
                            void (*func)(struct sk_buff *, void *),
                            void *data) {}

static void lock_sock(struct sock *sk) {}
static void release_sock(struct sock *sk) {}
static struct net_device *dev_get_by_index(struct net *net, int ifindex) { return NULL; }
static void dev_put(struct net_device *dev) {}
static int sock_flag(const struct sock *sk, int flag) { return 0; }