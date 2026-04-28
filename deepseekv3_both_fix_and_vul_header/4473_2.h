#include <stdint.h>
#include <stddef.h>

typedef uint64_t u64;

struct sock;
struct tcp_sock {
    int snd_ssthresh;
    int packets_out;
    int sacked_out;
    int prr_delivered;
    int prior_cwnd;
    int prr_out;
    int snd_cwnd;
};

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min_t(type, x, y) ((type)(x) < (type)(y) ? (type)(x) : (type)(y)) 
#define max_t(type, x, y) ((type)(x) > (type)(y) ? (type)(x) : (type)(y))

static inline struct tcp_sock *tcp_sk(struct sock *sk) { return (struct tcp_sock *)sk; }
static inline int tcp_packets_in_flight(struct tcp_sock *tp) { return 0; }
static inline u64 div_u64(u64 dividend, int divisor) { return dividend / divisor; }

#define FLAG_RETRANS_DATA_ACKED 0x1
#define FLAG_LOST_RETRANS 0x2