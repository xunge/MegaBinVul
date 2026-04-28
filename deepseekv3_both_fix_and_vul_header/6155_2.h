#include <string.h>
#include <stddef.h>

#define AF_NFC 39
#define EINVAL 22
#define EBADFD 77
#define ENODEV 19
#define ENOMEM 12
#define EADDRINUSE 98

#define LLCP_CLOSED 0
#define LLCP_BOUND 1
#define LLCP_SAP_MAX 63
#define NFC_LLCP_MAX_SERVICE_NAME 64
#define GFP_KERNEL 0

struct sockaddr {
    unsigned short sa_family;
    char sa_data[14];
};

struct sockaddr_nfc_llcp {
    unsigned short sa_family;
    unsigned int dev_idx;
    unsigned int nfc_protocol;
    unsigned int dsap;
    unsigned int service_name_len;
    char service_name[NFC_LLCP_MAX_SERVICE_NAME];
};

struct socket {
    struct sock *sk;
};

struct sock {
    int sk_state;
};

struct list_head {
    struct list_head *next, *prev;
};

struct nfc_llcp_sock {
    struct nfc_dev *dev;
    struct nfc_llcp_local *local;
    unsigned int nfc_protocol;
    unsigned int service_name_len;
    char *service_name;
    unsigned int ssap;
    unsigned int reserved_ssap;
};

struct nfc_llcp_local {
    struct list_head sockets;
};

struct nfc_dev;

#define pr_debug(fmt, ...)
#define min_t(type, x, y) ((x) < (y) ? (x) : (y))
#define offsetofend(type, member) (offsetof(type, member) + sizeof(((type *)0)->member))

static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}
static inline struct nfc_llcp_sock *nfc_llcp_sock(struct sock *sk) { return NULL; }
static inline struct nfc_dev *nfc_get_device(unsigned int idx) { return NULL; }
static inline void nfc_put_device(struct nfc_dev *dev) {}
static inline struct nfc_llcp_local *nfc_llcp_find_local(struct nfc_dev *dev) { return NULL; }
static inline void nfc_llcp_local_put(struct nfc_llcp_local *local) {}
static inline struct nfc_llcp_local *nfc_llcp_local_get(struct nfc_llcp_local *local) { return NULL; }
static inline unsigned int nfc_llcp_get_sdp_ssap(struct nfc_llcp_local *local, struct nfc_llcp_sock *sock) { return 0; }
static inline void nfc_llcp_sock_link(struct list_head *head, struct sock *sk) {}
static inline void *kmemdup(const void *src, size_t len, int gfp) { return NULL; }
static inline void kfree(const void *objp) {}