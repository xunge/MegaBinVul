#include <stdint.h>
#include <string.h>

#define __user
#define BT_CONNECTED 2
#define ENOTCONN 107
#define ENOPROTOOPT 92
#define EFAULT 14

#define BT_SECURITY_LOW 0
#define BT_SECURITY_MEDIUM 1
#define BT_SECURITY_HIGH 2

#define RFCOMM_LM 0x0001
#define RFCOMM_LM_AUTH 0x0001
#define RFCOMM_LM_ENCRYPT 0x0002
#define RFCOMM_LM_SECURE 0x0004
#define RFCOMM_LM_MASTER 0x0010
#define RFCOMM_CONNINFO 0x0002

typedef uint32_t u32;

struct socket {
    struct sock *sk;
};

struct sock {
    int sk_state;
};

struct l2cap_conn {
    struct {
        uint16_t handle;
        uint8_t dev_class[3];
    } *hcon;
};

struct hci_conn {
    uint16_t handle;
    uint8_t dev_class[3];
};

struct rfcomm_conninfo {
    uint16_t hci_handle;
    uint8_t dev_class[3];
};

struct rfcomm_pi {
    int sec_level;
    int role_switch;
    struct {
        struct {
            struct socket *sock;
        } *session;
        int defer_setup;
    } *dlc;
};

struct l2cap_pi {
    struct {
        struct l2cap_conn *conn;
    } *chan;
};

#define min_t(type, x, y) ((x) < (y) ? (x) : (y))

static inline struct rfcomm_pi *rfcomm_pi(struct sock *sk) { return (struct rfcomm_pi *)sk; }
static inline struct l2cap_pi *l2cap_pi(struct sock *sk) { return (struct l2cap_pi *)sk; }

static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}
static inline int get_user(int val, int __user *ptr) { return 0; }
static inline int put_user(u32 val, u32 __user *ptr) { return 0; }
static inline int copy_to_user(void __user *to, const void *from, unsigned long n) { return 0; }

#define BT_DBG(fmt, ...)