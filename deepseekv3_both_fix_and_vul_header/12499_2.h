#include <string.h>
#include <stddef.h>
#include <stdlib.h>

#define AF_NFC 39
#define EINVAL 22
#define EBADFD 77
#define ENODEV 19
#define ENOMEM 12
#define EADDRINUSE 98
#define GFP_KERNEL 0
#define NFC_LLCP_MAX_SERVICE_NAME 64
#define LLCP_CLOSED 0
#define LLCP_BOUND 1
#define LLCP_SAP_MAX 63

struct socket {
    struct sock *sk;
};

struct sock {
    int sk_state;
};

struct sockaddr {
    unsigned short sa_family;
};

struct sockaddr_nfc_llcp {
    unsigned short sa_family;
    unsigned int dev_idx;
    unsigned int nfc_protocol;
    unsigned int dsap;
    unsigned int ssap;
    unsigned char service_name[NFC_LLCP_MAX_SERVICE_NAME];
    unsigned int service_name_len;
};

struct nfc_llcp_sock {
    struct nfc_dev *dev;
    struct nfc_llcp_local *local;
    unsigned int nfc_protocol;
    unsigned int service_name_len;
    unsigned char *service_name;
    unsigned int ssap;
    unsigned int reserved_ssap;
};

struct nfc_llcp_local {
    void *sockets;
};

struct nfc_dev;

#define offsetofend(TYPE, MEMBER) \
    (offsetof(TYPE, MEMBER) + sizeof(((TYPE *)0)->MEMBER))

#define min_t(type, x, y) ((x) < (y) ? (x) : (y))

#define pr_debug(fmt, ...)

static inline void *kmemdup(const void *src, size_t len, int gfp) {
    void *p = malloc(len);
    if (p)
        memcpy(p, src, len);
    return p;
}

static inline void kfree(void *p) {
    free(p);
}

static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}

static inline struct nfc_llcp_sock *nfc_llcp_sock(struct sock *sk) { return NULL; }
static inline struct nfc_dev *nfc_get_device(unsigned int idx) { return NULL; }
static inline void nfc_put_device(struct nfc_dev *dev) {}
static inline struct nfc_llcp_local *nfc_llcp_find_local(struct nfc_dev *dev) { return NULL; }
static inline struct nfc_llcp_local *nfc_llcp_local_get(struct nfc_llcp_local *local) { return NULL; }
static inline void nfc_llcp_local_put(struct nfc_llcp_local *local) {}
static inline unsigned int nfc_llcp_get_sdp_ssap(struct nfc_llcp_local *local, struct nfc_llcp_sock *sock) { return 0; }
static inline void nfc_llcp_sock_link(void *list, struct sock *sk) {}