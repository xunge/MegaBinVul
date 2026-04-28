#include <stdint.h>

typedef uint32_t u32;
typedef uint16_t u16;

struct sk_buff {
    unsigned char* data;
    u32 len;
};

struct nlmsghdr {
    u32 nlmsg_len;
};

struct tcmsg {
    u32 tcm_family;
    u32 tcm__pad1;
    u32 tcm__pad2;
    int tcm_ifindex;
    u32 tcm_parent;
    u32 tcm_handle;
    u32 tcm_info;
};

struct gnet_dump {
    int dummy;
};

struct net_device {
    int ifindex;
};

struct Qdisc;
struct Qdisc_class_ops {
    int (*dump)(struct Qdisc *, unsigned long, struct sk_buff *, struct tcmsg *);
    int (*dump_stats)(struct Qdisc *, unsigned long, struct gnet_dump *);
};

struct Qdisc_ops {
    const char *id;
    const struct Qdisc_class_ops *cl_ops;
};

struct Qdisc {
    struct Qdisc_ops *ops;
    u32 handle;
    struct net_device *dev;
};

#define AF_UNSPEC 0
#define TCA_KIND 1
#define TCA_STATS 2
#define TCA_STATS2 3
#define TCA_XSTATS 4

static inline struct net_device *qdisc_dev(struct Qdisc *q) { return q->dev; }
static inline void *qdisc_root_sleeping_lock(struct Qdisc *q) { return 0; }
static inline int gnet_stats_start_copy_compat(struct sk_buff *skb, int a, int b, int c, void *d, struct gnet_dump *e) { return 0; }
static inline int gnet_stats_finish_copy(struct gnet_dump *d) { return 0; }

#define NLMSG_NEW(skb, pid, seq, type, len, flags) ((struct nlmsghdr*)0)
#define NLMSG_DATA(nlh) ((struct tcmsg*)0)
#define NLA_PUT_STRING(skb, attrtype, attrlen) 0
#define nlmsg_trim(skb, b) do {} while (0)
#define skb_tail_pointer(skb) ((unsigned char *)0)