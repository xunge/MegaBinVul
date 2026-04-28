#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stddef.h>
#include <sched.h>

struct socket {
    struct sock *sk;
};

struct sock {
    int sk_state;
    int sk_err;
    int sk_shutdown;
};

struct vsock_sock {
    const struct vsock_transport *transport;
    int peer_shutdown;
};

struct vsock_transport {
    int (*stream_rcvhiwat)(struct vsock_sock *);
    int (*notify_recv_init)(struct vsock_sock *, size_t, void *);
    int (*notify_recv_pre_block)(struct vsock_sock *, size_t, void *);
    int (*notify_recv_pre_dequeue)(struct vsock_sock *, size_t, void *);
    ssize_t (*stream_dequeue)(struct vsock_sock *, struct msghdr *, size_t, int);
    int (*notify_recv_post_dequeue)(struct vsock_sock *, size_t, ssize_t, int, void *);
};

struct vsock_transport_recv_notify_data {
    int dummy;
};

typedef long s64;

#define TCP_ESTABLISHED 1
#define RCV_SHUTDOWN 1
#define SEND_SHUTDOWN 2
#define SOCK_DONE 0x20
#define TASK_INTERRUPTIBLE 1

#define DEFINE_WAIT(name) int name

extern struct task_struct *current;

static inline int sock_flag(struct sock *sk, int flag) { return 0; }
static inline void prepare_to_wait(void *wq, void *wait, int state) {}
static inline void finish_wait(void *wq, void *wait) {}
static inline void *sk_sleep(struct sock *sk) { return NULL; }
static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}
static inline struct vsock_sock *vsock_sk(struct sock *sk) { return NULL; }
static inline size_t sock_rcvlowat(struct sock *sk, int waitall, size_t len) { return 0; }
static inline long sock_rcvtimeo(struct sock *sk, int noblock) { return 0; }
static inline int signal_pending(struct task_struct *p) { return 0; }
static inline long schedule_timeout(long timeout) { return 0; }
static inline s64 vsock_stream_has_data(struct vsock_sock *vsk) { return 0; }
static inline int sock_intr_errno(long timeout) { return 0; }