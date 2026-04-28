#include <string.h>
#include <signal.h>
#include <errno.h>

#define ROSE_MAX_DIGIS 8
#define MSG_DONTWAIT   0x40
#define MSG_EOR        0x80
#define MSG_CMSG_COMPAT 0x80000000
#define SOCK_ZAPPED    3
#define SEND_SHUTDOWN  1
#define EINVAL         22
#define EADDRNOTAVAIL  99
#define EPIPE          32
#define ENETUNREACH    101
#define EISCONN        106
#define ENOTCONN       107
#define EMSGSIZE       90
#define AF_ROSE        11
#define TCP_ESTABLISHED 1
#define ROSE_GFI       0x10
#define ROSE_Q_BIT     0x80
#define ROSE_DATA      0x00
#define ROSE_MIN_LEN   3
#define AX25_BPQ_HEADER_LEN 1
#define AX25_MAX_HEADER_LEN 273
#define M_BIT          0x10
#define SIGPIPE        13

typedef struct {
    unsigned char ax25_call[7];
} ax25_address;

typedef struct {
    unsigned char rose_addr[5];
} rose_address;

struct kiocb;
struct socket {
    struct sock *sk;
};
struct msghdr {
    void *msg_name;
    int msg_namelen;
    struct iovec *msg_iov;
    size_t msg_iovlen;
    unsigned int msg_flags;
};
struct iovec {
    void *iov_base;
    size_t iov_len;
};
struct sk_buff_head {
    struct sk_buff *next;
    struct sk_buff *prev;
};
struct sock {
    struct sock *sk;
    unsigned short sk_state;
    unsigned char sk_shutdown;
    struct sk_buff_head sk_write_queue;
};
struct full_sockaddr_rose {
    unsigned short srose_family;
    rose_address srose_addr;
    ax25_address srose_call;
    unsigned short srose_ndigis;
    ax25_address srose_digis[ROSE_MAX_DIGIS];
};
struct rose_sock {
    void *neighbour;
    void *device;
    rose_address dest_addr;
    ax25_address dest_call;
    unsigned int dest_ndigis;
    ax25_address dest_digis[ROSE_MAX_DIGIS];
    unsigned short lci;
    unsigned char qbitincl;
};
struct sockaddr_rose {
    unsigned short srose_family;
    ax25_address srose_call;
    unsigned short srose_ndigis;
    ax25_address srose_digis[ROSE_MAX_DIGIS];
};
struct sk_buff {
    unsigned char *data;
    unsigned int len;
    unsigned long transport_header;
    struct sock *sk;
    int free;
    int arp;
    unsigned int headroom;
    void (*destructor)(struct sk_buff *);
};
struct net_device;
struct task_struct;

#define current ((struct task_struct *)0)
#define SOCK_DEBUG(sk, fmt, ...) do {} while (0)

static inline void *skb_put(struct sk_buff *skb, unsigned int len) {
    void *tmp = skb->data + skb->len;
    skb->len += len;
    return tmp;
}
static inline void *skb_push(struct sk_buff *skb, unsigned int len) {
    skb->data -= len;
    skb->len += len;
    return skb->data;
}
static inline void skb_pull(struct sk_buff *skb, unsigned int len) {
    skb->data += len;
    skb->len -= len;
}
static inline void skb_reserve(struct sk_buff *skb, unsigned int len) {
    skb->data += len;
}
static inline unsigned int skb_headroom(const struct sk_buff *skb) {
    return skb->headroom;
}
static inline void skb_reset_transport_header(struct sk_buff *skb) {
    skb->transport_header = (unsigned long)skb->data;
}
static inline void *skb_transport_header(const struct sk_buff *skb) {
    return (void *)skb->transport_header;
}
static inline void kfree_skb(struct sk_buff *skb) {
    if (skb->destructor)
        skb->destructor(skb);
}
static inline int memcpy_fromiovec(void *to, struct iovec *iov, int len) {
    return 0;
}
static inline void skb_copy_from_linear_data(const struct sk_buff *skb, void *to, const unsigned int len) {
    memcpy(to, skb->data, len);
}
static inline void skb_copy_to_linear_data(struct sk_buff *skb, const void *from, const unsigned int len) {
    memcpy(skb->data, from, len);
}
static inline void skb_queue_tail(struct sk_buff_head *list, struct sk_buff *newsk) {
}
static inline struct sk_buff *sock_alloc_send_skb(struct sock *sk, int size, int noblock, int *errcode) {
    return NULL;
}
static inline void send_sig(int sig, void *p, int priv) {
}
static inline int sock_flag(const struct sock *sk, int flag) {
    return 0;
}
static inline struct rose_sock *rose_sk(const struct sock *sk) {
    return (struct rose_sock *)sk;
}
static inline int rosecmp(rose_address *a, rose_address *b) {
    return memcmp(a, b, sizeof(rose_address));
}
static inline int ax25cmp(ax25_address *a, ax25_address *b) {
    return memcmp(a, b, sizeof(ax25_address));
}
static inline void rose_kick(struct sock *sk) {
}