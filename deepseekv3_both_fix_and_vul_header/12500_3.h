#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

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
    unsigned int target_idx;
    unsigned int nfc_protocol;
    unsigned int service_name_len;
    unsigned int dsap;
    char service_name[64];
};

struct device;

struct nfc_dev {
    struct device *dev;
    bool dep_link_up;
};

struct nfc_llcp_local {
    unsigned int rf_mode;
    unsigned int target_idx;
    struct {
        void *connecting_sockets;
    };
};

struct nfc_llcp_sock {
    struct nfc_dev *dev;
    struct nfc_llcp_local *local;
    unsigned int ssap;
    unsigned int reserved_ssap;
    unsigned int dsap;
    unsigned int nfc_protocol;
    unsigned int service_name_len;
    char *service_name;
};

#define AF_NFC 39
#define LLCP_CONNECTED 1
#define LLCP_CONNECTING 2
#define LLCP_SAP_MAX 63
#define LLCP_SAP_SDP 1
#define NFC_LLCP_MAX_SERVICE_NAME 64
#define NFC_RF_INITIATOR 0
#define O_NONBLOCK 04000
#define EINVAL 22
#define EISCONN 106
#define EINPROGRESS 115
#define ENODEV 19
#define ENOLINK 67
#define ENOMEM 12
#define GFP_KERNEL 0

#define pr_debug(fmt, ...) 
#define lock_sock(sk) 
#define release_sock(sk) 
#define sock_sndtimeo(sk, flags) 0
#define sock_wait_state(sk, state, timeout) 0
#define min_t(type, x, y) ((x) < (y) ? (x) : (y))

static inline void *kmemdup(const void *src, size_t len, int gfp) { return NULL; }
static inline void kfree(void *p) {}
static inline void device_lock(struct device *dev) {}
static inline void device_unlock(struct device *dev) {}

static inline struct nfc_llcp_sock *nfc_llcp_sock(struct sock *sk) { return NULL; }
static inline struct nfc_dev *nfc_get_device(uint32_t idx) { return NULL; }
static inline void nfc_put_device(struct nfc_dev *dev) {}
static inline struct nfc_llcp_local *nfc_llcp_find_local(struct nfc_dev *dev) { return NULL; }
static inline void nfc_llcp_local_put(struct nfc_llcp_local *local) {}
static inline struct nfc_llcp_local *nfc_llcp_local_get(struct nfc_llcp_local *local) { return NULL; }
static inline uint8_t nfc_llcp_get_local_ssap(struct nfc_llcp_local *local) { return 0; }
static inline void nfc_llcp_put_ssap(struct nfc_llcp_local *local, uint8_t ssap) {}
static inline void nfc_llcp_sock_link(void *list, struct sock *sk) {}
static inline void nfc_llcp_sock_unlink(void *list, struct sock *sk) {}
static inline int nfc_llcp_send_connect(struct nfc_llcp_sock *llcp_sock) { return 0; }