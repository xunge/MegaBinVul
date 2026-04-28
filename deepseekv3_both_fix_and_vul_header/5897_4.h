#include <sys/socket.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdatomic.h>

struct sock {
    _Atomic int sk_drops;
};

struct inet_sock {
    int cmsg_flags;
};

struct sk_buff {
    unsigned int len;
    char cb[48];
};

struct udphdr {
    unsigned short source;
};

struct iphdr {
    unsigned int saddr;
};

#define DECLARE_SOCKADDR(type, name, msg_name) type name = (type)(msg_name)
#define IS_UDPLITE(sk) (0)
#define UDP_SKB_CB(skb) ((struct udp_skb_cb *)&((skb)->cb[0]))
#define UDP_INC_STATS_USER(net, metric, is_udplite) do { } while (0)
#define EINVAL (-22)
#define EAGAIN (-11)

struct udp_skb_cb {
    int partial_cov;
};

static inline struct inet_sock *inet_sk(const struct sock *sk) {
    return (struct inet_sock *)sk;
}

static inline struct udphdr *udp_hdr(const struct sk_buff *skb) {
    return (struct udphdr *)(skb + 1);
}

static inline struct iphdr *ip_hdr(const struct sk_buff *skb) {
    return (struct iphdr *)((char *)(skb + 1) + sizeof(struct udphdr));
}

static inline int unlikely(int x) { return x; }

static inline int ip_recv_error(struct sock *sk, struct msghdr *msg, size_t len, int *addr_len) {
    return -1;
}

static inline struct sk_buff *__skb_recv_datagram(struct sock *sk, int flags, int *peeked, int *off, int *err) {
    return NULL;
}

static inline int udp_lib_checksum_complete(struct sk_buff *skb) {
    return 0;
}

static inline int skb_csum_unnecessary(struct sk_buff *skb) {
    return 1;
}

static inline int skb_copy_datagram_msg(struct sk_buff *skb, int offset, struct msghdr *msg, int len) {
    return 0;
}

static inline int skb_copy_and_csum_datagram_msg(struct sk_buff *skb, int offset, struct msghdr *msg) {
    return 0;
}

static inline void trace_kfree_skb(struct sk_buff *skb, void *func) {}

static inline void sock_recv_ts_and_drops(struct msghdr *msg, struct sock *sk, struct sk_buff *skb) {}

static inline void ip_cmsg_recv_offset(struct msghdr *msg, struct sk_buff *skb, int offset) {}

static inline void skb_free_datagram_locked(struct sock *sk, struct sk_buff *skb) {}

static inline bool lock_sock_fast(struct sock *sk) {
    return false;
}

static inline int skb_kill_datagram(struct sock *sk, struct sk_buff *skb, int flags) {
    return 0;
}

static inline void unlock_sock_fast(struct sock *sk, bool slow) {}