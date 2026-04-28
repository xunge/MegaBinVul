#include <stdint.h>
#include <string.h>

typedef uint16_t u16;
typedef uint8_t u8;

struct l2cap_conn;
struct l2cap_cmd_hdr {
    u8 ident;
};
struct l2cap_conf_req {
    u16 dcid;
    u16 flags;
    u8 data[];
};
struct l2cap_chan {
    struct sock *sk;
    u16 conf_len;
    u8 conf_req[64];
    u16 num_conf_rsp;
    u8 conf_state;
    u16 next_tx_seq;
    u16 expected_tx_seq;
    u8 mode;
    u16 num_conf_req;
    void *tx_q;
};
struct sock {
    u8 sk_state;
};
struct l2cap_cmd_rej {
    u16 reason;
};

#define BT_DBG(fmt, ...)
#define ENOENT 2
#define ECONNRESET 104
#define __le16_to_cpu(x) (x)
#define cpu_to_le16(x) (x)

#define L2CAP_COMMAND_REJ 0x01
#define L2CAP_CONF_RSP 0x05
#define L2CAP_CONF_REJECT 0x01
#define L2CAP_CONF_SUCCESS 0x00
#define L2CAP_CONF_REQ 0x04

#define BT_CONFIG 1
#define BT_CONNECTED 2

#define L2CAP_CONF_OUTPUT_DONE 0x01
#define L2CAP_CONF_INPUT_DONE 0x02
#define L2CAP_CONF_REQ_SENT 0x04

#define L2CAP_MODE_ERTM 3

static inline int l2cap_get_chan_by_scid(struct l2cap_conn *conn, u16 dcid) { return 0; }
static inline void l2cap_send_cmd(struct l2cap_conn *conn, u8 ident, u8 code, u16 len, void *data) {}
static inline int l2cap_build_conf_rsp(struct l2cap_chan *chan, u8 *rsp, u8 result, u16 flags) { return 0; }
static inline int l2cap_parse_conf_req(struct l2cap_chan *chan, u8 *rsp) { return 0; }
static inline void l2cap_send_disconn_req(struct l2cap_conn *conn, struct l2cap_chan *chan, int err) {}
static inline void set_default_fcs(struct l2cap_chan *chan) {}
static inline void skb_queue_head_init(void *q) {}
static inline void l2cap_ertm_init(struct l2cap_chan *chan) {}
static inline void l2cap_chan_ready(struct sock *sk) {}
static inline u8 l2cap_get_ident(struct l2cap_conn *conn) { return 0; }
static inline int l2cap_build_conf_req(struct l2cap_chan *chan, u8 *buf) { return 0; }
static inline void bh_unlock_sock(struct sock *sk) {}