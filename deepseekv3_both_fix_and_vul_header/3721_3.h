#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <stddef.h>
#include <string.h>

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

struct l2tp_tunnel {
    // minimal tunnel definition
};

struct pppol2tp_session {
    struct sock *tunnel_sock;
};

struct udp_prot {
    int (*getsockopt)(struct sock *sk, int level, int optname, 
                     void *optval, int *optlen);
};

extern struct udp_prot udp_prot;

#define SOL_PPPOL2TP 273
#define __user
#define min_t(type, x, y) ((type)(x) < (type)(y) ? (type)(x) : (type)(y))
#define EFAULT 14
#define EINVAL 22
#define ENOTCONN 107
#define EBADF 9

extern struct l2tp_session *pppol2tp_sock_to_session(struct sock *sk);
extern int pppol2tp_tunnel_getsockopt(struct sock *sk, struct l2tp_tunnel *tunnel, int optname, int *val);
extern int pppol2tp_session_getsockopt(struct sock *sk, struct l2tp_session *session, int optname, int *val);
extern struct l2tp_tunnel *l2tp_sock_to_tunnel(struct sock *sk);
extern void sock_put(struct sock *sk);
extern struct pppol2tp_session *l2tp_session_priv(struct l2tp_session *session);

static inline int get_user(int val, int *addr) { return val = *addr, 0; }
static inline int put_user(int val, int *addr) { return *addr = val, 0; }
static inline int copy_to_user(void *to, const void *from, unsigned long n) { memcpy(to, from, n); return 0; }