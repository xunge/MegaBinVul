#include <stdint.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

struct net {
    struct {
        int sysctl_tcp_mtu_probing;
        int sysctl_tcp_base_mss;
        int sysctl_tcp_min_snd_mss;
    } ipv4;
};

struct inet_connection_sock {
    struct {
        int enabled;
        uint32_t probe_timestamp;
        int search_low;
    } icsk_mtup;
    uint32_t icsk_pmtu_cookie;
};

struct tcp_sock {
    int tcp_header_len;
};

struct sock;

extern const struct net *sock_net(const struct sock *sk);
extern uint32_t tcp_jiffies32;
extern int tcp_mtu_to_mss(struct sock *sk, int mtu);
extern int tcp_mss_to_mtu(struct sock *sk, int mss);
extern void tcp_sync_mss(struct sock *sk, uint32_t pmtu);
extern struct tcp_sock *tcp_sk(const struct sock *sk);