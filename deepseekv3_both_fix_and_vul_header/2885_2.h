#include <stdint.h>

typedef uint32_t u32;

#define __user
#define DCCP_SOCKOPT_CCID_TX_INFO 1
#define EINVAL 22
#define ENOPROTOOPT 92
#define EFAULT 14

struct sock {
    void *sk_protinfo;
};

struct ccid3_hc_tx_sock {
    u32 tx_x;
    u32 tx_x_recv;
    u32 tx_x_calc;
    u32 tx_rtt;
    u32 tx_p;
    u32 tx_t_rto;
    u32 tx_t_ipi;
};

struct tfrc_tx_info {
    u32 tfrctx_x;
    u32 tfrctx_x_recv;
    u32 tfrctx_x_calc;
    u32 tfrctx_rtt;
    u32 tfrctx_p;
    u32 tfrctx_rto;
    u32 tfrctx_ipi;
};

static inline struct ccid3_hc_tx_sock *ccid3_hc_tx_sk(const struct sock *sk)
{
    return (struct ccid3_hc_tx_sock *)sk->sk_protinfo;
}

static int put_user(int len, int __user *optlen) { return 0; }
static int copy_to_user(u32 __user *optval, const void *val, int len) { return 0; }