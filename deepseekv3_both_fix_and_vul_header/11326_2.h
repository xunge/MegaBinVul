#include <sys/socket.h>
#include <stdlib.h>

enum dccp_reset_codes {
    DCCP_RESET_CODE_UNSPECIFIED = 0
};

struct sock;
struct sk_buff {
    unsigned char cb[48];
};

struct inet_connection_sock {
    struct {
        int (*rebuild_header)(struct sock *sk);
    } *icsk_af_ops;
};

struct sock {
    struct {
        int max_header;
    } *sk_prot;
};

struct dccp_skb_cb {
    unsigned char dccpd_type;
    unsigned char dccpd_reset_code;
};

#define DCCP_SKB_CB(skb) ((struct dccp_skb_cb *)((skb)->cb))
#define DCCP_PKT_RESET 0
#define GFP_ATOMIC 0
#define ENOBUFS 105

static inline struct inet_connection_sock *inet_csk(struct sock *sk) { return (struct inet_connection_sock *)sk; }
static inline struct sk_buff *sock_wmalloc(struct sock *sk, int size, int priority, int flags) { return NULL; }
static inline void skb_reserve(struct sk_buff *skb, int len) {}
static inline int dccp_transmit_skb(struct sock *sk, struct sk_buff *skb) { return 0; }