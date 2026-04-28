#include <stdint.h>
#include <stdlib.h>

#define BT_DBG(fmt, ...)
#define BT_ERR(fmt, ...)

#define L2CAP_CID_A2MP 0

typedef uint16_t u16;

struct l2cap_conn;
struct l2cap_chan;
struct sk_buff {
    void *data;
    unsigned int len;
};

enum {
    L2CAP_CHAN_FIXED,
    L2CAP_CHAN_NORMAL
};

enum {
    L2CAP_MODE_BASIC,
    L2CAP_MODE_ERTM,
    L2CAP_MODE_STREAMING,
    L2CAP_MODE_LE_FLOWCTL,
    L2CAP_MODE_EXT_FLOWCTL
};

enum {
    BT_CONNECTED
};

struct l2cap_chan_ops {
    int (*recv)(struct l2cap_chan *chan, struct sk_buff *skb);
};

struct l2cap_chan {
    u16 scid;
    u16 dcid;
    u16 imtu;
    u16 omtu;
    uint8_t chan_type;
    uint8_t state;
    uint8_t mode;
    struct l2cap_chan_ops *ops;
};

static inline void kfree_skb(struct sk_buff *skb) {
    free(skb->data);
    free(skb);
}

static struct l2cap_chan *l2cap_get_chan_by_scid(struct l2cap_conn *conn, u16 cid);
static struct l2cap_chan *a2mp_channel_create(struct l2cap_conn *conn, struct sk_buff *skb);
static void l2cap_chan_lock(struct l2cap_chan *chan);
static void l2cap_chan_unlock(struct l2cap_chan *chan);
static void l2cap_chan_put(struct l2cap_chan *chan);
static void l2cap_chan_ready(struct l2cap_chan *chan);
static int l2cap_ecred_data_rcv(struct l2cap_chan *chan, struct sk_buff *skb);
static void l2cap_data_rcv(struct l2cap_chan *chan, struct sk_buff *skb);