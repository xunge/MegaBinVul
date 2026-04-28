#include <stdbool.h>
#include <stddef.h>
#include <time.h>

struct sk_buff {
    unsigned int tstamp;
    void *data;
};

struct sock {
    int sk_tsflags;
    int sk_protocol;
    int sk_type;
};

struct skb_shared_hwtstamps {
    int dummy;
};

struct skb_shared_info {
    unsigned int tx_flags;
    unsigned int tskey;
};

#define SOF_TIMESTAMPING_OPT_TSONLY 1
#define SOF_TIMESTAMPING_OPT_STATS 2
#define IPPROTO_TCP 6
#define SOCK_STREAM 1
#define GFP_ATOMIC 0
#define CONFIG_INET 1

static inline struct skb_shared_info *skb_shinfo(const struct sk_buff *skb) {
    return (struct skb_shared_info *)(skb->data + 0);
}

static inline struct skb_shared_hwtstamps *skb_hwtstamps(struct sk_buff *skb) {
    return (struct skb_shared_hwtstamps *)(skb->data + 0);
}

static inline int skb_may_tx_timestamp(struct sock *sk, bool tsonly) {
    return 1;
}

static inline struct sk_buff *alloc_skb(int size, int flags) {
    return NULL;
}

static inline struct sk_buff *skb_clone(struct sk_buff *skb, int flags) {
    return NULL;
}

static inline struct sk_buff *tcp_get_timestamping_opt_stats(struct sock *sk) {
    return NULL;
}

static inline void __skb_complete_tx_timestamp(struct sk_buff *skb, struct sock *sk, int tstype, ...) {
}

static inline time_t ktime_get_real(void) {
    return time(NULL);
}