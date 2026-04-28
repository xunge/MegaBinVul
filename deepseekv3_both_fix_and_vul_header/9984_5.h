#include <sys/socket.h>
#include <netinet/in.h>
#include <linux/types.h>
#include <errno.h>
#include <stddef.h>

#define SOCK_ZAPPED 0x02000000
#define EINVAL 22
#define EADDRINUSE 98
#define EADDRNOTAVAIL 99
#define TCP_CLOSE 0
#define RTN_LOCAL 1
#define RTN_MULTICAST 2
#define RTN_BROADCAST 3

struct sockaddr_l2tpip {
    sa_family_t l2tp_family;
    struct in_addr l2tp_addr;
    __u32 l2tp_conn_id;
};

struct inet_sock {
    int inet_rcv_saddr;
    int inet_saddr;
};

struct sock {
    int sk_state;
    int sk_bound_dev_if;
    unsigned int sk_flags;
};

struct l2tp_ip_sock {
    struct inet_sock inet;
    __u32 conn_id;
};

struct net;

static void read_lock_bh(void *lock) {}
static void read_unlock_bh(void *lock) {}
static void write_lock_bh(void *lock) {}
static void write_unlock_bh(void *lock) {}
static void lock_sock(struct sock *sk) {}
static void release_sock(struct sock *sk) {}
static void sk_dst_reset(struct sock *sk) {}
static void sock_reset_flag(struct sock *sk, int flag) {}
static int sock_flag(struct sock *sk, int flag) { return 0; }
static struct net *sock_net(struct sock *sk) { return NULL; }
static int inet_addr_type(struct net *net, unsigned int addr) { return 0; }
static void sk_add_bind_node(struct sock *sk, void *table) {}
static void sk_del_node_init(struct sock *sk) {}
static struct inet_sock *inet_sk(struct sock *sk) { return NULL; }
static int __l2tp_ip_bind_lookup(struct net *net, unsigned int addr, int ifindex, int conn_id) { return 0; }
static struct l2tp_ip_sock *l2tp_ip_sk(struct sock *sk) { return NULL; }

static void *l2tp_ip_lock;
static void *l2tp_ip_bind_table;