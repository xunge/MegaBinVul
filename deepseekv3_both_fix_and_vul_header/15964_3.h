#include <stdint.h>
#include <string.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint16_t __le16;

struct mutex {};

#define BT_LISTEN 1
#define LE_LINK 2
#define L2CAP_PSM_LE_DYN_END 0x00ff
#define L2CAP_CID_DYN_START 0x0040
#define L2CAP_CID_LE_DYN_END 0x007f
#define L2CAP_CR_LE_BAD_PSM 0x0002
#define L2CAP_CR_LE_AUTHENTICATION 0x0005
#define L2CAP_CR_LE_INVALID_SCID 0x0006
#define L2CAP_CR_LE_SCID_IN_USE 0x0007
#define L2CAP_CR_LE_NO_MEM 0x0004
#define L2CAP_CR_LE_SUCCESS 0x0000
#define L2CAP_CR_PEND 0x0001
#define FLAG_DEFER_SETUP 0
#define BT_CONNECT2 2
#define EPROTO 71
#define SMP_ALLOW_STK 0
#define L2CAP_LE_CONN_RSP 0x15

struct bdaddr_t {
    u8 b[6];
};

struct hci_conn {
    struct bdaddr_t src;
    struct bdaddr_t dst;
};

struct l2cap_conn {
    struct hci_conn *hcon;
    struct mutex chan_lock;
};

struct l2cap_cmd_hdr {
    u8 ident;
};

struct l2cap_le_conn_req {
    __le16 scid;
    __le16 mtu;
    __le16 mps;
    __le16 credits;
    __le16 psm;
};

struct l2cap_chan_ops {
    struct l2cap_chan *(*new_connection)(struct l2cap_chan *);
    void (*defer)(struct l2cap_chan *);
    unsigned long (*get_sndtimeo)(struct l2cap_chan *);
};

struct l2cap_chan {
    struct bdaddr_t src;
    struct bdaddr_t dst;
    u8 src_type;
    u8 dst_type;
    u16 scid;
    u16 dcid;
    u16 imtu;
    u16 mps;
    u16 omtu;
    u16 remote_mps;
    u16 rx_credits;
    __le16 psm;
    unsigned long flags;
    struct l2cap_chan_ops *ops;
    u8 ident;
    u8 sec_level;
};

struct l2cap_le_conn_rsp {
    __le16 mtu;
    __le16 mps;
    __le16 dcid;
    __le16 credits;
    __le16 result;
};

static inline u16 __le16_to_cpu(__le16 val) { return val; }
static inline __le16 cpu_to_le16(u16 val) { return val; }
static inline void bacpy(void *dst, const void *src) { memcpy(dst, src, 6); }
static inline u8 bdaddr_src_type(struct hci_conn *hcon) { return 0; }
static inline u8 bdaddr_dst_type(struct hci_conn *hcon) { return 0; }
static inline void mutex_lock(struct mutex *lock) {}
static inline void mutex_unlock(struct mutex *lock) {}
static inline int test_bit(int nr, const unsigned long *addr) { return 0; }

#define BT_DBG(fmt, ...)

static struct l2cap_chan *l2cap_global_chan_by_psm(int state, __le16 psm, void *src, void *dst, int link_type) { return NULL; }
static int smp_sufficient_security(struct hci_conn *hcon, int sec_level, int flags) { return 1; }
static struct l2cap_chan *__l2cap_get_chan_by_dcid(struct l2cap_conn *conn, u16 scid) { return NULL; }
static void l2cap_le_flowctl_init(struct l2cap_chan *chan, u16 credits) {}
static void __set_chan_timer(struct l2cap_chan *chan, unsigned long timeout) {}
static void l2cap_state_change(struct l2cap_chan *chan, int state) {}
static void l2cap_chan_ready(struct l2cap_chan *chan) {}
static void l2cap_send_cmd(struct l2cap_conn *conn, u8 ident, u8 code, u16 len, void *data) {}
static void l2cap_chan_lock(struct l2cap_chan *chan) {}
static void l2cap_chan_unlock(struct l2cap_chan *chan) {}
static void l2cap_chan_put(struct l2cap_chan *chan) {}
static void __l2cap_chan_add(struct l2cap_conn *conn, struct l2cap_chan *chan) {}