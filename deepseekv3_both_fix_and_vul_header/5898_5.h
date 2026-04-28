#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <stdbool.h>
#include <string.h>
#include <stdatomic.h>

typedef uint16_t __be16;
typedef uint32_t __be32;

struct sock {
    atomic_int sk_drops;
};

struct inet_sock {
    int cmsg_flags;
};

struct sk_buff {
    unsigned int len;
    unsigned char cb[48];
    void* data;
};

struct udp_skb_cb {
    int partial_cov;
};

#define IS_UDPLITE(sk) 0
#define UDP_SKB_CB(skb) ((struct udp_skb_cb *)&((skb)->cb[0]))
#define UDP_INC_STATS_USER(net, field, is_udplite) do { } while (0)
#define EINVAL 22
#define EAGAIN 11

#define DECLARE_SOCKADDR(type, name, msg_name) \
    type name = (type)(msg_name)

static inline struct udphdr *udp_hdr(const struct sk_buff *skb) { 
    return (struct udphdr *)(skb->data); 
}
static inline struct iphdr *ip_hdr(const struct sk_buff *skb) { 
    return (struct iphdr *)(skb->data); 
}
static inline void trace_kfree_skb(struct sk_buff *skb, void *location) {}
static inline void sock_recv_ts_and_drops(struct msghdr *msg, struct sock *sk, struct sk_buff *skb) {}
static inline void ip_cmsg_recv_offset(struct msghdr *msg, struct sk_buff *skb, int offset) {}
static inline void *sock_net(struct sock *sk) { return NULL; }
static inline struct inet_sock *inet_sk(const struct sock *sk) { return (struct inet_sock *)sk; }
static inline struct sk_buff *__skb_recv_datagram(struct sock *sk, unsigned int flags, int *peeked, int *off, int *err) { return NULL; }
static inline int udp_lib_checksum_complete(struct sk_buff *skb) { return 0; }
static inline bool skb_csum_unnecessary(const struct sk_buff *skb) { return false; }
static inline int skb_copy_datagram_msg(const struct sk_buff *skb, int offset, struct msghdr *msg, int size) { return 0; }
static inline int skb_copy_and_csum_datagram_msg(struct sk_buff *skb, int offset, struct msghdr *msg) { return 0; }
static inline void skb_free_datagram_locked(struct sock *sk, struct sk_buff *skb) {}
static inline bool lock_sock_fast(struct sock *sk) { return false; }
static inline bool skb_kill_datagram(struct sock *sk, struct sk_buff *skb, int flags) { return false; }
static inline void unlock_sock_fast(struct sock *sk, bool slow) {}
static inline int ip_recv_error(struct sock *sk, struct msghdr *msg, size_t len, int *addr_len) { return 0; }
#define unlikely(x) (x)