#include <sys/socket.h>
#include <sys/un.h>
#include <errno.h>
#include <stddef.h>

#define SOCK_PASSCRED 1
#define SOCK_DEAD 2

struct socket {
    struct sock *sk;
    int type;
    unsigned long flags;
};

struct sock {
    struct socket *sk_socket;
    // other members...
};

struct net;
struct unix_sock {
    void *addr;
    // other members...
};

static inline struct net *sock_net(struct sock *sk) { return NULL; }
static inline void unix_state_double_lock(struct sock *sk1, struct sock *sk2) {}
static inline void unix_state_double_unlock(struct sock *sk1, struct sock *sk2) {}
static inline struct sock **unix_peer_ptr(struct sock *sk) { static struct sock *peer; return &peer; }
#define unix_peer(sk) (*unix_peer_ptr(sk))
static inline void sock_put(struct sock *sk) {}
static inline int unix_mkname(struct sockaddr_un *sunaddr, int len, unsigned int *hash) { return 0; }
static inline struct sock *unix_find_other(struct net *net, struct sockaddr_un *sunaddr, int len, int type, unsigned int hash, int *err) { return NULL; }
static inline int unix_may_send(struct sock *sk, struct sock *other) { return 0; }
static inline void unix_dgram_disconnected(struct sock *sk, struct sock *old_peer) {}
static inline int unix_autobind(struct socket *sock) { return 0; }
static inline struct unix_sock *unix_sk(struct sock *sk) { return (struct unix_sock *)sk; }
static inline int security_unix_may_send(void *sk1, void *sk2) { return 0; }
static inline int test_bit(int nr, const volatile unsigned long *addr) { return 0; }
static inline int sock_flag(const struct sock *sk, int flag) { return 0; }