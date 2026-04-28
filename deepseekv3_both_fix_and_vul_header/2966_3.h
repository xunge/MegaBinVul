#include <sys/socket.h>
#include <sys/uio.h>
#include <stddef.h>
#include <unistd.h>
#include <errno.h>

struct kiocb;
struct socket {
    struct sock *sk;
};
struct sock {
    int sk_state;
    int sk_type;
    int sk_shutdown;
    struct {
        struct sk_buff *next;
    } sk_receive_queue;
};
struct sk_buff {
    unsigned int len;
    struct sk_buff *next;
};

#define LLCP_CLOSED 0
#define RCV_SHUTDOWN 1
#define EOPNOTSUPP 95
#define EFAULT 14
#define NFC_PROTO_NFC_DEP 5

struct nfc_llcp_ui_cb {
    unsigned int dsap;
    unsigned int ssap;
};

struct sockaddr_nfc_llcp {
    sa_family_t sa_family;
    unsigned int nfc_protocol;
    unsigned int dsap;
    unsigned int ssap;
};

static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}
static inline int sock_error(struct sock *sk) { return 0; }
static inline struct sk_buff *skb_recv_datagram(struct sock *sk, int flags, int noblock, int *err) { return NULL; }
static inline int skb_copy_datagram_iovec(struct sk_buff *skb, int offset, struct iovec *to, int len) { return 0; }
static inline void sock_recv_timestamp(struct msghdr *msg, struct sock *sk, struct sk_buff *skb) {}
static inline void skb_pull(struct sk_buff *skb, unsigned int len) {}
static inline void kfree_skb(struct sk_buff *skb) {}
static inline struct nfc_llcp_ui_cb *nfc_llcp_ui_skb_cb(struct sk_buff *skb) { return NULL; }
static inline int skb_queue_empty(const struct { struct sk_buff *next; } *list) { return 1; }
static inline void skb_queue_head(struct { struct sk_buff *next; } *list, struct sk_buff *newsk) {}

#define pr_debug(fmt, ...) 
#define pr_err(fmt, ...) 

#define min_t(type, x, y) ((x) < (y) ? (x) : (y))