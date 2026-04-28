#include <linux/socket.h>
#include <linux/tcp.h>
#include <linux/net.h>
#include <linux/sockios.h>
#include <linux/ax25.h>

#define SS_UNCONNECTED 1
#define TCP_LISTEN 10
#define EINVAL 22
#define EOPNOTSUPP 95
#define AX25_ADDR_LEN 7

struct socket {
    int state;
    struct sock *sk;
};

struct sock {
    unsigned short sk_state;
    int sk_max_ack_backlog;
};

struct nr_sock {
    char user_addr[AX25_ADDR_LEN];
};

static inline struct nr_sock *nr_sk(struct sock *sk)
{
    return (struct nr_sock *)sk;
}

static void lock_sock(struct sock *sk) {}
static void release_sock(struct sock *sk) {}