#include <sys/socket.h>
#include <linux/if_packet.h>
#include <linux/llc.h>

struct sock;
struct sk_buff {
    struct sock *sk;
};
struct llc_sock {
    unsigned int cmsg_flags;
    struct net_device *dev;
};
struct net_device {
    int ifindex;
};

#define LLC_CMSG_PKTINFO 1

static inline struct llc_sock *llc_sk(struct sock *sk) { return (struct llc_sock *)sk; }
static inline void llc_pdu_decode_dsap(struct sk_buff *skb, unsigned char *dsap) {}
static inline void llc_pdu_decode_da(struct sk_buff *skb, unsigned char *da) {}
static inline void put_cmsg(struct msghdr *msg, int level, int type, int len, void *data) {}