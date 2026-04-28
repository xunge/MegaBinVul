#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/time.h>
#include <signal.h>
#include <pthread.h>

struct socket {
    struct sock *sk;
    int state;
};

struct sock {
    int sk_state;
    int sk_err;
    int sk_refcnt;
    void *sk_sleep;
};

struct sockaddr_vm {
    unsigned int svm_cid;
    unsigned int svm_port;
};

struct vsock_sock {
    struct sock sk;
    struct sockaddr_vm remote_addr;
    const struct vsock_transport *transport;
    long connect_timeout;
    void *connect_work;
};

struct vsock_transport {
    int (*stream_allow)(unsigned int, unsigned int);
    int (*connect)(struct vsock_sock *);
};

#define vsock_sk(sk) ((struct vsock_sock *)(sk))
#define lock_sock(sk) /* dummy */
#define release_sock(sk) /* dummy */
#define vsock_addr_cast(addr, len, remote) (0)
#define vsock_assign_transport(vsk, trans) (0)
#define vsock_auto_bind(vsk) (0)
#define vsock_transport_cancel_pkt(vsk) /* dummy */
#define vsock_remove_connected(vsk) /* dummy */
#define prepare_to_wait(wait, entry, state) /* dummy */
#define finish_wait(wait, entry) /* dummy */
#define mod_delayed_work(wq, work, timeout) (0)
#define system_wq NULL
#define sock_intr_errno(timeout) (-EINTR)
#define TASK_INTERRUPTIBLE 0
#define schedule_timeout(timeout) (0)
#define signal_pending(current) (0)

#define TCP_LISTEN 10
#define TCP_SYN_SENT 2
#define TCP_ESTABLISHED 1
#define TCP_CLOSING 7
#define TCP_CLOSE 0

#define SS_CONNECTED 1
#define SS_DISCONNECTING 2
#define SS_CONNECTING 3
#define SS_UNCONNECTED 4

#define O_NONBLOCK 04000

#define EISCONN 106
#define EINVAL 22
#define EALREADY 114
#define ENETUNREACH 101
#define EINPROGRESS 115
#define ETIMEDOUT 110
#define EINTR 4

#define DEFINE_WAIT(name) int name
#define current pthread_self()
#define sk_sleep(sk) ((sk)->sk_sleep)
#define sock_hold(sk) ((sk)->sk_refcnt++)
#define sock_put(sk) ((sk)->sk_refcnt--)