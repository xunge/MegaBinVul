#include <stdint.h>

typedef uint32_t u32;
typedef uint16_t u16;

struct sk_buff {
    unsigned char *data;
    unsigned int len;
    unsigned char *tail;
};

struct net_device {
    int ifindex;
};

struct Qdisc {
    struct net_device *dev;
};

struct tcf_proto {
    struct Qdisc *q;
    unsigned long classid;
    unsigned int prio;
    unsigned int protocol;
    struct tcf_proto_ops *ops;
};

struct tcf_proto_ops {
    const char *kind;
    int (*dump)(struct tcf_proto *, unsigned long, struct sk_buff *, void *);
};

struct nlmsghdr {
    uint32_t nlmsg_len;
};

struct tcmsg {
    unsigned char tcm_family;
    unsigned char tcm__pad1;
    unsigned short tcm__pad2;
    int tcm_ifindex;
    uint32_t tcm_handle;
    uint32_t tcm_parent;
    uint32_t tcm_info;
};

#define AF_UNSPEC 0
#define TCA_KIND 1
#define TC_H_MAKE(prio, protocol) (((prio) << 16) | (protocol))
#define NLMSG_NEW(skb, pid, seq, type, len, flags) \
    ({ (void)(pid); (void)(seq); (void)(type); (void)(len); (void)(flags); \
       (struct nlmsghdr *)((skb)->tail); })
#define NLMSG_DATA(nlh) ((void *)((char *)(nlh) + sizeof(struct nlmsghdr)))
#define NLA_PUT_STRING(skb, attrtype, attrdata) (0)
#define RTM_DELTFILTER 0

static inline unsigned char *skb_tail_pointer(const struct sk_buff *skb) {
    return skb->tail;
}

static inline void nlmsg_trim(struct sk_buff *skb, unsigned char *b) {
    skb->tail = b;
}

static inline struct net_device *qdisc_dev(const struct Qdisc *q) {
    return q->dev;
}