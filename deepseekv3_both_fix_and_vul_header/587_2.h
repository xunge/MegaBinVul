#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;
typedef uint8_t __u8;

struct tcphdr {
    // Minimal definition for sizeof() to work
    uint16_t source;
    uint16_t dest;
    uint32_t seq;
    uint32_t ack_seq;
    uint16_t flags;
    uint16_t window;
    uint16_t check;
    uint16_t urg_ptr;
};

struct sock {
    unsigned int sk_userlocks;
    int sk_err;
};

struct dst_entry {
    // Minimal definition
};

struct tcp_sock {
    int tcp_header_len;
    struct {
        int user_mss;
        int mss_clamp;
        int ts_recent_stamp;
        __u8 rcv_wscale;
    } rx_opt;
    int max_window;
    int window_clamp;
    int advmss;
    int rcv_wnd;
    int rcv_ssthresh;
    int snd_wnd;
    int write_seq;
    int snd_una;
    int snd_sml;
    int snd_up;
    int snd_nxt;
    int repair;
    int rcv_nxt;
    u32 rcv_tstamp;
    int rcv_wup;
    int copied_seq;
    struct {
        int (*md5_lookup)(struct sock *sk, struct sock *sk2);
    } *af_specific;
};

struct net {
    struct {
        struct {
            int sysctl_tcp_timestamps;
            int sysctl_tcp_window_scaling;
        } ipv4;
    };
};

struct inet_connection_sock {
    u32 icsk_rto;
    int icsk_retransmits;
};

#define CONFIG_TCP_MD5SIG
#define TCPOLEN_TSTAMP_ALIGNED 12
#define TCPOLEN_MD5SIG_ALIGNED 18
#define SOCK_RCVBUF_LOCK (1 << 0)
#define SOCK_DONE (1 << 1)
#define RTAX_WINDOW 3
#define RTAX_INITRWND 4

static inline struct tcp_sock *tcp_sk(const struct sock *sk) { return (struct tcp_sock *)sk; }
static inline const struct dst_entry *__sk_dst_get(const struct sock *sk) { return NULL; }
static inline unsigned int dst_mtu(const struct dst_entry *dst) { return 0; }
static inline unsigned int dst_metric(const struct dst_entry *dst, int metric) { return 0; }
static inline unsigned int dst_metric_advmss(const struct dst_entry *dst) { return 0; }
static inline void tcp_mtup_init(struct sock *sk) {}
static inline void tcp_sync_mss(struct sock *sk, unsigned int mss) {}
static inline void tcp_ca_dst_init(struct sock *sk, const struct dst_entry *dst) {}
static inline unsigned int tcp_full_space(const struct sock *sk) { return 0; }
static inline u32 tcp_rwnd_init_bpf(struct sock *sk) { return 0; }
static inline void tcp_select_initial_window(struct sock *sk, int space, int mss, 
                                           int *rcv_wnd, int *window_clamp, 
                                           int window_scaling, __u8 *rcv_wscale, 
                                           u32 init_rcv_wnd) {}
static inline void tcp_init_wl(struct tcp_sock *tp, u32 seq) {}
static inline void tcp_clear_retrans(struct tcp_sock *tp) {}
static inline void sock_reset_flag(struct sock *sk, int flag) {}
static u32 tcp_jiffies32 = 0;
static inline void tcp_initialize_rcv_mss(struct sock *sk) {}
static inline unsigned int tcp_mss_clamp(struct tcp_sock *tp, unsigned int mss) { return 0; }
static inline u32 tcp_timeout_init(struct sock *sk) { return 0; }
static inline struct net *sock_net(const struct sock *sk) { return NULL; }
static inline struct inet_connection_sock *inet_csk(struct sock *sk) { return NULL; }
#define likely(x) __builtin_expect(!!(x), 1)