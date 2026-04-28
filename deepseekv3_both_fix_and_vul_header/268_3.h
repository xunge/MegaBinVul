#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;
typedef uint64_t u64;

struct sock;
struct sk_buff {
    unsigned int len;
    unsigned char cb[48];
};
struct tcp_sock {
    struct sk_buff *lost_skb_hint;
    struct sk_buff *retransmit_skb_hint;
    u32 lost_cnt_hint;
};
struct net;

struct tcp_sacktag_state {
    u32 reord;
    u32 fack_count;
    u32 lost_cnt_hint;
    u32 retrans_out;
    u32 prior_sacked;
    void *rate;
};

struct tcp_skb_cb {
    u32 seq;
    u32 end_seq;
    u8 sacked;
    u16 tcp_gso_size;
    u8 tcp_flags;
    u8 eor;
    struct {
        u32 delivered_mstamp;
    } tx;
};

#define TCP_SKB_CB(__skb) ((struct tcp_skb_cb *)&((__skb)->cb[0]))
#define TCPCB_EVER_RETRANS 0x80
#define TCPHDR_FIN 0x01
#define LINUX_MIB_SACKSHIFTED 0
#define LINUX_MIB_SACKMERGED 0

static inline void BUG_ON(int condition) {}
static inline void NET_INC_STATS(struct net *net, int stat) {}
static inline struct net *sock_net(struct sock *sk) { return NULL; }
static inline struct tcp_sock *tcp_sk(const struct sock *sk) { return NULL; }
static inline void tcp_sacktag_one(struct sock *sk, struct tcp_sacktag_state *state,
                                 u8 sacked, u32 start_seq, u32 end_seq,
                                 bool dup_sack, unsigned int pcount,
                                 u64 timestamp) {}
static inline void tcp_rate_skb_delivered(struct sock *sk, struct sk_buff *skb,
                                        void *rate) {}
static inline void tcp_skb_pcount_add(struct sk_buff *skb, int pcount) {}
static inline int tcp_skb_pcount(const struct sk_buff *skb) { return 0; }
static inline u64 tcp_skb_timestamp_us(const struct sk_buff *skb) { return 0; }
static inline struct sk_buff *tcp_highest_sack(struct sock *sk) { return NULL; }
static inline void tcp_advance_highest_sack(struct sock *sk, struct sk_buff *skb) {}
static inline void tcp_skb_collapse_tstamp(struct sk_buff *skb,
                                          const struct sk_buff *next) {}
static inline bool unlikely(bool x) { return x; }
static inline void tcp_rtx_queue_unlink_and_free(struct sk_buff *skb,
                                               struct sock *sk) {}