#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define L2CAP_CONF_OPT_SIZE 2
#define L2CAP_DEFAULT_MIN_MTU 48
#define L2CAP_CONF_UNACCEPT 1
#define L2CAP_CONF_PENDING 2
#define L2CAP_CONF_SUCCESS 0
#define L2CAP_MODE_BASIC 0
#define L2CAP_MODE_ERTM 1
#define L2CAP_MODE_STREAMING 2
#define L2CAP_FCS_NONE 0
#define L2CAP_SERV_NOTRAFIC 0
#define CONF_STATE2_DEVICE 0
#define CONF_RECV_NO_FCS 0
#define FLAG_EXT_CTRL 0
#define FLAG_EFS_ENABLE 0
#define ECONNREFUSED 111

#define L2CAP_CONF_MTU 0x01
#define L2CAP_CONF_FLUSH_TO 0x02
#define L2CAP_CONF_RFC 0x03
#define L2CAP_CONF_EWS 0x04
#define L2CAP_CONF_EFS 0x05
#define L2CAP_CONF_FCS 0x06

typedef uint16_t u16;

struct l2cap_chan {
    int imtu;
    int flush_to;
    int mode;
    int fcs;
    u16 ack_win;
    u16 tx_win;
    int local_stype;
    u16 retrans_timeout;
    u16 monitor_timeout;
    u16 mps;
    u16 local_msdu;
    uint32_t local_sdu_itime;
    uint32_t local_acc_lat;
    uint32_t local_flush_to;
    u16 dcid;
    unsigned long conf_state;
    unsigned long flags;
};

struct l2cap_conf_req {
    void *data;
    u16 dcid;
    u16 flags;
};

struct l2cap_conf_rfc {
    int mode;
    u16 retrans_timeout;
    u16 monitor_timeout;
    u16 max_pdu_size;
    u16 txwin_size;
};

struct l2cap_conf_efs {
    int stype;
    u16 msdu;
    uint32_t sdu_itime;
    uint32_t acc_lat;
    uint32_t flush_to;
};

#define BT_DBG(fmt, ...)
#define min_t(type, x, y) ((x) < (y) ? (x) : (y))
#define test_bit(nr, addr) (0)
#define set_bit(nr, addr)
#define cpu_to_le16(x) (x)
#define le16_to_cpu(x) (x)
#define le32_to_cpu(x) (x)

static int l2cap_get_conf_opt(void **ptr, int *type, int *olen, unsigned long *val);
static void l2cap_add_conf_opt(void **ptr, int type, int len, unsigned long val, int size);