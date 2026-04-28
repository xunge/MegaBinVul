#include <stddef.h>
#include <stdbool.h>

struct inet_frag_queue {
    void *net;
    unsigned int last_in;
    void *fragments;
    void *lock;
};

struct ipq {
    struct inet_frag_queue q;
    int iif;
    int user;
};

struct net {
    struct {
        void *frags;
    } ipv4;
};

struct sk_buff {
    void *dev;
    void *dst;
};

struct iphdr {
    unsigned char tos;
    unsigned int daddr;
    unsigned int saddr;
};

struct rtable {
    int rt_type;
};

#define INET_FRAG_COMPLETE 0x01
#define INET_FRAG_FIRST_IN 0x02
#define IP_DEFRAG_CONNTRACK_IN 0
#define IPSTATS_MIB_REASMTIMEOUT 0
#define IPSTATS_MIB_REASMFAILS 0
#define ICMP_TIME_EXCEEDED 11
#define ICMP_EXC_FRAGTIME 1
#define RTN_LOCAL 1

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define unlikely(x) (x)
#define IP_INC_STATS_BH(net, field) do {} while (0)

static inline void spin_lock(void *lock) {}
static inline void spin_unlock(void *lock) {}
static inline void rcu_read_lock(void) {}
static inline void rcu_read_unlock(void) {}
static inline void ipq_kill(struct ipq *qp) {}
static inline void ipq_put(struct ipq *qp) {}
static inline void *dev_get_by_index_rcu(struct net *net, int iif) { return NULL; }
static inline struct iphdr *ip_hdr(struct sk_buff *skb) { return NULL; }
static inline int ip_route_input(struct sk_buff *skb, unsigned int daddr, 
                               unsigned int saddr, unsigned char tos, void *dev) { return 0; }
static inline void *skb_dst(struct sk_buff *skb) { return skb->dst; }
static inline struct rtable *skb_rtable(struct sk_buff *skb) { return (struct rtable *)skb->dst; }
static inline void icmp_send(struct sk_buff *skb, int type, int code, int info) {}