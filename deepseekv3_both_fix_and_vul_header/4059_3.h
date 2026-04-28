#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define LLCP_CONNECTED 1
#define LLCP_CONNECTING 2
#define LLCP_SAP_MAX 63
#define LLCP_SAP_SDP 1
#define NFC_LLCP_MAX_SERVICE_NAME 64
#define NFC_RF_INITIATOR 0
#define O_NONBLOCK 04000
#define GFP_KERNEL 0
#define EINVAL 22
#define EISCONN 106
#define EINPROGRESS 115
#define ENODEV 19
#define ENOLINK 67
#define ENOMEM 12

typedef uint8_t u8;
typedef uint32_t u32;
typedef unsigned int gfp_t;

struct list_head {
    struct list_head *next, *prev;
};

struct device {
    struct list_head list;
    int dummy;
};

struct nfc_llcp_sock {
    struct nfc_dev *dev;
    struct nfc_llcp_local *local;
    u8 ssap;
    u8 dsap;
    u8 reserved_ssap;
    u8 nfc_protocol;
    unsigned int service_name_len;
    char *service_name;
};

struct nfc_llcp_local {
    u8 target_idx;
    u8 rf_mode;
    struct list_head connecting_sockets;
};

struct nfc_dev {
    struct device dev;
    bool dep_link_up;
};

struct socket {
    struct sock *sk;
};

struct sock {
    unsigned int sk_state;
};

struct sockaddr_nfc_llcp {
    sa_family_t sa_family;
    u32 dev_idx;
    u32 target_idx;
    u32 nfc_protocol;
    u32 dsap;
    unsigned int service_name_len;
    char service_name[];
};

static inline void device_lock(struct device *dev) {}
static inline void device_unlock(struct device *dev) {}

static inline void *kmemdup(const void *src, size_t len, gfp_t gfp) {
    void *p = malloc(len);
    if (p)
        memcpy(p, src, len);
    return p;
}

#define pr_debug(fmt, ...) 

#define min_t(type, x, y) ({ \
    type __min1 = (x); \
    type __min2 = (y); \
    __min1 < __min2 ? __min1 : __min2; })

#define kfree free

extern struct nfc_llcp_sock *nfc_llcp_sock(struct sock *sk);
extern struct nfc_dev *nfc_get_device(u32 idx);
extern void nfc_put_device(struct nfc_dev *dev);
extern struct nfc_llcp_local *nfc_llcp_find_local(struct nfc_dev *dev);
extern struct nfc_llcp_local *nfc_llcp_local_get(struct nfc_llcp_local *local);
extern void nfc_llcp_local_put(struct nfc_llcp_local *local);
extern u8 nfc_llcp_get_local_ssap(struct nfc_llcp_local *local);
extern void nfc_llcp_put_ssap(struct nfc_llcp_local *local, u8 ssap);
extern void nfc_llcp_sock_link(struct list_head *head, struct sock *sk);
extern void nfc_llcp_sock_unlink(struct list_head *head, struct sock *sk);
extern int nfc_llcp_send_connect(struct nfc_llcp_sock *sock);
extern void lock_sock(struct sock *sk);
extern void release_sock(struct sock *sk);
extern long sock_wait_state(struct sock *sk, int state, long timeo);
extern long sock_sndtimeo(struct sock *sk, int noblock);