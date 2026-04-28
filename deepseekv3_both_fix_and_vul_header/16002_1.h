#include <stdint.h>
#include <string.h>
#include <errno.h>

typedef uint16_t u16;
typedef uint8_t u8;

#define BT_DBG(fmt, ...)

#define L2CAP_CONF_RSP 0x05
#define L2CAP_CONF_REQ 0x04
#define L2CAP_CONF_REJECT 0x0001
#define L2CAP_CONF_SUCCESS 0x0000
#define L2CAP_CONF_MAX_CONF_RSP 4
#define L2CAP_CONF_FLAG_CONTINUATION 0x0001

#define CONF_OUTPUT_DONE 0
#define CONF_INPUT_DONE 1
#define CONF_REQ_SENT 2
#define CONF_REM_CONF_PEND 3
#define CONF_LOC_CONF_PEND 4

enum {
    BT_CONFIG,
    BT_CONNECT2,
    BT_CONNECTED
};

enum {
    L2CAP_MODE_ERTM,
    L2CAP_MODE_STREAMING
};

struct l2cap_conn;
struct l2cap_cmd_hdr {
    u8 ident;
};
struct l2cap_conf_req {
    u16 dcid;
    u16 flags;
    u8 data[0];
};
struct l2cap_chan {
    u16 scid;
    u16 dcid;
    u8 state;
    u8 conf_req[64];
    int conf_len;
    u8 ident;
    u8 num_conf_rsp;
    u8 num_conf_req;
    u8 mode;
    unsigned long conf_state;
    struct l2cap_conn *hs_hcon;
};

static inline u16 __le16_to_cpu(u16 val) { return val; }

static inline struct l2cap_chan *l2cap_get_chan_by_scid(struct l2cap_conn *conn, u16 dcid) { return NULL; }
static inline void cmd_reject_invalid_cid(struct l2cap_conn *conn, u8 ident, u16 scid, u16 dcid) {}
static inline void l2cap_send_cmd(struct l2cap_conn *conn, u8 ident, u8 code, int len, u8 *data) {}
static inline int l2cap_build_conf_rsp(struct l2cap_chan *chan, u8 *rsp, u16 result, u16 flags) { return 0; }
static inline int l2cap_parse_conf_req(struct l2cap_chan *chan, u8 *rsp, int size) { return 0; }
static inline void l2cap_send_disconn_req(struct l2cap_chan *chan, int err) {}
static inline void set_default_fcs(struct l2cap_chan *chan) {}
static inline int l2cap_ertm_init(struct l2cap_chan *chan) { return 0; }
static inline void l2cap_chan_ready(struct l2cap_chan *chan) {}
static inline u8 l2cap_get_ident(struct l2cap_conn *conn) { return 0; }
static inline int l2cap_build_conf_req(struct l2cap_chan *chan, u8 *buf, int size) { return 0; }
static inline void l2cap_send_efs_conf_rsp(struct l2cap_chan *chan, u8 *rsp, u8 ident, u16 flags) {}
static inline void l2cap_chan_unlock(struct l2cap_chan *chan) {}
static inline void l2cap_chan_put(struct l2cap_chan *chan) {}
static inline int test_bit(int nr, const volatile unsigned long *addr) { return 0; }
static inline int test_and_set_bit(int nr, volatile unsigned long *addr) { return 0; }