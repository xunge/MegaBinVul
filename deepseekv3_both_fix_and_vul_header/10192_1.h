#include <sys/socket.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>

struct sock {
    int sk_tsflags;
};

struct sk_buff {
    time_t tstamp;
    int len;
    void *data;
};

struct msghdr;

struct scm_timestamping {
    struct timespec ts[3];
};

struct skb_shared_hwtstamps {
    time_t hwtstamp;
};

#define SOCK_RCVTSTAMP 1
#define SOCK_RCVTSTAMPNS 2
#define SOF_TIMESTAMPING_SOFTWARE 1
#define SOF_TIMESTAMPING_RAW_HARDWARE 2
#define SOF_TIMESTAMPING_OPT_STATS 4

int sock_flag(struct sock *sk, int flag);
void __net_timestamp(struct sk_buff *skb);
void skb_get_timestamp(struct sk_buff *skb, struct timeval *tv);
void skb_get_timestampns(struct sk_buff *skb, struct timespec *ts);
void put_cmsg(struct msghdr *msg, int level, int type, int len, void *data);
struct skb_shared_hwtstamps *skb_hwtstamps(struct sk_buff *skb);
int ktime_to_timespec_cond(time_t ktime, struct timespec *ts);