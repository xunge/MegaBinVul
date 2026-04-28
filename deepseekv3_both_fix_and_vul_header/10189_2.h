#include <stdbool.h>
#include <string.h>

struct sock_extended_err {
    int ee_errno;
    unsigned int ee_origin;
    unsigned int ee_info;
    unsigned int ee_data;
};

struct skb_shared_info {
    unsigned int tskey;
};

struct sock_exterr_skb {
    struct sock_extended_err ee;
    bool opt_stats;
};

struct sk_buff {
    unsigned char cb[48];
    struct skb_shared_info shinfo;
};

struct sock {
    unsigned int sk_tsflags;
    int sk_protocol;
    int sk_type;
    unsigned int sk_tskey;
};

#define ENOMSG 42
#define SO_EE_ORIGIN_TIMESTAMPING 1
#define SOF_TIMESTAMPING_OPT_ID 1
#define IPPROTO_TCP 6
#define SOCK_STREAM 1

#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))
#define SKB_EXT_ERR(skb) ((struct sock_exterr_skb *)(skb)->cb)
#define skb_shinfo(skb) (&(skb)->shinfo)

static inline int sock_queue_err_skb(struct sock *sk, struct sk_buff *skb) { return 0; }
static inline void kfree_skb(struct sk_buff *skb) {}