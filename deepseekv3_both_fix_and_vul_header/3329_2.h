#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>

struct kiocb;
struct sock;
struct msghdr;
struct sk_buff {
    unsigned int len;
};
struct inet_sock {
    int cmsg_flags;
};
struct iphdr {
    unsigned long saddr;
};

static struct inet_sock *inet_sk(struct sock *sk) { return 0; }
static int ip_recv_error(struct sock *sk, struct msghdr *msg, size_t len) { return 0; }
static struct sk_buff *skb_recv_datagram(struct sock *sk, int flags, int noblock, int *err) { return 0; }
static int skb_copy_datagram_iovec(struct sk_buff *skb, int offset, void *iov, int len) { return 0; }
static void sock_recv_ts_and_drops(struct msghdr *msg, struct sock *sk, struct sk_buff *skb) {}
static void ip_cmsg_recv(struct msghdr *msg, struct sk_buff *skb) {}
static void skb_free_datagram(struct sock *sk, struct sk_buff *skb) {}
static struct iphdr *ip_hdr(struct sk_buff *skb) { return 0; }