#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define L2CAP_CONF_OPT_SIZE 2
#define L2CAP_CONF_RFC 0
#define L2CAP_CONF_EWS 1
#define L2CAP_MODE_ERTM 0
#define L2CAP_MODE_STREAMING 1
#define L2CAP_DEFAULT_RETRANS_TO 2000
#define L2CAP_DEFAULT_MONITOR_TO 12000
#define L2CAP_DEFAULT_TX_WINDOW 64
#define FLAG_EXT_CTRL 0

#define BT_DBG(fmt, ...)

typedef uint16_t u16;
typedef uint8_t u8;

struct l2cap_chan {
    unsigned long flags;
    u16 ack_win;
    u16 imtu;
    u8 mode;
    u16 retrans_timeout;
    u16 monitor_timeout;
    u16 mps;
};

struct l2cap_conf_rfc {
    u8 mode;
    u16 retrans_timeout;
    u16 monitor_timeout;
    u16 max_pdu_size;
    u16 txwin_size;
};

static inline u16 cpu_to_le16(u16 val) { return val; }
static inline u16 le16_to_cpu(u16 val) { return val; }
#define min_t(type, x, y) ((type)(x) < (type)(y) ? (type)(x) : (type)(y))
static inline int test_bit(int nr, const unsigned long *addr) { return (*addr >> nr) & 1; }

static inline int l2cap_get_conf_opt(void **ptr, int *type, int *olen, unsigned long *val) {
    return 0;
}