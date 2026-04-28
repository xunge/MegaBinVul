#include <stdint.h>
#include <stddef.h>

struct sk_buff {
    uint8_t pkt_type;
    unsigned int len;
    void* data;
};

struct sock {
    int sk_bound_dev_if;
};

struct sctp_ep_common {
    struct sock *sk;
    void *inqueue;
};

struct sctp_association {
    struct sctp_ep_common base;
};

struct sctp_endpoint {
    struct sctp_ep_common base;
};

struct sctp_transport {};

struct sctp_chunk {
    struct sctp_ep_common *rcvr;
    void* sctp_hdr;
    struct sctp_transport *transport;
};

struct sctphdr {};

struct sctp_chunkhdr {};

union sctp_addr {};

struct sctp_af {
    int (*addr_valid)(union sctp_addr *, void*, struct sk_buff*);
    void (*from_skb)(union sctp_addr*, struct sk_buff*, int);
    int (*skb_iif)(struct sk_buff*);
};

struct iphdr {
    uint8_t version;
};

struct sctp_sock {
    struct sctp_endpoint *ep;
};

struct sctp_input_cb {
    struct sctp_chunk *chunk;
};

#define PACKET_HOST 0
#define SCTP_MIB_INSCTPPACKS 0
#define SCTP_MIB_OUTOFBLUES 0
#define SCTP_MIB_IN_PKT_BACKLOG 0
#define SCTP_MIB_IN_PKT_SOFTIRQ 0
#define SCTP_MIB_IN_PKT_DISCARDS 0
#define XFRM_POLICY_IN 0

static inline int skb_linearize(struct sk_buff *skb) { return 0; }
static inline struct sctphdr* sctp_hdr(struct sk_buff *skb) { return NULL; }
static inline void __skb_pull(struct sk_buff *skb, int offset) {}
static inline int skb_transport_offset(struct sk_buff *skb) { return 0; }
static inline int skb_csum_unnecessary(struct sk_buff *skb) { return 0; }
static inline int sctp_rcv_checksum(struct sk_buff *skb) { return 0; }
static inline void skb_pull(struct sk_buff *skb, int len) {}
static inline int ipver2af(int version) { return 0; }
static inline struct iphdr* ip_hdr(struct sk_buff *skb) { return NULL; }
static inline struct sctp_af* sctp_get_af_specific(int family) { return NULL; }
static inline struct sctp_association* __sctp_rcv_lookup(struct sk_buff *skb, union sctp_addr *src, union sctp_addr *dest, struct sctp_transport **transport) { return NULL; }
static inline struct sctp_endpoint* __sctp_rcv_lookup_endpoint(union sctp_addr *dest) { return NULL; }
static inline void sctp_association_put(struct sctp_association *asoc) {}
static inline void sctp_endpoint_put(struct sctp_endpoint *ep) {}
static inline struct sock* sctp_get_ctl_sock() { return NULL; }
static inline struct sctp_sock* sctp_sk(struct sock *sk) { return NULL; }
static inline void sctp_endpoint_hold(struct sctp_endpoint *ep) {}
static inline int sctp_rcv_ootb(struct sk_buff *skb) { return 0; }
static inline int xfrm_policy_check(struct sock *sk, int policy, struct sk_buff *skb, int family) { return 0; }
static inline void nf_reset(struct sk_buff *skb) {}
static inline int sk_filter(struct sock *sk, struct sk_buff *skb) { return 0; }
static inline struct sctp_chunk* sctp_chunkify(struct sk_buff *skb, struct sctp_association *asoc, struct sock *sk) { return NULL; }
static inline void sctp_init_addrs(struct sctp_chunk *chunk, union sctp_addr *src, union sctp_addr *dest) {}
static inline void sctp_bh_lock_sock(struct sock *sk) {}
static inline int sock_owned_by_user(struct sock *sk) { return 0; }
static inline void sctp_add_backlog(struct sock *sk, struct sk_buff *skb) {}
static inline void sctp_inq_push(void *inqueue, struct sctp_chunk *chunk) {}
static inline void sctp_bh_unlock_sock(struct sock *sk) {}
static inline void kfree_skb(struct sk_buff *skb) {}
static inline void SCTP_INC_STATS_BH(int stat) {}
static inline struct sctp_input_cb* SCTP_INPUT_CB(struct sk_buff *skb) { return NULL; }

#define unlikely(x) (x)