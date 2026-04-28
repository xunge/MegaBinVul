#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>

struct socket {
    struct sock *sk;
};

struct sock {
    void *sk_user_data;
};

struct l2tp_session {
    unsigned int session_id;
    unsigned int peer_session_id;
};

struct l2tp_tunnel;

struct pppol2tp_session {
    struct sock *tunnel_sock;
};

#define __user
#define EINVAL 22
#define EFAULT 14
#define ENOTCONN 107
#define EBADF 9

struct proto {
    int (*setsockopt)(struct sock *sk, int level, int optname, char *optval, unsigned int optlen);
} udp_prot;

static inline int get_user(int *val, int *uaddr) {
    *val = *uaddr;
    return 0;
}

static inline void sock_put(struct sock *sk) {
    (void)sk;
}

extern int pppol2tp_sock_to_session(struct sock *sk);
extern int pppol2tp_tunnel_setsockopt(struct sock *sk, struct l2tp_tunnel *tunnel, int optname, int val);
extern int pppol2tp_session_setsockopt(struct sock *sk, struct l2tp_session *session, int optname, int val);
extern struct l2tp_tunnel *l2tp_sock_to_tunnel(struct sock *sk);
extern struct pppol2tp_session *l2tp_session_priv(struct l2tp_session *session);