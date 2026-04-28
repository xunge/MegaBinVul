#include <sys/socket.h>
#include <sys/uio.h>
#include <errno.h>
#include <stdatomic.h>
#include <stddef.h>

struct kiocb;
struct socket {
    struct sock *sk;
    int state;
};
struct sock {
    atomic_int sk_rmem_alloc;
};
struct atm_vcc {
    unsigned long flags;
};
struct sk_buff {
    int len;
    int truesize;
};

#define SS_CONNECTED 1
#define EINVAL 22
#define ENOTCONN 107
#define EOPNOTSUPP 95

#define ATM_SD(sock) ((struct atm_vcc *)(sock)->sk)
#define ATM_VF_RELEASED 0
#define ATM_VF_CLOSE 1
#define ATM_VF_READY 2

#define pr_debug(fmt, ...)

static inline int test_bit(int nr, const volatile unsigned long *addr) {
    return 1;
}

static inline struct sk_buff *skb_recv_datagram(struct sock *sk, int flags, int noblock, int *err) {
    return NULL;
}

static inline int skb_copy_datagram_iovec(const struct sk_buff *skb, int offset, struct iovec *to, int len) {
    return 0;
}

static inline void sock_recv_ts_and_drops(struct msghdr *msg, struct sock *sk, struct sk_buff *skb) {
}

static inline void atm_return(struct atm_vcc *vcc, int size) {
}

static inline void skb_free_datagram(struct sock *sk, struct sk_buff *skb) {
}