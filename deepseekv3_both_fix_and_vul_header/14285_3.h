#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <stdbool.h>
#include <stdatomic.h>
#include <stddef.h>
#include <stdint.h>

typedef uint16_t u16;
typedef uint8_t u8;
typedef uint32_t u32;

#define PN_PIPE_DISABLE 0
#define PN_PIPE_ENABLE 1
#define PN_PIPE_ERR_INVALID_PARAM 0
#define PN_PIPE_ERR_PEP_IN_USE 0
#define PN_PIPE_ERR_OVERLOAD 0
#define PN_PIPE_SB_CONNECT_REQ_PEP_SUB_TYPE 1
#define PN_PIPE_SB_ALIGNED_DATA 2
#define PN_LEGACY_FLOW_CONTROL 0
#define GFP_KERNEL 0
#define O_NONBLOCK 0
#define EINVAL 1
#define EPROTO 2
#define ENOBUFS 3

struct sock {
    int sk_state;
    void *sk_prot;
    int sk_protocol;
    void (*sk_backlog_rcv)(struct sock *);
    void (*sk_destruct)(struct sock *);
};

struct sk_buff {
    unsigned char *data;
};

struct pnpipehdr {
    u8 pipe_handle;
    u8 state_after_connect;
    u8 other_pep_type;
    u8 data[4];
};

struct pep_sock {
    struct {
        u32 sobject;
        u32 dobject;
        u8 resource;
    } pn_sk;
    struct sock *listener;
    struct {
        struct hlist_node *next;
        struct hlist_node **pprev;
    } hlist;
    struct {
        struct sk_buff *next;
        struct sk_buff *prev;
    } ctrlreq_queue;
    u8 pipe_handle;
    u8 ifindex;
    u16 peer_type;
    u16 rx_credits;
    u16 rx_fc;
    u16 tx_fc;
    u8 init_enable;
    u8 aligned;
    atomic_int tx_credits;
};

struct sockaddr_pn {
    u8 spn_family;
    u8 spn_obj;
    u8 spn_dev;
    u8 spn_resource;
    u8 spn_zero[16];
};

static inline void atomic_set(atomic_int *v, int i) { *v = i; }
static inline void sock_init_data(void *a, struct sock *b) {}
static inline void sock_hold(struct sock *sk) {}
static inline void __sock_put(struct sock *sk) {}
static inline void sock_put(struct sock *sk) {}
static inline void sk_add_node(struct sock *a, void *b) {}
static inline void skb_queue_head_init(void *list) {}
static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}
static inline void kfree_skb(struct sk_buff *skb) {}
static inline void sk_acceptq_removed(struct sock *sk) {}
static inline struct sock *sk_alloc(void *a, int b, int c, void *d, bool e) { return NULL; }
static inline bool pskb_may_pull(struct sk_buff *skb, unsigned int len) { return false; }
static inline struct pnpipehdr *pnp_hdr(struct sk_buff *skb) { return NULL; }
static inline void pep_reject_conn(struct sock *sk, struct sk_buff *skb, int err, int flags) {}
static inline const u8 *pep_get_sb(struct sk_buff *skb, u8 *type, u8 *len, u8 *buf) { return NULL; }
static inline struct sock *pep_find_pipe(void *hlist, struct sockaddr_pn *dst, u8 pipe_handle) { return NULL; }
static inline int pep_accept_conn(struct sock *newsk, struct sk_buff *skb) { return 0; }
static inline struct sk_buff *skb_recv_datagram(struct sock *sk, int flags, int nonblock, int *err) { return NULL; }
static inline void pn_skb_get_dst_sockaddr(struct sk_buff *skb, struct sockaddr_pn *dst) {}
static inline void pn_skb_get_src_sockaddr(struct sk_buff *skb, struct sockaddr_pn *src) {}
static inline u32 pn_sockaddr_get_object(struct sockaddr_pn *spn) { return 0; }
static inline u8 pn_sockaddr_get_resource(struct sockaddr_pn *spn) { return 0; }
static inline struct pep_sock *pep_sk(struct sock *sk) { return NULL; }
static inline void *sock_net(struct sock *sk) { return NULL; }
static inline int unlikely(int x) { return x; }
static inline void pipe_do_rcv(struct sock *sk) {}
static inline void pipe_destruct(struct sock *sk) {}