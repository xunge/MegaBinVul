#include <stddef.h>

#define DCCP_LISTEN 0
#define DCCP_REQUESTING 1
#define DCCP_RESPOND 2
#define DCCP_PARTOPEN 3
#define DCCP_CLOSED 4

#define DCCP_PKT_REQUEST 0
#define DCCP_PKT_RESPONSE 1
#define DCCP_PKT_DATA 2
#define DCCP_PKT_ACK 3
#define DCCP_PKT_DATAACK 4
#define DCCP_PKT_CLOSEREQ 5
#define DCCP_PKT_CLOSE 6
#define DCCP_PKT_RESET 7
#define DCCP_PKT_SYNC 8
#define DCCP_PKT_SYNCACK 9

#define DCCP_ROLE_CLIENT 0
#define DCCP_RESET_CODE_NO_CONNECTION 0

#define SOCK_WAKE_IO 0
#define POLL_OUT 0

struct sock {
    int sk_state;
    void (*sk_state_change)(struct sock *);
};

struct sk_buff {
    unsigned char cb[48];
};

struct dccp_hdr {
    unsigned char dccph_type;
};

struct dccp_sock {
    int dccps_role;
};

struct dccp_skb_cb {
    unsigned int dccpd_seq;
    int dccpd_reset_code;
};

struct inet_connection_sock {
    struct {
        int (*conn_request)(struct sock *, struct sk_buff *);
    } *icsk_af_ops;
};

#define DCCP_SKB_CB(__skb) ((struct dccp_skb_cb *)&((__skb)->cb[0]))
#define dccp_sk(__sk) ((struct dccp_sock *)__sk)
#define inet_csk(__sk) ((struct inet_connection_sock *)__sk)

static inline void __kfree_skb(struct sk_buff *skb) {}
static inline void sk_wake_async(struct sock *sk, int how, int mask) {}

static int dccp_check_seqno(struct sock *sk, struct sk_buff *skb) { return 0; }
static int dccp_parse_options(struct sock *sk, void *null, struct sk_buff *skb) { return 0; }
static void dccp_handle_ackvec_processing(struct sock *sk, struct sk_buff *skb) {}
static void dccp_deliver_input_to_ccids(struct sock *sk, struct sk_buff *skb) {}
static void dccp_rcv_reset(struct sock *sk, struct sk_buff *skb) {}
static void dccp_send_sync(struct sock *sk, unsigned int seq, int type) {}
static int dccp_rcv_closereq(struct sock *sk, struct sk_buff *skb) { return 0; }
static int dccp_rcv_close(struct sock *sk, struct sk_buff *skb) { return 0; }
static int dccp_rcv_request_sent_state_process(struct sock *sk, struct sk_buff *skb, struct dccp_hdr *dh, unsigned len) { return 0; }
static int dccp_rcv_respond_partopen_state_process(struct sock *sk, struct sk_buff *skb, struct dccp_hdr *dh, unsigned len) { return 0; }