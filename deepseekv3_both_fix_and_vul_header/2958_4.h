#include <sys/types.h>
#include <sys/socket.h>
#include <stddef.h>

struct kiocb;
struct msghdr;

struct socket {
    struct sock *sk;
};

struct sock {
    int sk_state;
    unsigned long flags;
};

struct sco_pinfo {
    struct {
        struct hci_conn *hcon;
    } *conn;
};

struct hci_conn;

#define BT_CONNECT2 1
#define BT_CONFIG 2
#define BT_SK_DEFER_SETUP 0

static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}
static inline struct sco_pinfo *sco_pi(struct sock *sk) { return NULL; }
static inline struct sock *bt_sk(struct sock *sk) { return sk; }
static inline int test_bit(int nr, void *addr) { return 0; }
static inline void hci_conn_accept(struct hci_conn *hcon, int flag) {}
static inline int bt_sock_recvmsg(struct kiocb *iocb, struct socket *sock,
                                struct msghdr *msg, size_t len, int flags) { return 0; }