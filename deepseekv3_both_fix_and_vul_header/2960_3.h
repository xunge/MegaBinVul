#include <sys/types.h>
#include <sys/socket.h>
#include <sys/uio.h>
#include <stdatomic.h>

struct kiocb;
struct socket {
    struct sock *sk;
};
struct sock {
    _Atomic unsigned int sk_rmem_alloc;
    unsigned int sk_rcvbuf;
};
struct irda_sock {
    int rx_flow;
    void *tsap;
};
struct sk_buff {
    size_t len;
};

#define IRDA_DEBUG(level, fmt, ...)
#define FLOW_STOP 0
#define FLOW_START 1

static inline struct irda_sock *irda_sk(struct sock *sk) { return (struct irda_sock *)sk; }
static inline void *skb_recv_datagram(struct sock *sk, int flags1, int flags2, int *err) { return 0; }
static inline void skb_reset_transport_header(struct sk_buff *skb) {}
static inline void skb_copy_datagram_iovec(struct sk_buff *skb, int offset, struct iovec *iov, size_t len) {}
static inline void skb_free_datagram(struct sock *sk, struct sk_buff *skb) {}
static inline unsigned int atomic_read(const _Atomic unsigned int *v) { return *v; }
static inline void irttp_flow_request(void *tsap, int flow) {}