#include <sys/socket.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include <sys/uio.h>
#include <unistd.h>

struct kiocb {
    struct sock_iocb *scm;
};

struct socket {
    struct sock *sk;
};

struct sock {
    int sk_state;
    int sk_shutdown;
    int sk_sndbuf;
    void *sk_receive_queue;
    void (*sk_data_ready)(struct sock *, int);
};

struct sock_iocb {
    struct scm_cookie *scm;
};

struct sk_buff {
    int dummy;
};

struct scm_cookie {
    int dummy;
};

#define TCP_ESTABLISHED 1
#define SEND_SHUTDOWN 1
#define RCV_SHUTDOWN 2
#define SOCK_DEAD 4

#define SKB_MAX_ALLOC 32768

#define ENOTCONN 107
#define EISCONN 106
#define EOPNOTSUPP 95
#define EPIPE 32
#define SIGPIPE 13

static inline struct sock_iocb *kiocb_to_siocb(struct kiocb *kiocb) { return (struct sock_iocb *)kiocb; }
static inline void wait_for_unix_gc(void) {}
static inline int scm_send(struct socket *sock, struct msghdr *msg, struct scm_cookie *scm, ...) { return 0; }
static inline struct sock *unix_peer(struct sock *sk) { return NULL; }
static inline void unix_state_lock(struct sock *sk) {}
static inline void unix_state_unlock(struct sock *sk) {}
static inline void maybe_add_creds(struct sk_buff *skb, struct socket *sock, struct sock *other) {}
static inline void scm_destroy(struct scm_cookie *scm) {}
static inline int unix_scm_to_skb(struct scm_cookie *scm, struct sk_buff *skb, bool send_fds) { return 0; }
static inline void kfree_skb(struct sk_buff *skb) {}
static inline struct sk_buff *sock_alloc_send_skb(struct sock *sk, int size, int flags, int *err) { return NULL; }
static inline int skb_tailroom(struct sk_buff *skb) { return 0; }
static inline void *skb_put(struct sk_buff *skb, unsigned int len) { return NULL; }
static inline int memcpy_fromiovec(void *kdata, struct iovec *iov, int len) { return 0; }
static inline int sock_flag(struct sock *sk, int flag) { return 0; }
static inline void skb_queue_tail(void *list, struct sk_buff *skb) {}
static inline void send_sig(int sig, void *p, int priv) {}

#define min_t(type, x, y) ((x) < (y) ? (x) : (y))

struct unix_sock {
    int recursion_level;
};

static inline struct unix_sock *unix_sk(struct sock *sk) { return (struct unix_sock *)sk; }

static void *current = NULL;