#include <sys/socket.h>
#include <string.h>
#include <stddef.h>
#include <linux/types.h>

#define LLCP_CLOSED 0
#define LLCP_BOUND 1
#define EINVAL 22
#define EBADFD 77
#define ENODEV 19

struct socket {
    struct sock *sk;
};

struct sock {
    int sk_state;
};

struct nfc_llcp_sock {
    struct nfc_dev *dev;
    struct nfc_llcp_local *local;
    int nfc_protocol;
};

struct nfc_llcp_local {
    void *raw_sockets; // Placeholder for list_head
};

struct nfc_dev {
    // minimal definition
};

struct sockaddr_nfc_llcp {
    unsigned short sa_family;
    unsigned int dev_idx;
    int nfc_protocol;
};

#define offsetofend(TYPE, MEMBER) \
    (offsetof(TYPE, MEMBER) + sizeof(((TYPE *)0)->MEMBER))

#define min_t(type, x, y) ((x) < (y) ? (x) : (y))

static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}
static inline struct nfc_llcp_sock *nfc_llcp_sock(struct sock *sk) { return NULL; }
static inline struct nfc_dev *nfc_get_device(unsigned int idx) { return NULL; }
static inline void nfc_put_device(struct nfc_dev *dev) {}
static inline struct nfc_llcp_local *nfc_llcp_find_local(struct nfc_dev *dev) { return NULL; }
static inline struct nfc_llcp_local *nfc_llcp_local_get(struct nfc_llcp_local *local) { return NULL; }
static inline void nfc_llcp_sock_link(void *list, struct sock *sk) {}

#define pr_debug(fmt, ...)