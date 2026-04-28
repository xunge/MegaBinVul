#include <stddef.h>

struct sock;
struct tcp_sock;
struct inet_connection_sock;
struct dst_entry;
struct net;

#define TCP_MIN_SND_MSS 48

static inline const struct tcp_sock *tcp_sk(const struct sock *sk) { return (const struct tcp_sock *)sk; }
static inline const struct inet_connection_sock *inet_csk(const struct sock *sk) { return (const struct inet_connection_sock *)sk; }
static inline const struct dst_entry *__sk_dst_get(const struct sock *sk) { return NULL; }
static inline int dst_allfrag(const struct dst_entry *dst) { return 0; }
static inline struct net *sock_net(const struct sock *sk) { return NULL; }

struct tcphdr {
    // dummy definition
};

struct inet_connection_sock {
    struct {
        int net_header_len;
        int net_frag_header_len;
    } *icsk_af_ops;
    int icsk_ext_hdr_len;
};

struct tcp_sock {
    struct {
        int mss_clamp;
    } rx_opt;
};

struct net {
    struct {
        struct {
            int sysctl_tcp_min_snd_mss;
        } ipv4;
    };
};