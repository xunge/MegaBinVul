#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

#define L2CAP_CONF_OPT_SIZE 2
#define L2CAP_CONF_HINT 0x80
#define L2CAP_CONF_MASK 0x7f
#define L2CAP_CONF_MTU 0x01
#define L2CAP_CONF_FLUSH_TO 0x02
#define L2CAP_CONF_QOS 0x03
#define L2CAP_CONF_RFC 0x04
#define L2CAP_CONF_FCS 0x05
#define L2CAP_CONF_EFS 0x06
#define L2CAP_CONF_EWS 0x07

#define L2CAP_MODE_BASIC 0
#define L2CAP_MODE_STREAMING 1
#define L2CAP_MODE_ERTM 2
#define L2CAP_DEFAULT_MTU 672
#define L2CAP_CONF_SUCCESS 0
#define L2CAP_CONF_UNKNOWN 1
#define L2CAP_CONF_UNACCEPT 2
#define L2CAP_CONF_PENDING 3
#define L2CAP_FCS_NONE 0
#define L2CAP_FC_A2MP 0x80
#define L2CAP_DEFAULT_EXT_WINDOW 64
#define L2CAP_DEFAULT_MIN_MTU 48
#define L2CAP_EXT_HDR_SIZE 6
#define L2CAP_SDULEN_SIZE 2
#define L2CAP_FCS_SIZE 2
#define L2CAP_DEFAULT_TX_WINDOW 63
#define L2CAP_SERV_NOTRAFIC 0
#define ECONNREFUSED 111

#define CONF_RECV_NO_FCS 0
#define CONF_EWS_RECV 1
#define CONF_STATE2_DEVICE 2
#define CONF_MTU_DONE 3
#define CONF_MODE_DONE 4
#define CONF_LOC_CONF_PEND 5
#define CONF_OUTPUT_DONE 6
#define FLAG_EXT_CTRL 0
#define FLAG_EFS_ENABLE 1

#define BT_DBG(fmt, ...)

struct l2cap_chan;
struct l2cap_conn {
    u16 mtu;
    u32 feat_mask;
    u8 local_fixed_chan;
};

struct l2cap_conf_rsp {
    void *data;
    u16 scid;
    u16 result;
    u16 flags;
};

struct l2cap_conf_rfc {
    u8 mode;
    u8 txwin_size;
    u8 max_transmit;
    u16 max_pdu_size;
};

struct l2cap_conf_efs {
    u8 id;
    u8 stype;
    u16 msdu;
    u32 flush_to;
    u32 acc_lat;
    u32 sdu_itime;
};

struct l2cap_chan {
    struct l2cap_conn *conn;
    void *conf_req;
    int conf_len;
    unsigned long conf_state;
    unsigned long flags;
    u16 dcid;
    u16 omtu;
    u16 tx_win_max;
    u16 remote_tx_win;
    u8 mode;
    u8 fcs;
    u8 num_conf_rsp;
    u8 num_conf_req;
    u8 local_stype;
    u8 remote_id;
    u8 remote_stype;
    u16 remote_msdu;
    u32 flush_to;
    u32 remote_flush_to;
    u32 remote_acc_lat;
    u32 remote_sdu_itime;
    u16 remote_mps;
    u8 remote_max_tx;
};

static inline void set_bit(int nr, volatile unsigned long *addr)
{
    *addr |= (1UL << nr);
}

static inline int test_bit(int nr, const volatile unsigned long *addr)
{
    return ((1UL << nr) & *addr) != 0;
}

#define min_t(type, x, y) ({ \
    type __min1 = (x); \
    type __min2 = (y); \
    __min1 < __min2 ? __min1 : __min2; \
})

static inline int l2cap_get_conf_opt(void **ptr, int *type, int *olen, unsigned long *val);
static inline void l2cap_add_conf_opt(void **ptr, u8 type, size_t len, unsigned long val, size_t size);
static inline int __l2cap_efs_supported(struct l2cap_conn *conn);
static inline void __l2cap_set_ertm_timeouts(struct l2cap_chan *chan, struct l2cap_conf_rfc *rfc);
static inline u8 l2cap_select_mode(u8 mode, u32 feat_mask);