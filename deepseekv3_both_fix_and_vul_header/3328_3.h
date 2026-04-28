#include <sys/socket.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdatomic.h>
#include <string.h>

struct kiocb;
struct sock {
    atomic_int sk_drops;
};
struct msghdr;
struct inet_sock {
    int cmsg_flags;
};
struct sk_buff {
    unsigned int len;
    unsigned char cb[48];
};
struct udphdr {
    unsigned short source;
};
struct iphdr {
    unsigned long saddr;
};
struct iovec;
struct net;
struct udp_skb_cb {
    int partial_cov;
};

#define IS_UDPLITE(sk) 0
#define UDP_SKB_CB(skb) ((struct udp_skb_cb *)&((skb)->cb[0]))
#define UDP_INC_STATS_USER(net, field, is_udplite) do { } while (0)
#define UDP_MIB_INERRORS 0
#define UDP_MIB_INDATAGRAMS 0
#define UDP_MIB_CSUMERRORS 0
#define EINVAL 22
#define EAGAIN 11

static inline struct inet_sock *inet_sk(const struct sock *sk) { return (struct inet_sock *)sk; }
static inline struct udphdr *udp_hdr(const struct sk_buff *skb) { return (struct udphdr *)((char*)skb + sizeof(struct sk_buff)); }
static inline struct iphdr *ip_hdr(const struct sk_buff *skb) { return (struct iphdr *)((char*)skb + sizeof(struct sk_buff) + sizeof(struct udphdr)); }
#define unlikely(x) (x)

int ip_recv_error(struct sock *sk, struct msghdr *msg, size_t len);
struct sk_buff *__skb_recv_datagram(struct sock *sk, unsigned int flags, int *peeked, int *off, int *err);
int udp_lib_checksum_complete(struct sk_buff *skb);
bool skb_csum_unnecessary(const struct sk_buff *skb);
int skb_copy_datagram_iovec(const struct sk_buff *skb, int offset, struct iovec *to, int len);
int skb_copy_and_csum_datagram_iovec(struct sk_buff *skb, int offset, struct iovec *to);
void trace_kfree_skb(struct sk_buff *skb, void *location);
void sock_recv_ts_and_drops(struct msghdr *msg, struct sock *sk, struct sk_buff *skb);
int ip_cmsg_recv(struct msghdr *msg, struct sk_buff *skb);
void skb_free_datagram_locked(struct sock *sk, struct sk_buff *skb);
bool lock_sock_fast(struct sock *sk);
bool skb_kill_datagram(struct sock *sk, struct sk_buff *skb, int flags);
void unlock_sock_fast(struct sock *sk, bool slow);
struct net *sock_net(struct sock *sk);