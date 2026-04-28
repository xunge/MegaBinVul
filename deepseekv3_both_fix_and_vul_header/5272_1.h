#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define L2CAP_CONF_OPT_SIZE 2
#define L2CAP_MODE_ERTM 1
#define L2CAP_MODE_STREAMING 2
#define L2CAP_CONF_RFC 1
#define L2CAP_CONF_EWS 2
#define L2CAP_DEFAULT_RETRANS_TO 2000
#define L2CAP_DEFAULT_MONITOR_TO 12000
#define L2CAP_DEFAULT_TX_WINDOW 64
#define FLAG_EXT_CTRL 0

#define BT_DBG(fmt, ...)

typedef uint16_t u16;
typedef uint8_t u8;

#define min_t(type, x, y) ((x) < (y) ? (x) : (y))
#define cpu_to_le16(x) (x)
#define le16_to_cpu(x) (x)
#define test_bit(nr, addr) ((*(addr)) & (1UL << (nr)))

struct l2cap_chan {
    unsigned long flags;
    u16 ack_win;
    u16 mode;
    u16 imtu;
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

static int l2cap_get_conf_opt(void **ptr, int *type, int *olen, unsigned long *val);