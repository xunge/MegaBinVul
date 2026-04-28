#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <pthread.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

#define __packed __attribute__((packed))
#define __le16 uint16_t
#define __le16_to_cpu(x) (x)
#define cpu_to_le16(x) (x)

#define L2CAP_ECRED_MAX_CID 5
#define L2CAP_ECRED_MIN_MTU 64
#define L2CAP_ECRED_MIN_MPS 64
#define L2CAP_PSM_LE_DYN_END 0x00FF
#define L2CAP_CID_DYN_START 0x0040
#define L2CAP_CID_LE_DYN_END 0x007F

#define L2CAP_CR_LE_INVALID_PARAMS 0x0001
#define L2CAP_CR_LE_UNACCEPT_PARAMS 0x0002
#define L2CAP_CR_LE_BAD_PSM 0x0003
#define L2CAP_CR_LE_AUTHENTICATION 0x0005
#define L2CAP_CR_LE_SUCCESS 0x0000
#define L2CAP_CR_LE_INVALID_SCID 0x0006
#define L2CAP_CR_LE_SCID_IN_USE 0x0007
#define L2CAP_CR_LE_NO_MEM 0x0004

#define BT_LISTEN 1
#define LE_LINK 2
#define BT_CONNECT2 3
#define L2CAP_ECRED_CONN_RSP 0

#define FLAG_DEFER_SETUP 0
#define SMP_ALLOW_STK 0

#define EINVAL 22

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

struct l2cap_cmd_hdr {
    u8 ident;
};

struct l2cap_ecred_conn_req {
    __le16 psm;
    __le16 mtu;
    __le16 mps;
    __le16 credits;
    __le16 scid[];
};

struct l2cap_ecred_conn_rsp {
    __le16 mtu;
    __le16 mps;
    __le16 credits;
    __le16 result;
};

struct bdaddr_t {
    u8 b[6];
};

struct hcon {
    struct bdaddr_t src;
    struct bdaddr_t dst;
};

struct l2cap_chan {
    struct bdaddr_t src;
    struct bdaddr_t dst;
    int src_type;
    int dst_type;
    __le16 psm;
    u16 dcid;
    u16 scid;
    u16 omtu;
    u16 imtu;
    u16 mps;
    u16 remote_mps;
    u16 rx_credits;
    u8 ident;
    int sec_level;
    unsigned long flags;
    struct {
        struct l2cap_chan* (*new_connection)(struct l2cap_chan*);
        void (*defer)(struct l2cap_chan*);
        int (*get_sndtimeo)(struct l2cap_chan*);
    } *ops;
};

struct l2cap_conn {
    struct hcon *hcon;
    pthread_mutex_t chan_lock;
};

static inline void bacpy(struct bdaddr_t *dst, const struct bdaddr_t *src) {}
static inline int bdaddr_src_type(struct hcon *hcon) { return 0; }
static inline int bdaddr_dst_type(struct hcon *hcon) { return 0; }
static inline bool smp_sufficient_security(struct hcon *hcon, int sec_level, int flags) { return true; }
static inline struct l2cap_chan *l2cap_global_chan_by_psm(int state, __le16 psm, struct bdaddr_t *src, struct bdaddr_t *dst, int link_type) { return NULL; }
static inline void l2cap_chan_lock(struct l2cap_chan *chan) {}
static inline void l2cap_chan_unlock(struct l2cap_chan *chan) {}
static inline void l2cap_chan_put(struct l2cap_chan *chan) {}
static inline struct l2cap_chan *__l2cap_get_chan_by_dcid(struct l2cap_conn *conn, u16 scid) { return NULL; }
static inline void __l2cap_chan_add(struct l2cap_conn *conn, struct l2cap_chan *chan) {}
static inline void l2cap_ecred_init(struct l2cap_chan *chan, u16 credits) {}
static inline void __set_chan_timer(struct l2cap_chan *chan, int timeout) {}
static inline void l2cap_state_change(struct l2cap_chan *chan, int state) {}
static inline void l2cap_chan_ready(struct l2cap_chan *chan) {}
static inline void l2cap_send_cmd(struct l2cap_conn *conn, u8 ident, u8 code, u16 len, void *data) {}
static inline int test_bit(int nr, const volatile unsigned long *addr) { return 0; }

#define BT_DBG(fmt, ...)

static bool enable_ecred = false;