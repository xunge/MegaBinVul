#include <sys/socket.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t b[6];
} bdaddr_t;

struct socket {
    struct sock *sk;
};

struct sock;
struct l2cap_chan {
    uint16_t psm;
    uint16_t sport;
    uint16_t dcid;
    uint16_t scid;
};
struct l2cap_pinfo {
    struct l2cap_chan *chan;
};
struct bt_sk {
    bdaddr_t src;
    bdaddr_t dst;
};
struct sockaddr_l2 {
    uint16_t l2_psm;
    bdaddr_t l2_bdaddr;
    uint16_t l2_cid;
};

#define BT_DBG(fmt, ...)
#define l2cap_pi(sk) ((struct l2cap_pinfo *)sk)
#define bt_sk(sk) ((struct bt_sk *)sk)
#define cpu_to_le16(x) (x)
#define bacpy(dest, src) memcpy(dest, src, sizeof(bdaddr_t))