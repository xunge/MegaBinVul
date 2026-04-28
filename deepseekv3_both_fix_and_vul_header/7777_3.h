#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

struct sock {
    uint32_t sk_wmem_queued;
    struct sk_buff *sk_send_head;
};

struct inet_connection_sock {
    struct {
        bool enabled;
        int probe_size;
        int search_high;
        int search_low;
    } icsk_mtup;
    int icsk_ca_state;
};

struct tcp_sock {
    int snd_cwnd;
    struct {
        int num_sacks;
        bool dsack;
    } rx_opt;
    int reordering;
    int mss_cache;
    uint32_t write_seq;
    uint32_t snd_nxt;
    int snd_wnd;
    struct {
        uint32_t probe_seq_start;
        uint32_t probe_seq_end;
    } mtu_probe;
};

struct sk_buff {
    uint32_t len;
    uint32_t truesize;
    uint16_t csum;
    uint8_t ip_summed;
    struct TCP_SKB_CB *cb;
    struct sk_buff *next;
};

struct net {
    struct {
        int sysctl_tcp_probe_threshold;
    } ipv4;
};

struct TCP_SKB_CB {
    uint32_t seq;
    uint32_t end_seq;
    int tcp_flags;
    int sacked;
    int eor;
};

#define likely(x) (x)
#define GFP_ATOMIC 0
#define CHECKSUM_PARTIAL 0
#define TCPHDR_ACK 0
#define TCPHDR_FIN 0
#define TCPHDR_PSH 0
#define TCP_CA_Open 0

#define min_t(type, x, y) ((x) < (y) ? (x) : (y))

static inline struct inet_connection_sock *inet_csk(struct sock *sk) { return (struct inet_connection_sock *)sk; }
static inline struct tcp_sock *tcp_sk(struct sock *sk) { return (struct tcp_sock *)sk; }
static inline struct net *sock_net(struct sock *sk) { return (struct net *)0; }
static inline int tcp_current_mss(struct sock *sk) { return 0; }
static inline int tcp_mtu_to_mss(struct sock *sk, int mtu) { return 0; }
static inline void tcp_mtu_check_reprobe(struct sock *sk) {}
static inline int after(uint32_t a, uint32_t b) { return a > b; }
static inline uint32_t tcp_wnd_end(struct tcp_sock *tp) { return 0; }
static inline int tcp_packets_in_flight(struct tcp_sock *tp) { return 0; }
static inline int tcp_can_coalesce_send_queue_head(struct sock *sk, int size) { return 0; }
static inline struct sk_buff *sk_stream_alloc_skb(struct sock *sk, int size, int gfp, bool b) { return (struct sk_buff *)0; }
static inline struct sk_buff *tcp_send_head(struct sock *sk) { return (struct sk_buff *)0; }
static inline void tcp_insert_write_queue_before(struct sk_buff *nskb, struct sk_buff *skb, struct sock *sk) {}
static inline void tcp_highest_sack_replace(struct sock *sk, struct sk_buff *old, struct sk_buff *new) {}
static inline void skb_copy_bits(struct sk_buff *skb, int offset, void *to, int len) {}
static inline void *skb_put(struct sk_buff *skb, int len) { return 0; }
static inline void tcp_skb_collapse_tstamp(struct sk_buff *skb, struct sk_buff *old) {}
static inline void tcp_unlink_write_queue(struct sk_buff *skb, struct sock *sk) {}
static inline void sk_wmem_free_skb(struct sock *sk, struct sk_buff *skb) {}
static inline void skb_pull(struct sk_buff *skb, int len) {}
static inline void __pskb_trim_head(struct sk_buff *skb, int len) {}
static inline void tcp_set_skb_tso_segs(struct sk_buff *skb, int mss) {}
static inline void tcp_init_tso_segs(struct sk_buff *skb, int len) {}
static inline int tcp_transmit_skb(struct sock *sk, struct sk_buff *skb, int clone, int gfp) { return 0; }
static inline void tcp_event_new_data_sent(struct sock *sk, struct sk_buff *skb) {}
static inline int tcp_mss_to_mtu(struct sock *sk, int mss) { return 0; }
static inline void sk_mem_charge(struct sock *sk, int size) {}

#define TCP_SKB_CB(skb) ((struct TCP_SKB_CB *)(skb)->cb)

struct skb_shared_info {
    int nr_frags;
};

static inline struct skb_shared_info *skb_shinfo(struct sk_buff *skb) { return (struct skb_shared_info *)0; }

#define tcp_for_write_queue_from_safe(skb, next, sk) \
    for (skb = (sk)->sk_send_head, next = skb ? skb->next : NULL; \
         skb != NULL; \
         skb = next, next = skb ? skb->next : NULL)