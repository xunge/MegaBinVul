#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

struct sk_buff_head {
    struct sk_buff *next;
    struct sk_buff *prev;
    unsigned int qlen;
};

struct rb_root {
    void *rb_node;
};

struct sock {
    int sk_state;
    int sk_err;
    unsigned int sk_userlocks;
    int sk_shutdown;
    struct sk_buff_head sk_receive_queue;
    void (*sk_error_report)(struct sock *);
};

struct inet_sock {
    unsigned short inet_dport;
    int inet_num;
    int defer_connect;
};

struct inet_connection_sock {
    int icsk_backoff;
    int icsk_probes_out;
    struct {
        int rcv_mss;
    } icsk_ack;
    int icsk_bind_hash;
};

struct tcp_sock {
    int repair;
    unsigned int snd_nxt;
    unsigned int write_seq;
    unsigned int max_window;
    unsigned int srtt_us;
    unsigned int snd_cwnd;
    unsigned int packets_out;
    unsigned int snd_ssthresh;
    unsigned int snd_cwnd_cnt;
    unsigned int window_clamp;
    struct rb_root out_of_order_queue;
    struct {
        int dummy;
    } rx_opt;
};

#define TCP_CLOSE 7
#define TCP_LISTEN 10
#define TCP_SYN_SENT 2
#define TCPF_CLOSING (1 << 7)
#define TCPF_LAST_ACK (1 << 9)
#define TCP_INFINITE_SSTHRESH 0x7fffffff
#define TCP_MIN_MSS 48
#define TCP_CA_Open 0

#define SOCK_BINDADDR_LOCK 1
#define SOCK_DONE 0x0004

#define ECONNABORTED 103
#define ECONNRESET 104

#define unlikely(x) (x)
#define WARN_ON(condition) ((void)0)

typedef unsigned int gfp_t;
#define gfp_any() 0

static inline struct inet_sock *inet_sk(const struct sock *sk) { return (struct inet_sock *)sk; }
static inline struct inet_connection_sock *inet_csk(const struct sock *sk) { return (struct inet_connection_sock *)sk; }
static inline struct tcp_sock *tcp_sk(const struct sock *sk) { return (struct tcp_sock *)sk; }

static inline void tcp_set_state(struct sock *sk, int state) {}
static inline void inet_csk_listen_stop(struct sock *sk) {}
static inline int tcp_need_reset(int state) { return 0; }
static inline void tcp_send_active_reset(struct sock *sk, gfp_t priority) {}
static inline void tcp_clear_xmit_timers(struct sock *sk) {}
static inline void __skb_queue_purge(struct sk_buff_head *list) {}
static inline void tcp_write_queue_purge(struct sock *sk) {}
static inline void tcp_fastopen_active_disable_ofo_check(struct sock *sk) {}
static inline void skb_rbtree_purge(struct rb_root *root) {}
static inline void inet_reset_saddr(struct sock *sk) {}
static inline void sock_reset_flag(struct sock *sk, int flag) {}
static inline void tcp_set_ca_state(struct sock *sk, int state) {}
static inline void tcp_clear_retrans(struct tcp_sock *tp) {}
static inline void inet_csk_delack_init(struct sock *sk) {}
static inline void tcp_init_send_head(struct sock *sk) {}
static inline void __sk_dst_reset(struct sock *sk) {}
static inline void tcp_saved_syn_free(struct tcp_sock *tp) {}
static inline void tcp_free_fastopen_req(struct tcp_sock *tp) {}