#include <stddef.h>
#include <string.h>
#include <linux/types.h>
#include <endian.h>

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
#define L2CAP_CONF_UNKNOWN 4
#define L2CAP_CONF_UNACCEPT 2
#define L2CAP_CONF_PENDING 1
#define L2CAP_FCS_NONE 0
#define L2CAP_FC_A2MP 0x80
#define L2CAP_DEFAULT_EXT_WINDOW 64
#define L2CAP_DEFAULT_MIN_MTU 48
#define L2CAP_DEFAULT_TX_WINDOW 63
#define L2CAP_EXT_HDR_SIZE 4
#define L2CAP_SDULEN_SIZE 2
#define L2CAP_FCS_SIZE 2
#define L2CAP_SERV_NOTRAFIC 0

#define CONF_RECV_NO_FCS 0
#define CONF_EWS_RECV 1
#define CONF_STATE2_DEVICE 2
#define CONF_MTU_DONE 3
#define CONF_MODE_DONE 4
#define CONF_LOC_CONF_PEND 5
#define CONF_OUTPUT_DONE 6

#define FLAG_EXT_CTRL 0
#define FLAG_EFS_ENABLE 1

#define ECONNREFUSED 111

#define BT_DBG(fmt, ...)

struct l2cap_chan {
    void *conf_req;
    int conf_len;
    unsigned long conf_state;
    unsigned long flags;
    int mode;
    int num_conf_rsp;
    int num_conf_req;
    int flush_to;
    int tx_win_max;
    int remote_tx_win;
    int omtu;
    int local_stype;
    int remote_id;
    int remote_stype;
    int remote_msdu;
    int remote_flush_to;
    int remote_acc_lat;
    int remote_sdu_itime;
    int remote_mps;
    int remote_max_tx;
    int fcs;
    int dcid;
    struct l2cap_conn *conn;
};

struct l2cap_conn {
    int mtu;
    int local_fixed_chan;
    int feat_mask;
};

struct l2cap_conf_rsp {
    void *data;
    int scid;
    int result;
    int flags;
};

struct l2cap_conf_rfc {
    int mode;
    int txwin_size;
    int max_transmit;
    int max_pdu_size;
};

struct l2cap_conf_efs {
    int id;
    int stype;
    int msdu;
    int flush_to;
    int acc_lat;
    int sdu_itime;
};

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

#define min_t(type, x, y) ({ type __x = (x); type __y = (y); __x < __y ? __x : __y; })
#define cpu_to_le16(x) htole16(x)
#define le16_to_cpu(x) le16toh(x)
#define cpu_to_le32(x) htole32(x)
#define le32_to_cpu(x) le32toh(x)

static inline void set_bit(int nr, volatile unsigned long *addr)
{
    *addr |= (1UL << nr);
}

static inline int test_bit(int nr, volatile unsigned long *addr)
{
    return (*addr & (1UL << nr)) != 0;
}

static int l2cap_get_conf_opt(void **ptr, int *type, int *olen, unsigned long *val);
static int l2cap_select_mode(int mode, int feat_mask);
static int __l2cap_efs_supported(struct l2cap_conn *conn);
static void __l2cap_set_ertm_timeouts(struct l2cap_chan *chan, struct l2cap_conf_rfc *rfc);
static void l2cap_add_conf_opt(void **ptr, int type, int len, unsigned long val, int size);