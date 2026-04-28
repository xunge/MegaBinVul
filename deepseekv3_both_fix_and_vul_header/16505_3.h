#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>

struct socket {
    struct sock *sk;
};

struct sock {
    int sk_state;
    int sk_shutdown;
    int sk_err;
};

struct vsock_sock {
    const struct vsock_transport *transport;
    struct sockaddr local_addr;
    struct sockaddr remote_addr;
    int peer_shutdown;
};

struct vsock_transport {
    int (*notify_send_init)(struct vsock_sock *, void *);
    int (*notify_send_pre_block)(struct vsock_sock *, void *);
    int (*notify_send_pre_enqueue)(struct vsock_sock *, void *);
    ssize_t (*stream_enqueue)(struct vsock_sock *, struct msghdr *, size_t);
    int (*notify_send_post_enqueue)(struct vsock_sock *, ssize_t, void *);
};

struct vsock_transport_send_notify_data {
    int dummy;
};

#define DEFINE_WAIT_FUNC(name, function) \
    struct { \
        void *private; \
        int (*func)(void *); \
        void *entry; \
    } name = { \
        .private = NULL, \
        .func = (int (*)(void *))function, \
        .entry = NULL \
    }

static int woken_wake_function(void *data) { return 0; }
static void *current = NULL;

#define TCP_ESTABLISHED 1
#define SEND_SHUTDOWN 1
#define RCV_SHUTDOWN 2
#define TASK_INTERRUPTIBLE 1

static inline struct vsock_sock *vsock_sk(struct sock *sk) { return (struct vsock_sock *)sk; }
static inline int vsock_addr_bound(struct sockaddr *addr) { return 1; }
static inline int vsock_stream_has_space(struct vsock_sock *vsk) { return 1; }
static inline void *sk_sleep(struct sock *sk) { return NULL; }
static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}
static inline long sock_sndtimeo(struct sock *sk, int flags) { return 0; }
static inline long wait_woken(void *wait, int state, long timeout) { return 0; }
static inline void add_wait_queue(void *sleep, void *wait) {}
static inline void remove_wait_queue(void *sleep, void *wait) {}
static inline int signal_pending(void *task) { return 0; }
static inline int sock_intr_errno(long timeout) { return EINTR; }