#include <stdint.h>
#include <errno.h>
#include <stddef.h>

struct sock {
    int sk_wmem_alloc;
    int sk_wmem_queued;
    int sk_sndbuf;
};

struct sk_buff {
    unsigned int len;
    unsigned char *data;
    unsigned char cb[48];
    unsigned int headroom;
};

struct inet_connection_sock {
    struct {
        unsigned int probe_size;
    } icsk_mtup;
    struct {
        int (*rebuild_header)(struct sock *);
    } *icsk_af_ops;
};

struct tcp_sock {
    uint32_t snd_una;
    uint32_t total_retrans;
};

#define TCP_MIB_RETRANSSEGS 0
#define LINUX_MIB_TCPSYNRETRANS 0
#define LINUX_MIB_TCPRETRANSFAIL 0
#define TCPHDR_SYN 0x01
#define TCPCB_EVER_RETRANS 0x01
#define BPF_SOCK_OPS_RETRANS_CB_FLAG 0
#define BPF_SOCK_OPS_RETRANS_CB 0

static inline struct inet_connection_sock *inet_csk(struct sock *sk) {
    return (struct inet_connection_sock *)sk;
}

static inline struct tcp_sock *tcp_sk(struct sock *sk) {
    return (struct tcp_sock *)sk;
}

#define GFP_ATOMIC 0
#define EAGAIN 11
#define EBUSY 16
#define EINVAL 22
#define ENOMEM 12
#define EHOSTUNREACH 113
#define ENOBUFS 105

#define TCPHDR_SYN_ECN 0x02
#define TCP_FRAG_IN_RTX_QUEUE 0
#define MAX_TCP_HEADER 128
#define NET_IP_ALIGN 2

#define WARN_ON_ONCE(cond) do { } while (0)
#define unlikely(x) (x)
#define likely(x) (x)

#define min_t(type, x, y) ((x) < (y) ? (x) : (y))

typedef uint32_t u32;

static inline int refcount_read(const int *r) { return *r; }

struct tcp_skb_cb {
    uint32_t seq;
    uint32_t end_seq;
    uint8_t tcp_flags;
    uint8_t sacked;
};

#define TCP_SKB_CB(skb) ((struct tcp_skb_cb *)&((skb)->cb[0]))

static inline int before(uint32_t a, uint32_t b) { return (int32_t)(a - b) < 0; }
static inline unsigned int tcp_current_mss(struct sock *sk) { return 0; }
static inline int skb_still_in_host_queue(struct sock *sk, struct sk_buff *skb) { return 0; }
static inline int tcp_trim_head(struct sock *sk, struct sk_buff *skb, unsigned int len) { return 0; }
static inline uint32_t tcp_wnd_end(struct tcp_sock *tp) { return 0; }
static inline int tcp_fragment(struct sock *sk, int flags, struct sk_buff *skb, int len, unsigned int mss, int gfp) { return 0; }
static inline int skb_unclone(struct sk_buff *skb, int gfp) { return 0; }
static inline int tcp_skb_pcount(struct sk_buff *skb) { return 0; }
static inline void tcp_set_skb_tso_segs(struct sk_buff *skb, unsigned int mss) {}
static inline void tcp_adjust_pcount(struct sock *sk, struct sk_buff *skb, int diff) {}
static inline void tcp_retrans_try_collapse(struct sock *sk, struct sk_buff *skb, unsigned int mss) {}
static inline void tcp_ecn_clear_syn(struct sock *sk, struct sk_buff *skb) {}
static inline void TCP_ADD_STATS(void *net, int stat, int val) {}
static inline void __NET_INC_STATS(void *net, int stat) {}
static inline void *sock_net(struct sock *sk) { return NULL; }
static inline int BPF_SOCK_OPS_TEST_FLAG(struct tcp_sock *tp, int flag) { return 0; }
static inline void tcp_call_bpf_3arg(struct sock *sk, int op, uint32_t seq, int segs, int err) {}
static inline void tcp_update_skb_after_send(struct tcp_sock *tp, struct sk_buff *skb) {}
static inline void tcp_rate_skb_sent(struct sock *sk, struct sk_buff *skb) {}
static inline struct sk_buff *__pskb_copy(struct sk_buff *skb, int len, int gfp) { return NULL; }
static inline int tcp_transmit_skb(struct sock *sk, struct sk_buff *skb, int clone, int gfp) { return 0; }
static inline void NET_INC_STATS(void *net, int stat) {}
static inline unsigned int skb_headroom(const struct sk_buff *skb) { return 0; }
#define tcp_skb_tsorted_save(skb) do {
#define tcp_skb_tsorted_restore(skb) } while (0)