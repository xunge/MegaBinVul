#include <stdatomic.h>
#include <stdbool.h>

struct sk_buff {
    struct sock *sk;
};

struct sock {
    atomic_int sk_refcnt;
};

struct skb_shared_hwtstamps {
    int dummy;
};

#define likely(x) (x)
#define SCM_TSTAMP_SND 0

bool skb_may_tx_timestamp(struct sock *sk, bool tx_timeout);
int atomic_inc_not_zero(atomic_int *v);
void __skb_complete_tx_timestamp(struct sk_buff *skb, struct sock *sk, int type, ...);
struct skb_shared_hwtstamps *skb_hwtstamps(struct sk_buff *skb);
void sock_put(struct sock *sk);