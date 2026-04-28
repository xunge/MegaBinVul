#include <stdbool.h>
#include <sys/socket.h>
#include <linux/capability.h>

struct net;
struct socket {
    int type;
    void *ops;
    int state;
};
struct nfc_protocol {
    void *proto;
    int id;
};
struct sock {
    int sk_protocol;
    void *sk_destruct;
    void *sk_user_data;
};
struct rawsock_ops {
    int dummy;
};
struct rawsock_raw_ops {
    int dummy;
};
struct list_head {
    void *next;
    void *prev;
};

#define PF_NFC 39
#define GFP_ATOMIC 0
#define ESOCKTNOSUPPORT 44
#define ENOMEM 12
#define EPERM 1
#define SS_UNCONNECTED 1
#define SOCK_SEQPACKET 5
#define SOCK_RAW 3
#define CAP_NET_RAW 13

struct rawsock_data {
    void *tx_work;
    bool tx_work_scheduled;
};

static struct rawsock_ops rawsock_ops;
static struct rawsock_raw_ops rawsock_raw_ops;
static struct list_head raw_sk_list;

#define nfc_rawsock(sk) ((struct rawsock_data *)sk->sk_user_data)
#define INIT_WORK(work, func) ((void)0)
#define pr_debug(fmt, ...) ((void)0)

static void rawsock_destruct(struct sock *sk) {}
static void rawsock_tx_work(void *work) {}
static void sock_init_data(struct socket *sock, struct sock *sk) {}
static struct sock *sk_alloc(struct net *net, int family, int priority, void *proto, int kern) { return 0; }
static void nfc_sock_link(struct list_head *list, struct sock *sk) {}