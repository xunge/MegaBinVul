#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <stddef.h>
#include <stdint.h>

struct kiocb;
struct socket {
    struct sock *sk;
};
struct sock {
    int sk_state;
    int sk_shutdown;
    int sk_err;
    unsigned long sk_flags;
    void (*sk_state_change)(struct sock *);
};
struct vsock_sock {
    int peer_shutdown;
};
struct vsock_transport_recv_notify_data {};
struct transport {
    int (*stream_rcvhiwat)(struct vsock_sock *);
    int (*notify_recv_init)(struct vsock_sock *, size_t, struct vsock_transport_recv_notify_data *);
    int (*notify_recv_pre_dequeue)(struct vsock_sock *, size_t, struct vsock_transport_recv_notify_data *);
    ssize_t (*stream_dequeue)(struct vsock_sock *, struct iovec *, size_t, int);
    int (*notify_recv_post_dequeue)(struct vsock_sock *, size_t, ssize_t, int, struct vsock_transport_recv_notify_data *);
    int (*notify_recv_pre_block)(struct vsock_sock *, size_t, struct vsock_transport_recv_notify_data *);
};
extern struct transport *transport;

#define SS_CONNECTED 1
#define SS_UNCONNECTED 0
#define RCV_SHUTDOWN 1
#define SEND_SHUTDOWN 2
#define SOCK_DONE 0x1

#define ENOTCONN 107
#define EOPNOTSUPP 95
#define ENOMEM 12
#define EAGAIN 11
#define EINTR 4

#define DEFINE_WAIT(name) int name
#define TASK_INTERRUPTIBLE 1

typedef int64_t s64;
extern void *current;

static inline struct vsock_sock *vsock_sk(struct sock *sk) { return (struct vsock_sock *)sk; }
static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}
static inline int sock_flag(struct sock *sk, int flag) { return sk->sk_flags & flag; }
static inline size_t sock_rcvlowat(struct sock *sk, int waitall, size_t len) { return waitall ? len : 1; }
static inline long sock_rcvtimeo(struct sock *sk, int noblock) { return noblock ? 0 : -1; }
static inline void *sk_sleep(struct sock *sk) { return NULL; }
static inline void prepare_to_wait(void *sleep, int *wait, int state) {}
static inline void finish_wait(void *sleep, int *wait) {}
static inline long schedule_timeout(long timeout) { return timeout; }
static inline int signal_pending(void *current) { return 0; }
static inline int sock_intr_errno(long timeout) { return -EINTR; }
static inline void sock_set_flag(struct sock *sk, int flag) { sk->sk_flags |= flag; }
static inline s64 vsock_stream_has_data(struct vsock_sock *vsk) { return 0; }