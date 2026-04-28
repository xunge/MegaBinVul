#include <stdint.h>

#define TCP_MIN_SND_MSS 536

struct sock;
struct dst_entry;

struct tcphdr {
    uint16_t source;
    uint16_t dest;
    uint32_t seq;
    uint32_t ack_seq;
    uint16_t res1:4;
    uint16_t doff:4;
    uint16_t fin:1;
    uint16_t syn:1;
    uint16_t rst:1;
    uint16_t psh:1;
    uint16_t ack:1;
    uint16_t urg:1;
    uint16_t res2:2;
    uint16_t window;
    uint16_t check;
    uint16_t urg_ptr;
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

static inline struct tcp_sock *tcp_sk(const struct sock *sk) { return (struct tcp_sock *)sk; }
static inline struct inet_connection_sock *inet_csk(const struct sock *sk) { return (struct inet_connection_sock *)sk; }
static inline const struct dst_entry *__sk_dst_get(const struct sock *sk) { return 0; }
static inline int dst_allfrag(const struct dst_entry *dst) { return 0; }