#include <sys/socket.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>

typedef long long ktime_t;

struct sock {
    int sk_tsflags;
};
struct sk_buff {
    ktime_t tstamp;
    int len;
    void *data;
    struct skb_ext_err *ext_err;
};
struct skb_ext_err {
    int opt_stats;
};
struct msghdr;
struct scm_timestamping {
    struct timespec ts[3];
};
struct skb_shared_hwtstamps {
    ktime_t hwtstamp;
};

#define SOCK_RCVTSTAMP 1
#define SOCK_RCVTSTAMPNS 2
#define SOF_TIMESTAMPING_SOFTWARE (1<<0)
#define SOF_TIMESTAMPING_RAW_HARDWARE (1<<1)
#define SOF_TIMESTAMPING_OPT_STATS (1<<2)

static inline int sock_flag(struct sock *sk, int flag) { return 0; }
static inline void __net_timestamp(struct sk_buff *skb) {}
static inline void skb_get_timestamp(struct sk_buff *skb, struct timeval *tv) {}
static inline void skb_get_timestampns(struct sk_buff *skb, struct timespec *ts) {}
static inline int put_cmsg(struct msghdr *msg, int level, int type, int len, void *data) { return 0; }
static inline int ktime_to_timespec_cond(ktime_t kt, struct timespec *ts) { return 0; }
static inline int skb_is_err_queue(struct sk_buff *skb) { return 0; }
static inline struct skb_shared_hwtstamps *skb_hwtstamps(struct sk_buff *skb) { return NULL; }
static inline struct skb_ext_err *SKB_EXT_ERR(struct sk_buff *skb) { return skb->ext_err; }