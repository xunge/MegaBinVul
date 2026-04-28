#include <stdint.h>

typedef int32_t __s32;
typedef uint32_t __u32;
typedef uint16_t __u16;
typedef uint8_t __u8;

#define TCP_CLOSE       0
#define TCP_LISTEN      1
#define TCP_SYN_SENT    2
#define TCP_SYN_RECV    3
#define TCP_ESTABLISHED 4
#define TCP_FIN_WAIT1   5
#define TCP_FIN_WAIT2   6
#define TCP_CLOSE_WAIT  7
#define TCP_CLOSING     8
#define TCP_LAST_ACK    9
#define TCP_TIME_WAIT   10

#define TCP_TIMEWAIT_LEN (60*HZ)
#define HZ 100
#define TCPOLEN_TSTAMP_ALIGNED 12

#define SOCK_DEAD 1
#define SEND_SHUTDOWN 1
#define RCV_SHUTDOWN 2
#define POLL_OUT 2
#define FLAG_SLOWPATH 0x1

#define LINUX_MIB_PAWSESTABREJECTED 0
#define LINUX_MIB_TCPABORTONSYN 0
#define LINUX_MIB_TCPABORTONDATA 0

struct tcphdr {
    __u16 source;
    __u16 dest;
    __u32 seq;
    __u32 ack_seq;
    __u16 window;
    __u16 check;
    __u16 urg_ptr;
    __u8  ack;
    __u8  rst;
    __u8  syn;
    __u8  fin;
};

struct tcp_options_received {
    __u32 saw_tstamp:1;
    __u32 tstamp_ok:1;
    __u32 snd_wscale:4;
    __u32 rcv_tsecr:32;
};

struct tcp_sock {
    __u32 rcv_nxt;
    __u32 snd_una;
    __u32 write_seq;
    __u32 copied_seq;
    __u32 snd_wnd;
    __u32 advmss;
    __u32 srtt;
    __u32 lsndtime;
    __s32 linger2;
    struct tcp_options_received rx_opt;
};

struct inet_connection_sock {
    struct {
        int (*conn_request)(struct sock *sk, struct sk_buff *skb);
        void (*rebuild_header)(struct sock *sk);
    } *icsk_af_ops;
};

struct sock {
    int sk_state;
    unsigned int sk_shutdown;
    void *sk_socket;
    void *sk_dst_cache;
    void *sk_sleep;
    int sk_dead;
    void (*sk_state_change)(struct sock *sk);
};

struct sk_buff {
    void *cb;
};

struct tcp_skb_cb {
    __u32 seq;
    __u32 end_seq;
    __u32 ack_seq;
};

#define TCP_SKB_CB(__skb) ((struct tcp_skb_cb *)&((__skb)->cb[0]))

static inline int before(__u32 seq1, __u32 seq2) {
    return (__s32)(seq1-seq2) < 0;
}

static inline int after(__u32 seq1, __u32 seq2) {
    return (__s32)(seq1-seq2) > 0;
}

static inline __u16 ntohs(__u16 val) {
    return val;
}

static inline void smp_mb(void) {}
static inline void dst_confirm(void *dst) {}
static inline int sock_owned_by_user(const struct sock *sk) { return 0; }
static inline int sock_flag(const struct sock *sk, int flag) { return 0; }
static inline void sk_wake_async(struct sock *sk, int how, int band) {}

static inline struct tcp_sock *tcp_sk(const struct sock *sk) {
    return (struct tcp_sock *)sk;
}

static inline struct inet_connection_sock *inet_csk(const struct sock *sk) {
    return (struct inet_connection_sock *)sk;
}

static inline void __kfree_skb(struct sk_buff *skb) {}
static inline void tcp_urg(struct sock *sk, struct sk_buff *skb, struct tcphdr *th) {}
static inline void tcp_data_snd_check(struct sock *sk, struct tcp_sock *tp) {}
static inline void tcp_send_dupack(struct sock *sk, struct sk_buff *skb) {}
static inline void tcp_reset(struct sock *sk) {}
static inline void tcp_replace_ts_recent(struct tcp_sock *tp, __u32 seq) {}
static inline int tcp_sequence(struct tcp_sock *tp, __u32 seq, __u32 end_seq) { return 1; }
static inline int tcp_fast_parse_options(struct sk_buff *skb, struct tcphdr *th, struct tcp_sock *tp) { return 0; }
static inline int tcp_paws_discard(struct sock *sk, struct sk_buff *skb) { return 0; }
static inline int tcp_ack(struct sock *sk, struct sk_buff *skb, int flag) { return 1; }
static inline void tcp_set_state(struct sock *sk, int state) {}
static inline void tcp_init_wl(struct tcp_sock *tp, __u32 ack_seq, __u32 seq) {}
static inline void tcp_ack_saw_tstamp(struct sock *sk, int flag) {}
static inline void tcp_init_metrics(struct sock *sk) {}
static inline void tcp_init_congestion_control(struct sock *sk) {}
static inline void tcp_mtup_init(struct sock *sk) {}
static inline void tcp_initialize_rcv_mss(struct sock *sk) {}
static inline void tcp_init_buffer_space(struct sock *sk) {}
static inline void tcp_fast_path_on(struct tcp_sock *tp) {}
static inline void tcp_done(struct sock *sk) {}
static inline int tcp_fin_time(struct sock *sk) { return 0; }
static inline void inet_csk_reset_keepalive_timer(struct sock *sk, int timeout) {}
static inline void tcp_time_wait(struct sock *sk, int state, int timeout) {}
static inline void tcp_update_metrics(struct sock *sk) {}
static inline void tcp_data_queue(struct sock *sk, struct sk_buff *skb) {}
static inline void tcp_ack_snd_check(struct sock *sk) {}
static inline int tcp_rcv_synsent_state_process(struct sock *sk, struct sk_buff *skb, struct tcphdr *th, unsigned len) { return 0; }
static inline void NET_INC_STATS_BH(int stat) {}
static __u32 tcp_time_stamp = 0;