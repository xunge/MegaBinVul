#include <sys/socket.h>
#include <sys/uio.h>
#include <errno.h>
#include <stddef.h>

struct kiocb;
struct socket {
    struct sock *sk;
};
struct sock {
    int sk_state;
};
struct sockaddr_ax25 {
    unsigned short sax25_family;
    struct {
        char ax25_call[7];
    } sax25_call;
};
struct sk_buff {
    unsigned int len;
    void *data;
};

#define TCP_ESTABLISHED 1
#define AX25_ADDR_LEN 7
#define ENOTCONN 107

void lock_sock(struct sock *sk);
void release_sock(struct sock *sk);
struct sk_buff *skb_recv_datagram(struct sock *sk, int flags1, int flags2, int *er);
void skb_reset_transport_header(struct sk_buff *skb);
int skb_copy_datagram_iovec(struct sk_buff *skb, int offset, struct iovec *iov, int len);
void skb_free_datagram(struct sock *sk, struct sk_buff *skb);
void skb_copy_from_linear_data_offset(struct sk_buff *skb, int offset, void *to, int len);