#include <sys/socket.h>
#include <sys/uio.h>
#include <errno.h>

struct kiocb;
struct socket {
    struct sock *sk;
};

struct sock {
    unsigned int sk_shutdown;
};

struct sk_buff {
    size_t len;
};

#define BT_DBG(fmt, ...)
#define RCV_SHUTDOWN 1

typedef int (*skb_recv_datagram_t)(struct sock *, int, int, int *);
typedef void (*skb_reset_transport_header_t)(struct sk_buff *);
typedef int (*skb_copy_datagram_iovec_t)(struct sk_buff *, int, void *, size_t);
typedef void (*sock_recv_ts_and_drops_t)(struct msghdr *, struct sock *, struct sk_buff *);
typedef void (*skb_free_datagram_t)(struct sock *, struct sk_buff *);