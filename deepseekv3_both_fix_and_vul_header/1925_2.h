#include <string.h>
#include <stddef.h>

#define __user
#define __u8 unsigned char
#define __u16 unsigned short
#define __u32 unsigned int
#define u32 unsigned int

#define BT_DBG(fmt, ...)

#define L2CAP_OPTIONS 0
#define L2CAP_LM 1
#define L2CAP_CONNINFO 2

#define L2CAP_LM_AUTH 0x01
#define L2CAP_LM_ENCRYPT 0x02
#define L2CAP_LM_SECURE 0x04
#define L2CAP_LM_MASTER 0x08
#define L2CAP_LM_RELIABLE 0x10

#define BT_SECURITY_LOW 0
#define BT_SECURITY_MEDIUM 1
#define BT_SECURITY_HIGH 2

#define BT_CONNECTED 1
#define BT_CONNECT2 2

#define ENOTCONN 107
#define ENOPROTOOPT 92
#define EFAULT 14

struct socket {
    struct sock *sk;
};

struct sock {
    int sk_state;
};

struct l2cap_chan {
    __u16 imtu;
    __u16 omtu;
    __u16 flush_to;
    __u8 mode;
    __u8 fcs;
    __u8 max_tx;
    __u16 tx_win;
    __u8 sec_level;
    int role_switch;
    int force_reliable;
    struct {
        struct {
            int handle;
            __u8 dev_class[3];
        } *hcon;
    } *conn;
};

struct l2cap_pi {
    struct l2cap_chan *chan;
};

struct bt_sk {
    int defer_setup;
};

struct l2cap_options {
    __u16 imtu;
    __u16 omtu;
    __u16 flush_to;
    __u8 mode;
    __u8 fcs;
    __u8 max_tx;
    __u16 txwin_size;
};

struct l2cap_conninfo {
    __u16 hci_handle;
    __u8 dev_class[3];
};

static inline struct l2cap_pi *l2cap_pi(struct sock *sk) { return (struct l2cap_pi *)sk; }
static inline struct bt_sk *bt_sk(struct sock *sk) { return (struct bt_sk *)sk; }

static inline int get_user(int val, int __user *ptr) { return 0; }
static inline int put_user(int val, int __user *ptr) { return 0; }
static inline int copy_to_user(void __user *to, const void *from, unsigned long n) { return 0; }

static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}

#define min_t(type, x, y) ((x) < (y) ? (x) : (y))