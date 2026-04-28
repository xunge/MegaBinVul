#include <stdint.h>
#include <stddef.h>
#include <netinet/in.h>
#include <sys/socket.h>

struct sock {
    int sk_ack_backlog;
    int sk_txrehash;
    struct {
        int (*get_port)(struct sock *, int);
        int (*hash)(struct sock *);
    } *sk_prot;
};

struct inet_connection_sock {
    struct {
        int dummy;
    } icsk_accept_queue;
};

struct inet_sock {
    int inet_num;
    uint16_t inet_sport;
};

struct net {
    struct {
        int sysctl_txrehash;
    } core;
};

#define TCP_LISTEN 10
#define TCP_CLOSE 7
#define SOCK_TXREHASH_DEFAULT (-1)

#define likely(x) __builtin_expect(!!(x), 1)
#define READ_ONCE(x) (*(volatile typeof(x) *)&(x))

static inline struct inet_connection_sock *inet_csk(struct sock *sk) {
    return (struct inet_connection_sock *)sk;
}

static inline struct inet_sock *inet_sk(struct sock *sk) {
    return (struct inet_sock *)sk;
}

static inline void reqsk_queue_alloc(void *queue) {}
static inline void inet_csk_delack_init(struct sock *sk) {}
static inline struct net *sock_net(struct sock *sk) { return NULL; }
static inline void inet_sk_state_store(struct sock *sk, int state) {}
static inline void sk_dst_reset(struct sock *sk) {}
static inline void inet_sk_set_state(struct sock *sk, int state) {}