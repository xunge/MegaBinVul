#include <sys/socket.h>
#include <netinet/in.h>
#include <stddef.h>

typedef enum {
    SCTP_SOCKET_UDP = 0,
    SCTP_SOCKET_TCP
} sctp_socket_type_t;

struct sk_buff {
    struct sk_buff *next;
    struct sk_buff *prev;
};

struct sk_buff_head {
    struct sk_buff *next;
    struct sk_buff *prev;
};

struct sock {
    int sk_sndbuf;
    int sk_rcvbuf;
    struct sk_buff_head sk_receive_queue;
    int sk_shutdown;
    int sk_state;
    int sk_family;
    int num;
};

struct sctp_association {
    struct {
        struct sock *sk;
    } base;
    struct {
        unsigned int ipv4_address;
        unsigned int ipv6_address;
    } peer;
    struct {
        int pd_mode;
        struct sk_buff_head reasm;
        struct sk_buff_head lobby;
    } ulpq;
};

struct sctp_sock {
    struct sctp_endpoint *ep;
    struct sctp_bind_bucket *bind_hash;
    void *hmac;
    sctp_socket_type_t type;
    int pd_mode;
    struct sk_buff_head pd_lobby;
};

struct sctp_endpoint {
    struct {
        struct {
            int dummy;
        } bind_addr;
    } base;
};

struct sctp_bind_bucket {
    struct sock *owner;
};

struct sctp_ulpevent {
    struct sctp_association *asoc;
};

#define SCTP_ADDR6_ALLOWED    0x00000001
#define SCTP_ADDR4_PEERSUPP   0x00000002
#define SCTP_ADDR6_PEERSUPP   0x00000004
#define SCTP_SCOPE_GLOBAL     0
#define GFP_KERNEL            0
#define CLOSED                0
#define SCTP_SS_ESTABLISHED   1
#define RCV_SHUTDOWN          1
#define PF_INET6              10
#define TCP                   1

static inline struct sctp_sock *sctp_sk(struct sock *sk) { return (struct sctp_sock *)sk; }
static inline struct sock *inet_sk(struct sock *sk) { return sk; }
static inline void inet_sk_copy_descendant(struct sock *newsk, struct sock *oldsk) {}
static inline void sk_add_bind_node(struct sock *sk, struct sock **pp) {}
static inline void sctp_bind_addr_copy(void *dst, void *src, int scope, int gfp, int flags) {}
#define sctp_skb_for_each(skb, head, tmp) \
    for ((skb) = (head)->next, (tmp) = (skb)->next; \
         (skb) != (struct sk_buff *)(head); \
         (skb) = (tmp), (tmp) = (skb)->next)
static inline void sctp_lock_sock(struct sock *sk) {}
static inline void sctp_assoc_migrate(struct sctp_association *assoc, struct sock *sk) {}
static inline int sctp_state(struct sctp_association *assoc, int state) { return 0; }
static inline int sctp_style(struct sock *sk, int type) { return 0; }
static inline void sctp_release_sock(struct sock *sk) {}