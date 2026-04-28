#include <stdint.h>
#include <stdatomic.h>

typedef uint32_t u32;
typedef uint16_t u16;

struct sk_buff {
    unsigned char *data;
    unsigned char *tail;
    int len;
};

struct gnet_stats_basic {
    uint64_t bytes;
    uint32_t packets;
};

struct gnet_stats_queue {
    uint32_t qlen;
    uint32_t backlog;
    uint32_t drops;
    uint32_t requeues;
    uint32_t overlimits;
};

struct gnet_stats_rate_est {
    uint32_t bps;
    uint32_t pps;
};

struct net_device {
    int ifindex;
};

struct Qdisc_ops {
    char *id;
    int (*dump)(struct Qdisc *, struct sk_buff *);
    int (*dump_stats)(struct Qdisc *, struct gnet_dump *);
};

struct Qdisc {
    struct net_device *dev;
    u32 handle;
    _Atomic uint32_t refcnt;
    struct Qdisc_ops *ops;
    struct gnet_stats_basic bstats;
    struct gnet_stats_queue qstats;
    struct gnet_stats_queue q;
    struct spinlock *stats_lock;
#ifdef CONFIG_NET_ESTIMATOR
    struct gnet_stats_rate_est rate_est;
#endif
};

struct tcmsg {
    unsigned char tcm_family;
    unsigned char tcm__pad1;
    unsigned short tcm__pad2;
    int tcm_ifindex;
    u32 tcm_parent;
    u32 tcm_handle;
    u32 tcm_info;
};

struct nlmsghdr {
    u32 nlmsg_len;
    u16 nlmsg_type;
    u16 nlmsg_flags;
    u32 nlmsg_seq;
    u32 nlmsg_pid;
};

struct gnet_dump {
    int dummy;
};

struct spinlock {
    int lock;
};

#define NLMSG_NEW(skb, pid, seq, type, len, flags) \
    ({ struct nlmsghdr *__nlh = (struct nlmsghdr *)skb->tail; \
       __nlh->nlmsg_len = NLMSG_LENGTH(len); \
       __nlh->nlmsg_type = type; \
       __nlh->nlmsg_flags = flags; \
       __nlh->nlmsg_seq = seq; \
       __nlh->nlmsg_pid = pid; \
       skb->tail += NLMSG_ALIGN(__nlh->nlmsg_len); \
       __nlh; })

#define NLMSG_LENGTH(len) ((len) + NLMSG_HDRLEN)
#define NLMSG_HDRLEN ((int)sizeof(struct nlmsghdr))
#define NLMSG_ALIGN(len) (((len) + 3) & ~3)
#define NLMSG_DATA(nlh) ((void*)((char*)(nlh) + NLMSG_HDRLEN))

#define RTA_PUT(skb, attrtype, attrlen, data) \
    ({ if (0) goto rtattr_failure; 0; })

#define TCA_KIND 1
#define TCA_STATS 2
#define TCA_STATS2 3
#define TCA_XSTATS 4
#define IFNAMSIZ 16
#define AF_UNSPEC 0

static inline uint32_t atomic_read(const _Atomic uint32_t *v) {
    return *v;
}

int gnet_stats_start_copy_compat(struct sk_buff *skb, int type1, int type2, int type3, struct spinlock *lock, struct gnet_dump *d);
int gnet_stats_copy_basic(struct gnet_dump *d, struct gnet_stats_basic *b);
int gnet_stats_copy_rate_est(struct gnet_dump *d, struct gnet_stats_rate_est *r);
int gnet_stats_copy_queue(struct gnet_dump *d, struct gnet_stats_queue *q);
int gnet_stats_finish_copy(struct gnet_dump *d);
void skb_trim(struct sk_buff *skb, int len);