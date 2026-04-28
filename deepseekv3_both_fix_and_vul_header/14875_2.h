#include <stdint.h>
#include <string.h>

#define TCPOLEN_SACK_BASE 2
#define FLAG_DSACKING_ACK 0x01
#define FLAG_DATA_LOST 0x02
#define FLAG_ONLY_ORIG_SACKED 0x04
#define FLAG_DATA_SACKED 0x08
#define TCPCB_SACKED_ACKED 0x01
#define TCPCB_LOST 0x02
#define TCPCB_RETRANS 0x04
#define TCPCB_SACKED_RETRANS 0x08
#define LINUX_MIB_TCPDSACKIGNOREDNOUNDO 0
#define LINUX_MIB_TCPDSACKIGNOREDOLD 0
#define LINUX_MIB_TCPSACKDISCARD 0
#define FASTRETRANS_DEBUG 0
#define WARN_ON(condition) ((condition) ? 1 : 0)
#define BUG_TRAP(condition) ((void)0)
#define unlikely(x) (x)
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

typedef uint32_t __u32;
typedef uint8_t __u8;
typedef uint32_t u32;
typedef uint8_t u8;
typedef uint32_t __be32;

struct tcp_sack_block_wire {
    __be32 start_seq;
    __be32 end_seq;
};

struct tcp_sack_block {
    __be32 start_seq;
    __be32 end_seq;
};

struct tcp_skb_cb {
    __u32 seq;
    __u32 end_seq;
    __u32 ack_seq;
    __u8 sacked;
};

struct sk_buff {
    unsigned char *transport_header;
    unsigned char cb[48];
    struct sk_buff *next;
};

struct sock {
    struct sk_buff *sk_send_head;
};

struct tcp_sock {
    u32 lost_retrans_low;
    u32 snd_una;
    u32 high_seq;
    u32 frto_highmark;
    u32 max_window;
    u32 undo_marker;
    u32 highest_sack;
    int packets_out;
    int sacked_out;
    int fackets_out;
    int lost_out;
    int retrans_out;
    int undo_retrans;
    struct sk_buff *fastpath_skb_hint;
    int fastpath_cnt_hint;
    struct sk_buff *retransmit_skb_hint;
    struct tcp_sack_block recv_sack_cache[4];
};

struct inet_connection_sock {
    __u8 icsk_ca_state;
};

enum tcp_ca_state {
    TCP_CA_Open = 0,
    TCP_CA_Disorder = 1,
    TCP_CA_CWR = 2,
    TCP_CA_Recovery = 3,
    TCP_CA_Loss = 4
};

#define TCP_SKB_CB(__skb) ((struct tcp_skb_cb *)&((__skb)->cb[0]))

static inline struct tcp_sock *tcp_sk(const struct sock *sk) { return (struct tcp_sock *)sk; }
static inline struct inet_connection_sock *inet_csk(const struct sock *sk) { return (struct inet_connection_sock *)sk; }
static inline unsigned char *skb_transport_header(const struct sk_buff *skb) { return skb->transport_header; }
static inline struct sk_buff *tcp_write_queue_head(const struct sock *sk) { return sk->sk_send_head; }
static inline struct sk_buff *tcp_send_head(const struct sock *sk) { return sk->sk_send_head; }
static inline int tcp_skb_pcount(const struct sk_buff *skb) { return 1; }
static inline int tcp_match_skb_to_sack(struct sock *sk, struct sk_buff *skb, u32 start_seq, u32 end_seq) { return 0; }
static inline int tcp_check_dsack(struct tcp_sock *tp, struct sk_buff *ack_skb, struct tcp_sack_block_wire *sp, int num_sacks, u32 prior_snd_una) { return 0; }
static inline int tcp_mark_lost_retrans(struct sock *sk, u32 end_seq) { return 0; }
static inline void tcp_verify_left_out(struct tcp_sock *tp) {}
static inline void tcp_update_reordering(struct sock *sk, int metric, int ts) {}
static inline int tcp_is_sackblock_valid(struct tcp_sock *tp, int dup_sack, u32 start_seq, u32 end_seq) { return 1; }
#define tcp_for_write_queue_from(skb, sk) for (; skb != NULL; skb = skb->next)
#define NET_INC_STATS_BH(x) do {} while (0)
#define before(a, b) ((int32_t)((a)-(b)) < 0)
#define after(a, b) ((int32_t)((a)-(b)) > 0)
#define ntohl(x) (x)
#define min(a, b) ((a) < (b) ? (a) : (b))