#include <stdint.h>
#include <stddef.h>

#define INET_DIAG_VEGASINFO 1

typedef uint32_t u32;
typedef uint64_t u64;

struct sock;
struct sk_buff;

struct illinois {
    u32 cnt_rtt;
    u32 base_rtt;
    u64 sum_rtt;
};

struct tcpvegas_info {
    u32 tcpv_enabled;
    u32 tcpv_rtt;
    u32 tcpv_minrtt;
    u32 tcpv_rttcnt;
};

static inline const struct illinois *inet_csk_ca(const struct sock *sk) { return NULL; }
static inline void nla_put(struct sk_buff *skb, int type, unsigned int size, const void *data) {}