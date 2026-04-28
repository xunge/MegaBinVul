#include <netinet/in.h>
#include <stdbool.h>

#define LOOPBACK_IFINDEX 1
#define IP_CMSG_PKTINFO 0
#define PKTINFO_SKB_CB(skb) ((struct in_pktinfo *)((skb)->cb))

struct sk_buff {
    char cb[48];
    void* rtable;
};

struct sock {
    int cmsg_flags;
};

struct ip_options {
    struct {
        unsigned char optlen;
    } opt;
};

static inline bool ipv6_sk_rxinfo(const struct sock *sk) { return false; }
static inline void* skb_rtable(struct sk_buff *skb) { return skb->rtable; }
static inline int inet_iif(struct sk_buff *skb) { return 0; }
static inline unsigned int fib_compute_spec_dst(struct sk_buff *skb) { return 0; }
static inline bool unlikely(bool x) { return x; }
static inline struct ip_options* IPCB(struct sk_buff *skb) { return (struct ip_options*)skb->cb; }
static inline void skb_dst_force(struct sk_buff *skb) {}
static inline void skb_dst_drop(struct sk_buff *skb) {}
static inline struct sock* inet_sk(const struct sock *sk) { return (struct sock*)sk; }