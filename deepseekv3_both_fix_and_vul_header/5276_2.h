#include <stddef.h>
#include <string.h>
#include <stdint.h>

typedef uint16_t u16;
typedef uint32_t u32;

#define L2CAP_CONF_OPT_SIZE 2
#define L2CAP_DEFAULT_MIN_MTU 48
#define L2CAP_CONF_UNACCEPT 1
#define L2CAP_CONF_PENDING 2
#define L2CAP_CONF_SUCCESS 3
#define L2CAP_FCS_NONE 0
#define L2CAP_MODE_BASIC 0
#define L2CAP_MODE_ERTM 1
#define L2CAP_MODE_STREAMING 2
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
    u32 local_sdu_itime;
    u32 local_acc_lat;
    u32 local_flush_to;
    unsigned long conf_state;
    unsigned long flags;
    u16 dcid;
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
    u32 sdu_itime;
    u32 acc_lat;
    u32 flush_to;
};

#define BT_DBG(fmt, ...)

static inline int l2cap_get_conf_opt(void **ptr, int *type, int *olen, unsigned long *val) { return 0; }
static inline void l2cap_add_conf_opt(void **ptr, int type, int len, unsigned long val, int size) {}
static inline int test_bit(int nr, const volatile unsigned long *addr) { return 0; }
static inline void set_bit(int nr, volatile unsigned long *addr) {}
static inline u16 cpu_to_le16(u16 val) { return val; }
static inline u16 le16_to_cpu(u16 val) { return val; }
static inline u32 le32_to_cpu(u32 val) { return val; }
#define min_t(type, x, y) ((x) < (y) ? (x) : (y))