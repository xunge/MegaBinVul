#include <stddef.h>
#include <string.h>
#include <errno.h>

#define __user
#define BT_CONNECTED 2
#define SCO_OPTIONS 1
#define SCO_CONNINFO 2
#define ENOTCONN 107
#define ENOPROTOOPT 92
#define EFAULT 14

#define BT_DBG(fmt, ...)

struct socket {
    struct sock *sk;
};

struct sock {
    int sk_state;
};

struct sco_options {
    unsigned short mtu;
};

struct sco_conninfo {
    unsigned short hci_handle;
    unsigned char dev_class[3];
};

struct sco_pinfo {
    struct sco_conn *conn;
};

struct sco_conn {
    unsigned short mtu;
    struct hci_conn *hcon;
};

struct hci_conn {
    unsigned short handle;
    unsigned char dev_class[3];
};

static inline struct sco_pinfo *sco_pi(struct sock *sk) {
    return (struct sco_pinfo *)sk;
}

static inline int get_user(int val, int __user *ptr) {
    return 0;
}

static inline int copy_to_user(void __user *to, const void *from, unsigned long n) {
    return 0;
}

static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}

#define min_t(type, x, y) ((x) < (y) ? (x) : (y))