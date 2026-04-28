#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define __percpu
#define __net_init
#define ENOMEM 12
#define HZ 1000
#define NSEC_PER_MSEC 1000000L
#define UINT_MAX 4294967295U
#define PF_INET 2
#define SOCK_RAW 3
#define IPPROTO_TCP 6
#define IP_PMTUDISC_DO 2
#define SOCK_USE_WRITE_QUEUE (1 << 0)
#define TCP_BASE_MSS 1024
#define TCP_MIN_SND_MSS 48
#define TCP_PROBE_THRESHOLD 8
#define TCP_PROBE_INTERVAL 1
#define TCP_KEEPALIVE_TIME (120*60*HZ)
#define TCP_KEEPALIVE_PROBES 9
#define TCP_KEEPALIVE_INTVL (75*HZ)
#define TCP_SYN_RETRIES 6
#define TCP_SYNACK_RETRIES 5
#define TCP_FASTRETRANS_THRESH 3
#define TCP_RETR1 3
#define TCP_RETR2 15
#define TCP_FIN_TIMEOUT (60*HZ)
#define TCP_RACK_LOSS_DETECTION 1
#define TFO_CLIENT_ENABLE 1

struct sock {
    unsigned int sk_flags;
};

struct inet_sock {
    int pmtudisc;
};

struct tcp_hashinfo {
    int ehash_mask;
};

struct tcp_death_row {
    int sysctl_max_tw_buckets;
    struct tcp_hashinfo *hashinfo;
};

struct tcp_congestion_ops {
    struct module *owner;
};

struct module;

struct net {
    struct {
        struct sock * __percpu *tcp_sk;
        struct tcp_death_row tcp_death_row;
        int sysctl_tcp_ecn;
        int sysctl_tcp_ecn_fallback;
        int sysctl_tcp_base_mss;
        int sysctl_tcp_min_snd_mss;
        int sysctl_tcp_probe_threshold;
        int sysctl_tcp_probe_interval;
        int sysctl_tcp_keepalive_time;
        int sysctl_tcp_keepalive_probes;
        int sysctl_tcp_keepalive_intvl;
        int sysctl_tcp_syn_retries;
        int sysctl_tcp_synack_retries;
        int sysctl_tcp_syncookies;
        int sysctl_tcp_reordering;
        int sysctl_tcp_retries1;
        int sysctl_tcp_retries2;
        int sysctl_tcp_orphan_retries;
        int sysctl_tcp_fin_timeout;
        unsigned int sysctl_tcp_notsent_lowat;
        int sysctl_tcp_tw_reuse;
        int sysctl_max_syn_backlog;
        int sysctl_tcp_sack;
        int sysctl_tcp_window_scaling;
        int sysctl_tcp_timestamps;
        int sysctl_tcp_early_retrans;
        int sysctl_tcp_recovery;
        int sysctl_tcp_slow_start_after_idle;
        int sysctl_tcp_retrans_collapse;
        int sysctl_tcp_max_reordering;
        int sysctl_tcp_dsack;
        int sysctl_tcp_app_win;
        int sysctl_tcp_adv_win_scale;
        int sysctl_tcp_frto;
        int sysctl_tcp_moderate_rcvbuf;
        int sysctl_tcp_tso_win_divisor;
        int sysctl_tcp_limit_output_bytes;
        int sysctl_tcp_challenge_ack_limit;
        int sysctl_tcp_min_tso_segs;
        int sysctl_tcp_min_rtt_wlen;
        int sysctl_tcp_autocorking;
        int sysctl_tcp_invalid_ratelimit;
        int sysctl_tcp_pacing_ss_ratio;
        int sysctl_tcp_pacing_ca_ratio;
        int sysctl_tcp_rmem[3];
        int sysctl_tcp_wmem[3];
        int sysctl_tcp_comp_sack_delay_ns;
        int sysctl_tcp_comp_sack_nr;
        int sysctl_tcp_fastopen;
        int tcp_fastopen_ctx_lock;
        int sysctl_tcp_fastopen_blackhole_timeout;
        int tfo_active_disable_times;
        struct tcp_congestion_ops *tcp_congestion_control;
    } ipv4;
};

extern struct net init_net;
extern struct tcp_hashinfo tcp_hashinfo;
extern struct tcp_congestion_ops tcp_reno;

#define for_each_possible_cpu(cpu) for (cpu = 0; cpu < 1; cpu++)
#define per_cpu_ptr(ptr, cpu) (ptr)
#define alloc_percpu(type) ((type __percpu *)malloc(sizeof(type)))
#define sock_set_flag(sk, flag) ((sk)->sk_flags |= (flag))
#define inet_sk(sk) ((struct inet_sock *)(sk))
#define net_eq(net1, net2) ((net1) == (net2))
#define try_module_get(mod) 1
#define spin_lock_init(lock) do {} while (0)
#define atomic_set(v, i) ((*(v)) = (i))
#define max(a, b) ((a) > (b) ? (a) : (b))

static inline int inet_ctl_sock_create(struct sock **sk, int family, int type, int protocol, struct net *net) { return 0; }
static inline void tcp_sk_exit(struct net *net) {}