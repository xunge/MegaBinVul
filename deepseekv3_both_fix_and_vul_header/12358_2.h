#include <stddef.h>

typedef struct sock {
    int sk_state;
    void (*sk_state_change)(struct sock *);
} sock;

typedef struct sk_buff {
    unsigned char cb[48];
} sk_buff;

typedef struct dccp_hdr {
    unsigned char dccph_type;
} dccp_hdr;

typedef struct dccp_sock {
    int dccps_role;
} dccp_sock;

typedef struct dccp_skb_cb {
    unsigned int dccpd_seq;
    int dccpd_reset_code;
} dccp_skb_cb;

typedef struct inet_connection_sock {
    struct {
        int (*conn_request)(struct sock *, struct sk_buff *);
    } *icsk_af_ops;
} inet_connection_sock;

#define DCCP_SKB_CB(__skb) ((struct dccp_skb_cb *)&((__skb)->cb[0]))

enum {
    DCCP_LISTEN,
    DCCP_CLOSED,
    DCCP_REQUESTING,
    DCCP_PARTOPEN,
    DCCP_RESPOND
};

enum dccp_pkt_type {
    DCCP_PKT_REQUEST,
    DCCP_PKT_RESPONSE,
    DCCP_PKT_DATA,
    DCCP_PKT_RESET,
    DCCP_PKT_CLOSEREQ,
    DCCP_PKT_CLOSE,
    DCCP_PKT_ACK,
    DCCP_PKT_DATAACK,
    DCCP_PKT_SYNC,
    DCCP_PKT_SYNCACK
};

enum dccp_role {
    DCCP_ROLE_CLIENT,
    DCCP_ROLE_SERVER
};

enum dccp_reset_codes {
    DCCP_RESET_CODE_NO_CONNECTION
};

#define SOCK_WAKE_IO 1
#define POLL_OUT 4
#define unlikely(x) (x)

static inline struct dccp_sock *dccp_sk(const struct sock *sk) { return (struct dccp_sock *)sk; }
static inline struct inet_connection_sock *inet_csk(const struct sock *sk) { return (struct inet_connection_sock *)sk; }
static int dccp_check_seqno(struct sock *sk, struct sk_buff *skb) { return 0; }
static void dccp_send_sync(struct sock *sk, unsigned int seq, int type) {}
static int dccp_parse_options(struct sock *sk, void *opt, struct sk_buff *skb) { return 0; }
static void dccp_rcv_reset(struct sock *sk, struct sk_buff *skb) {}
static int dccp_rcv_closereq(struct sock *sk, struct sk_buff *skb) { return 0; }
static int dccp_rcv_close(struct sock *sk, struct sk_buff *skb) { return 0; }
static int dccp_rcv_request_sent_state_process(struct sock *sk, struct sk_buff *skb, struct dccp_hdr *dh, unsigned int len) { return 0; }
static void dccp_handle_ackvec_processing(struct sock *sk, struct sk_buff *skb) {}
static void dccp_deliver_input_to_ccids(struct sock *sk, struct sk_buff *skb) {}
static int dccp_rcv_respond_partopen_state_process(struct sock *sk, struct sk_buff *skb, struct dccp_hdr *dh, unsigned int len) { return 0; }
static void sk_wake_async(struct sock *sk, int how, int mask) {}
static void __kfree_skb(struct sk_buff *skb) {}