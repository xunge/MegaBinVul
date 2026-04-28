#include <sys/socket.h>
#include <errno.h>

struct sockaddr_hci {
    unsigned short hci_family;
    unsigned short hci_dev;
    unsigned short hci_channel;
};

struct socket {
    struct sock *sk;
};

struct sock;

struct hci_dev {
    unsigned short id;
};

struct hci_pi {
    struct hci_dev *hdev;
};

static inline struct hci_pi *hci_pi(struct sock *sk) {
    return (struct hci_pi *)sk;
}

#define BT_DBG(fmt, ...)

static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}