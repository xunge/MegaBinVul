#include <sys/socket.h>
#include <sys/uio.h>
#include <errno.h>

struct kiocb;
struct socket {
    struct sock *sk;
};
struct sock;
struct sk_buff {
    unsigned int len;
    void *data;
};

#define EOPNOTSUPP 95

typedef struct {
    void *iov_base;
    size_t iov_len;
} iovec_t;

// 这些函数需要链接Linux内核网络模块，标准库无法提供完整实现
struct sk_buff *skb_recv_datagram(struct sock *sk, int flags, int noblock, int *err);
int skb_copy_datagram_iovec(const struct sk_buff *skb, int offset, const iovec_t *to, int len);
void skb_free_datagram(struct sock *sk, struct sk_buff *skb);
void caif_check_flow_release(struct sock *sk);