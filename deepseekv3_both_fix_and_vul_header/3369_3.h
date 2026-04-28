#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

typedef uint16_t __be16;
typedef uint32_t __be32;
typedef int32_t __s32;
typedef uint16_t __sum16;
typedef uint16_t __u16;
typedef uint32_t __u32;

struct sock {
    int sk_state;
    void (*sk_state_change)(struct sock *);
    int sk_shutdown;
    int sk_socket;
    int sk_sleep;
};

struct sk_buff {
    char cb[48];
};

struct tcp_sock {
    unsigned int rcv_nxt;
    unsigned int copied_seq;
    unsigned int snd_una;
    unsigned int write_seq;
    unsigned int snd_wnd;
    unsigned int advmss;
    unsigned int lsndtime;
    struct {
        unsigned int saw_tstamp:1;
        unsigned int tstamp_ok:1;
        unsigned int snd_wscale:4;
    } rx_opt;
    int linger2;
};

struct inet_connection_sock {
    struct {
        int (*conn_request)(struct sock *sk, struct sk_buff *skb);
        void (*rebuild_header)(struct sock *sk);
    } *icsk_af_ops;
};

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

#define SOCK_WAKE_IO    1
#define POLL_OUT        2
#define SEND_SHUTDOWN   1
#define RCV_SHUTDOWN    2
#define SOCK_DEAD       4

#define FLAG_SLOWPATH   0x1
#define TCP_TIMEWAIT_LEN (60*HZ)
#define HZ 100
#define TCPOLEN_TSTAMP_ALIGNED 12
#define LINUX_MIB_TCPABORTONDATA 0

static inline void kfree_skb(struct sk_buff *skb) { free(skb); }
static inline void __kfree_skb(struct sk_buff *skb) { free(skb); }
static inline void smp_mb() { __asm__ __volatile__("" ::: "memory"); }
static inline struct tcp_sock *tcp_sk(const struct sock *sk) { return (struct tcp_sock *)sk; }
static inline struct inet_connection_sock *inet_csk(const struct sock *sk) { return (struct inet_connection_sock *)sk; }
static inline void tcp_set_state(struct sock *sk, int state) { sk->sk_state = state; }
static inline void sk_wake_async(struct sock *sk, int how, int band) {}
static inline void tcp_init_wl(struct tcp_sock *tp, __be32 seq) {}
static inline void tcp_init_metrics(struct sock *sk) {}
static inline void tcp_init_congestion_control(struct sock *sk) {}
static inline void tcp_mtup_init(struct sock *sk) {}
static inline void tcp_initialize_rcv_mss(struct sock *sk) {}
static inline void tcp_init_buffer_space(struct sock *sk) {}
static inline void tcp_fast_path_on(struct tcp_sock *tp) {}
static inline void tcp_update_metrics(struct sock *sk) {}
static inline void tcp_done(struct sock *sk) {}
static inline void tcp_reset(struct sock *sk) {}
static inline void tcp_time_wait(struct sock *sk, int state, int timeout) {}
static inline int tcp_ack(struct sock *sk, struct sk_buff *skb, int flag) { return 0; }
static inline int tcp_rcv_synsent_state_process(struct sock *sk, struct sk_buff *skb, const struct tcphdr *th, unsigned int len) { return 0; }
static inline void tcp_urg(struct sock *sk, struct sk_buff *skb, const struct tcphdr *th) {}
static inline void tcp_data_snd_check(struct sock *sk) {}
static inline void tcp_ack_snd_check(struct sock *sk) {}
static inline int tcp_validate_incoming(struct sock *sk, struct sk_buff *skb, const struct tcphdr *th, int flag) { return 0; }
static inline void tcp_data_queue(struct sock *sk, struct sk_buff *skb) {}
static inline int tcp_fin_time(struct sock *sk) { return 0; }
static inline void inet_csk_reset_keepalive_timer(struct sock *sk, int timeout) {}
static inline int sock_owned_by_user(const struct sock *sk) { return 0; }
static inline int sock_flag(const struct sock *sk, int flag) { return 0; }
static inline void *__sk_dst_get(const struct sock *sk) { return NULL; }
static inline void dst_confirm(void *dst) {}
static inline void *sock_net(struct sock *sk) { return NULL; }
static inline int before(__u32 seq1, __u32 seq2) { return (__s32)(seq1-seq2) < 0; }
static inline int after(__u32 seq1, __u32 seq2) { return (__s32)(seq1-seq2) > 0; }
static __u32 tcp_time_stamp = 0;
static inline void NET_INC_STATS_BH(void *net, int field) {}

#define TCP_SKB_CB(skb) ((struct tcp_skb_cb *)&((skb)->cb[0]))
struct tcp_skb_cb {
    __be32 seq;
    __be32 end_seq;
    __be32 ack_seq;
};