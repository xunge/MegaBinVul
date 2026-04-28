#include <poll.h>
#include <sys/socket.h>
#include <stdbool.h>

typedef unsigned int __poll_t;

struct file;
typedef struct poll_table_struct poll_table;

struct sock {
    int sk_err;
    unsigned char sk_shutdown;
    int sk_state;
    void *sk_receive_queue;
    void *sk_sleep;
};

struct socket {
    int type;
    struct sock *sk;
};

struct vsock_sock {
    unsigned int peer_shutdown;
    const struct vsock_transport *transport;
};

struct vsock_transport {
    bool (*stream_is_active)(struct vsock_sock *);
    int (*notify_poll_in)(struct vsock_sock *, int, bool *);
    int (*notify_poll_out)(struct vsock_sock *, int, bool *);
};

#define SHUTDOWN_MASK 3
#define SEND_SHUTDOWN 1
#define RCV_SHUTDOWN 2

#define TCP_LISTEN 10
#define TCP_ESTABLISHED 1
#define TCP_CLOSE 7
#define TCP_CLOSING 8

#define EPOLLIN 0x001
#define EPOLLPRI 0x002
#define EPOLLOUT 0x004
#define EPOLLERR 0x008
#define EPOLLHUP 0x010
#define EPOLLRDNORM 0x040
#define EPOLLRDBAND 0x080
#define EPOLLWRNORM 0x100
#define EPOLLWRBAND 0x200
#define EPOLLRDHUP 0x2000

static inline struct vsock_sock *vsock_sk(struct sock *sk) {
    return (struct vsock_sock *)sk;
}

static inline void *sk_sleep(struct sock *sk) {
    return sk->sk_sleep;
}

static inline bool skb_queue_empty_lockless(void *queue) {
    return true;
}

static inline bool vsock_is_accept_queue_empty(struct sock *sk) {
    return true;
}

static inline void poll_wait(struct file *file, void *wait_address, poll_table *wait) {
}

static inline void lock_sock(struct sock *sk) {
}

static inline void release_sock(struct sock *sk) {
}