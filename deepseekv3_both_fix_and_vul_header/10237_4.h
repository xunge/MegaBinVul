#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <errno.h>

struct sock;
struct msghdr;
struct inet_sock {
    int cmsg_flags;
};
struct sk_buff {
    unsigned int len;
};
struct udphdr {
    unsigned short source;
};
struct iphdr {
    unsigned int saddr;
};

#define DECLARE_SOCKADDR(type, name, msg_name) \
    type name = (type)(msg_name)

#define IS_UDPLITE(sk) (0)
#define UDP_SKB_CB(skb) ((struct udp_skb_cb *)NULL)
#define UDP_INC_STATS_USER(net, metric, is_udplite) do {} while (0)
#define UDP_MIB_INERRORS 0
#define UDP_MIB_CSUMERRORS 0
#define UDP_MIB_INDATAGRAMS 0

#define atomic_inc(v) do {} while (0)
#define unlikely(x) (x)
#define cond_resched() do {} while (0)

struct udp_skb_cb {
    int partial_cov;
};

static inline void trace_kfree_skb(struct sk_buff *skb, void *fn) {}
static inline void sock_recv_ts_and_drops(struct msghdr *msg, struct sock *sk, struct sk_buff *skb) {}
static inline void ip_cmsg_recv_offset(struct msghdr *msg, struct sk_buff *skb, int offset) {}
static inline int ip_recv_error(struct sock *sk, struct msghdr *msg, size_t len, int *addr_len) { return 0; }
static inline int udp_lib_checksum_complete(struct sk_buff *skb) { return 0; }
static inline bool skb_csum_unnecessary(struct sk_buff *skb) { return false; }
static inline int skb_copy_datagram_msg(struct sk_buff *skb, int offset, struct msghdr *msg, int len) { return 0; }
static inline int skb_copy_and_csum_datagram_msg(struct sk_buff *skb, int offset, struct msghdr *msg) { return 0; }
static inline void skb_free_datagram_locked(struct sock *sk, struct sk_buff *skb) {}
static inline bool lock_sock_fast(struct sock *sk) { return false; }
static inline void unlock_sock_fast(struct sock *sk, bool slow) {}
static inline bool skb_kill_datagram(struct sock *sk, struct sk_buff *skb, int flags) { return false; }
static inline struct sk_buff *__skb_recv_datagram(struct sock *sk, int flags, int *peeked, int *off, int *err) { return NULL; }
static inline struct inet_sock *inet_sk(struct sock *sk) { return NULL; }
static inline struct udphdr *udp_hdr(struct sk_buff *skb) { return NULL; }
static inline struct iphdr *ip_hdr(struct sk_buff *skb) { return NULL; }
static inline void *sock_net(struct sock *sk) { return NULL; }