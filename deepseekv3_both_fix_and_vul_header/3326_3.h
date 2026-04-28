#include <sys/socket.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

struct kiocb;
struct msghdr;

struct sock {
    int sk_drops;
};

struct inet_sock {
    int cmsg_flags;
};

struct sk_buff {
    unsigned int len;
    void *cb;
    struct udphdr *udp_header;
    struct iphdr *ip_header;
};

struct udphdr {
    unsigned short source;
};

struct iphdr {
    unsigned int saddr;
};

struct UDP_SKB_CB {
    bool partial_cov;
};

#define IS_UDPLITE(sk) (0)
#define UDP_MIB_INERRORS 0
#define UDP_MIB_INDATAGRAMS 1
#define UDP_MIB_CSUMERRORS 2

static inline struct inet_sock *inet_sk(struct sock *sk) { return (struct inet_sock *)sk; }
static inline struct UDP_SKB_CB *UDP_SKB_CB(struct sk_buff *skb) { return (struct UDP_SKB_CB *)skb->cb; }
static inline struct udphdr *udp_hdr(struct sk_buff *skb) { return skb->udp_header; }
static inline struct iphdr *ip_hdr(struct sk_buff *skb) { return skb->ip_header; }

static inline int ip_recv_error(struct sock *sk, struct msghdr *msg, size_t len) { return 0; }
static inline struct sk_buff *__skb_recv_datagram(struct sock *sk, int flags, int *peeked, int *off, int *err) { return NULL; }
static inline int udp_lib_checksum_complete(struct sk_buff *skb) { return 0; }
static inline int skb_csum_unnecessary(struct sk_buff *skb) { return 0; }
static inline int skb_copy_datagram_iovec(struct sk_buff *skb, int offset, void *iov, int len) { return 0; }
static inline int skb_copy_and_csum_datagram_iovec(struct sk_buff *skb, int offset, void *iov) { return 0; }
static inline int unlikely(int err) { return err; }
static inline void trace_kfree_skb(struct sk_buff *skb, void *func) {}
static inline void atomic_inc(int *count) {}
static inline void UDP_INC_STATS_USER(void *net, int type, int is_udplite) {}
static inline void *sock_net(struct sock *sk) { return NULL; }
static inline void sock_recv_ts_and_drops(struct msghdr *msg, struct sock *sk, struct sk_buff *skb) {}
static inline int ip_cmsg_recv(struct msghdr *msg, struct sk_buff *skb) { return 0; }
static inline void skb_free_datagram_locked(struct sock *sk, struct sk_buff *skb) {}
static inline bool lock_sock_fast(struct sock *sk) { return false; }
static inline int skb_kill_datagram(struct sock *sk, struct sk_buff *skb, int flags) { return 0; }
static inline void unlock_sock_fast(struct sock *sk, bool slow) {}