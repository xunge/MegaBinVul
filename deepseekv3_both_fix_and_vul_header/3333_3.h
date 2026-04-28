#include <sys/socket.h>
#include <stddef.h>

#define EOPNOTSUPP 95

struct kiocb;
struct sock;
struct sk_buff {
    unsigned int len;
    void *cb;
};

struct ieee802154_addr {
    unsigned short addr_type;
    unsigned char addr[8];
};

struct sockaddr_ieee802154 {
    unsigned short family;
    struct ieee802154_addr addr;
};

static inline struct {
    struct ieee802154_addr sa;
} *mac_cb(const struct sk_buff *skb)
{
    return (void *)skb->cb;
}

static struct sk_buff *skb_recv_datagram(struct sock *sk, int flags, int noblock, int *err) { return 0; }
static int skb_copy_datagram_iovec(struct sk_buff *skb, int offset, struct iovec *iov, int len) { return 0; }
static void sock_recv_ts_and_drops(struct msghdr *msg, struct sock *sk, struct sk_buff *skb) {}
static void skb_free_datagram(struct sock *sk, struct sk_buff *skb) {}