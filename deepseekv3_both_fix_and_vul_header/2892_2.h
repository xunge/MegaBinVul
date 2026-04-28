#include <sys/socket.h>
#include <stdint.h>
#include <stddef.h>

struct socket {
    struct sock *sk;
};

struct sock;

typedef struct {
    uint8_t b[6];
} bdaddr_t;

struct sockaddr_rc {
    uint16_t rc_family;
    bdaddr_t rc_bdaddr;
    uint8_t rc_channel;
};

struct rfcomm_pi {
    uint8_t channel;
};

struct bt_sk {
    bdaddr_t src;
    bdaddr_t dst;
};

#define BT_DBG(fmt, ...)

static inline struct rfcomm_pi *rfcomm_pi(struct sock *sk) { return NULL; }
static inline struct bt_sk *bt_sk(struct sock *sk) { return NULL; }
static inline void bacpy(bdaddr_t *dst, const bdaddr_t *src) { *dst = *src; }