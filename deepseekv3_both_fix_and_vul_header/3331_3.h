#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>

struct kiocb;
struct sock;
struct msghdr;
struct inet_sock {
    int cmsg_flags;
};
struct sk_buff {
    unsigned int len;
    void* data;
};
struct iphdr {
    unsigned long saddr;
};

#define EOPNOTSUPP 95

static inline struct inet_sock *inet_sk(const struct sock *sk) { return (struct inet_sock *)sk; }
static inline int ip_recv_error(struct sock *sk, struct msghdr *msg, size_t len) { return -1; }
static inline struct sk_buff *skb_recv_datagram(struct sock *sk, int flags, int noblock, int *err) { return NULL; }
static inline int skb_copy_datagram_iovec(struct sk_buff *skb, int offset, void *iov, int len) { return -1; }
static inline void sock_recv_ts_and_drops(struct msghdr *msg, struct sock *sk, struct sk_buff *skb) {}
static inline struct iphdr *ip_hdr(const struct sk_buff *skb) { return (struct iphdr*)skb->data; }
static inline void ip_cmsg_recv(struct msghdr *msg, struct sk_buff *skb) {}
static inline void skb_free_datagram(struct sock *sk, struct sk_buff *skb) {}