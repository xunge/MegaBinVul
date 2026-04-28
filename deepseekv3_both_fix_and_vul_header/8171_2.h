#include <stdint.h>

typedef uint32_t u32;

struct sock;
struct sk_buff;

struct tcp_sock {
    u32 last_oow_ack_time;
};

struct net;

static u32 challenge_timestamp;
static unsigned int challenge_count;

#define HZ 100
#define LINUX_MIB_TCPACKSKIPPEDCHALLENGE 0
#define LINUX_MIB_TCPCHALLENGEACK 0
#define sysctl_tcp_challenge_ack_limit 100

static inline struct tcp_sock* tcp_sk(const struct sock* sk) { return (struct tcp_sock*)sk; }
static inline struct net* sock_net(const struct sock* sk) { return (struct net*)0; }
static int tcp_oow_rate_limited(struct net* net, const struct sk_buff* skb, int mib, u32* time) { return 0; }
static void tcp_send_ack(struct sock* sk) {}
static unsigned long jiffies;
#define NET_INC_STATS(net, mib) {}