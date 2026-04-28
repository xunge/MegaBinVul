#include <sys/socket.h>
#include <sys/uio.h>
#include <stdlib.h>

#define EIO 5
#define PPPOX_BOUND 0x1

struct kiocb {};
struct socket {
    struct sock *sk;
};
struct sock {
    int sk_state;
};
struct sk_buff {
    unsigned char *data;
    int len;
};

void kfree_skb(struct sk_buff *skb);
struct sk_buff *skb_recv_datagram(struct sock *sk, int flags1, int flags2, int *err);
int memcpy_toiovec(struct iovec *iov, unsigned char *data, int len);