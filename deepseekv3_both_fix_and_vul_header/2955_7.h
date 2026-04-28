#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <stddef.h>

typedef struct {
    char ax25_call[7];
} ax25_address;

typedef struct {
    int ndigi;
    ax25_address calls[8];
} ax25_digi;

struct sockaddr_ax25 {
    sa_family_t sax25_family;
    ax25_address sax25_call;
    int sax25_ndigis;
};

struct full_sockaddr_ax25 {
    sa_family_t fsa_family;
    ax25_address fsa_ax25_call;
    ax25_address fsa_digipeater[8];
};

struct ax25_sock {
    int pidincl;
};

struct kiocb;
struct socket {
    struct sock *sk;
};
struct sock {
    int sk_type;
    int sk_state;
};
struct sk_buff {
    unsigned int len;
    unsigned char *data;
};

#define ENOTCONN 107
#define AF_AX25 3
#define SOCK_SEQPACKET 5
#define TCP_ESTABLISHED 1
#define MSG_DONTWAIT 0x40
#define MSG_TRUNC 0x20

static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}
static inline struct sk_buff *skb_recv_datagram(struct sock *sk, int flags1, int flags2, int *err) { return NULL; }
static inline void skb_pull(struct sk_buff *skb, int len) {}
static inline void skb_reset_transport_header(struct sk_buff *skb) {}
static inline void skb_copy_datagram_iovec(struct sk_buff *skb, int offset, struct iovec *iov, int len) {}
static inline unsigned char *skb_mac_header(struct sk_buff *skb) { return NULL; }
static inline void ax25_addr_parse(const unsigned char *p1, int p2, ax25_address *src, void *p3, ax25_digi *digi, void *p4, void *p5) {}
static inline void skb_free_datagram(struct sock *sk, struct sk_buff *skb) {}
static inline struct ax25_sock *ax25_sk(struct sock *sk) { return NULL; }