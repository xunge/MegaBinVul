#include <stdint.h>
#include <stddef.h>

struct sk_buff {
    // dummy definition
};

typedef uint16_t u16;

struct l2cap_ctrl {
    u16 txseq;
    // other members as needed
};

struct l2cap_chan {
    int rx_state;
    u16 buffer_seq;
    struct sk_buff *sdu;
    struct sk_buff *sdu_last_frag;
    u16 sdu_len;
    u16 last_acked_seq;
    u16 expected_tx_seq;
    // other members as needed
};

#define BT_DBG(fmt, ...)
#define L2CAP_TXSEQ_EXPECTED 0

static inline u16 __next_seq(struct l2cap_chan *chan, u16 seq) { return 0; }
static void l2cap_pass_to_tx(struct l2cap_chan *chan, struct l2cap_ctrl *control) {}
static int l2cap_classify_txseq(struct l2cap_chan *chan, u16 txseq) { return 0; }
static void l2cap_reassemble_sdu(struct l2cap_chan *chan, struct sk_buff *skb, struct l2cap_ctrl *control) {}
static void kfree_skb(struct sk_buff *skb) {}