#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint8_t u8;
typedef uint32_t u32;

struct sk_buff {
    struct sk_buff *next;
    struct sk_buff *prev;
};

struct sk_buff_head {
    struct sk_buff *next;
    struct sk_buff *prev;
    int qlen;
};

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

struct l2cap_ctrl {
    u8 txseq;
    u8 final;
    u8 poll;
};

struct l2cap_chan {
    u8 expected_tx_seq;
    u8 buffer_seq;
    u8 rx_state;
    u32 conn_state;
    u32 unacked_frames;
    struct sk_buff_head srej_q;
    struct list_head srej_list;
    struct list_head retrans_list;
};

#define BIT(nr) (1UL << (nr))
#define test_bit(nr, addr) (!!(*(addr) & BIT(nr)))
#define set_bit(nr, addr) (*(addr) |= BIT(nr))
#define clear_bit(nr, addr) (*(addr) &= ~BIT(nr))
#define test_and_clear_bit(nr, addr) \
    ({ int __ret = test_bit(nr, addr); if (__ret) clear_bit(nr, addr); __ret; })

static inline void skb_queue_tail(struct sk_buff_head *list, struct sk_buff *skb) {
    skb->next = (struct sk_buff *)list;
    skb->prev = list->prev;
    list->prev->next = skb;
    list->prev = skb;
    list->qlen++;
}

static inline int skb_queue_len(const struct sk_buff_head *list) {
    return list->qlen;
}

static inline void INIT_LIST_HEAD(struct list_head *list) {
    list->next = list;
    list->prev = list;
}

static inline void l2cap_seq_list_clear(struct list_head *list) {
    INIT_LIST_HEAD(list);
}

static inline void kfree_skb(struct sk_buff *skb) {
    free(skb);
}

enum {
    L2CAP_EV_RECV_IFRAME,
    L2CAP_EV_RECV_RR,
    L2CAP_EV_RECV_RNR,
    L2CAP_EV_RECV_REJ,
    L2CAP_EV_RECV_SREJ
};

enum {
    L2CAP_TXSEQ_EXPECTED,
    L2CAP_TXSEQ_UNEXPECTED,
    L2CAP_TXSEQ_DUPLICATE,
    L2CAP_TXSEQ_INVALID_IGNORE,
    L2CAP_TXSEQ_INVALID
};

enum {
    L2CAP_RX_STATE_SREJ_SENT
};

enum {
    CONN_LOCAL_BUSY,
    CONN_REJ_ACT,
    CONN_SREJ_ACT,
    CONN_REMOTE_BUSY,
    CONN_SEND_FBIT
};

#define BT_DBG(fmt, ...)
#define ECONNRESET 104

static inline u8 __next_seq(struct l2cap_chan *chan, u8 seq) { return seq + 1; }
static inline bool __chan_is_moving(struct l2cap_chan *chan) { return false; }
static inline void __set_retrans_timer(struct l2cap_chan *chan) {}
static inline void __clear_retrans_timer(struct l2cap_chan *chan) {}

static inline int l2cap_classify_txseq(struct l2cap_chan *chan, u8 txseq) { return 0; }
static inline void l2cap_pass_to_tx(struct l2cap_chan *chan, struct l2cap_ctrl *control) {}
static inline int l2cap_reassemble_sdu(struct l2cap_chan *chan, struct sk_buff *skb, struct l2cap_ctrl *control) { return 0; }
static inline void l2cap_retransmit_all(struct l2cap_chan *chan, struct l2cap_ctrl *control) {}
static inline void l2cap_ertm_send(struct l2cap_chan *chan) {}
static inline void l2cap_send_ack(struct l2cap_chan *chan) {}
static inline void l2cap_send_srej(struct l2cap_chan *chan, u8 txseq) {}
static inline void l2cap_send_disconn_req(struct l2cap_chan *chan, int err) {}
static inline void l2cap_send_i_or_rr_or_rnr(struct l2cap_chan *chan) {}
static inline void l2cap_send_rr_or_rnr(struct l2cap_chan *chan, int ack) {}
static inline void l2cap_handle_rej(struct l2cap_chan *chan, struct l2cap_ctrl *control) {}
static inline void l2cap_handle_srej(struct l2cap_chan *chan, struct l2cap_ctrl *control) {}