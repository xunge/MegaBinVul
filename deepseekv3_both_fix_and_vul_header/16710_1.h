#include <sys/socket.h>
#include <errno.h>

struct sockaddr_qrtr {
    unsigned short sq_family;
    unsigned int sq_node;
    unsigned int sq_port;
};

struct sk_buff {
    unsigned int len;
    char cb[48];
};

struct qrtr_cb {
    unsigned int src_node;
    unsigned int src_port;
    int confirm_rx;
};

struct socket {
    void *sk;
};

struct sock {
    unsigned int flags;
};

#define AF_QIPCRTR 42
#define SOCK_ZAPPED 0x00000001
#define MSG_DONTWAIT 0x40
#define MSG_TRUNC 0x20
#define EADDRNOTAVAIL 99

#define DECLARE_SOCKADDR(type, name, addr) type name = (type)(addr)

static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}
static inline int sock_flag(struct sock *sk, int flag) { return sk->flags & flag; }
static inline struct sk_buff *skb_recv_datagram(struct sock *sk, int flags1, int flags2, int *rc) { return 0; }
static inline int skb_copy_datagram_msg(struct sk_buff *skb, int offset, struct msghdr *msg, int size) { return 0; }
static inline void skb_free_datagram(struct sock *sk, struct sk_buff *skb) {}
static inline void qrtr_send_resume_tx(struct qrtr_cb *cb) {}