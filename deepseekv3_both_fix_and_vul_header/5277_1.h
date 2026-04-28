#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

#define BT_DBG(fmt, ...)

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
#define L2CAP_MODE_ERTM 1
#define L2CAP_MODE_STREAMING 2
#define L2CAP_DEFAULT_MTU 672
#define L2CAP_CONF_SUCCESS 0
#define L2CAP_CONF_UNKNOWN 1
#define L2CAP_CONF_UNACCEPT 2
#define L2CAP_CONF_PENDING 3
#define L2CAP_FCS_NONE 0
#define L2CAP_FC_A2MP 0x80
#define L2CAP_DEFAULT_EXT_WINDOW 64
#define L2CAP_DEFAULT_MIN_MTU 48
#define L2CAP_DEFAULT_TX_WINDOW 63
#define L2CAP_EXT_HDR_SIZE 6
#define L2CAP_SDULEN_SIZE 2
#define L2CAP_FCS_SIZE 2
#define L2CAP_SERV_NOTRAFIC 0
#define ECONNREFUSED 111

struct l2cap_chan {
    void *conf_req;
    int conf_len;
    unsigned long conf_state;
    unsigned long flags;
    int mode;
    int num_conf_rsp;
    int num_conf_req;
    int flush_to;
    int omtu;
    int tx_win_max;
    int remote_tx_win;
    int remote_max_tx;
    int remote_mps;
    int remote_id;
    int remote_stype;
    int remote_msdu;
    int remote_flush_to;
    int remote_acc_lat;
    int remote_sdu_itime;
    int local_stype;
    int dcid;
    int fcs;
    struct {
        int local_fixed_chan;
        int feat_mask;
        int mtu;
    } *conn;
};

struct l2cap_conf_rsp {
    void *data;
    uint16_t scid;
    uint16_t result;
    uint16_t flags;
};

struct l2cap_conf_rfc {
    int mode;
    int txwin_size;
    int max_transmit;
    uint16_t max_pdu_size;
};

struct l2cap_conf_efs {
    int id;
    int stype;
    uint16_t msdu;
    uint32_t flush_to;
    uint32_t acc_lat;
    uint32_t sdu_itime;
};

enum {
    CONF_RECV_NO_FCS,
    CONF_STATE2_DEVICE,
    CONF_EWS_RECV,
    CONF_MTU_DONE,
    CONF_MODE_DONE,
    CONF_OUTPUT_DONE,
    CONF_LOC_CONF_PEND,
    FLAG_EXT_CTRL,
    FLAG_EFS_ENABLE
};

#define min_t(type, x, y) ((x) < (y) ? (x) : (y))
#define le16_to_cpu(x) le16toh(x)
#define le32_to_cpu(x) le32toh(x)
#define cpu_to_le16(x) htole16(x)

static inline int l2cap_get_conf_opt(void **ptr, int *type, int *olen, unsigned long *val) { return 0; }
static inline void l2cap_add_conf_opt(void **ptr, int type, int len, unsigned long val, int size) {}
static inline int l2cap_select_mode(int mode, int feat_mask) { return 0; }
static inline int __l2cap_efs_supported(void *conn) { return 0; }
static inline void __l2cap_set_ertm_timeouts(struct l2cap_chan *chan, struct l2cap_conf_rfc *rfc) {}
static inline void set_bit(int nr, volatile unsigned long *addr) {}
static inline int test_bit(int nr, volatile unsigned long *addr) { return 0; }