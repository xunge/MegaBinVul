#include <stdint.h>
#include <string.h>

typedef uint32_t u32;
typedef uint16_t u16;

#define AF_UNSPEC 0
#define IFNAMSIZ 16
#define RTM_DELTFILTER 0
#define TCA_KIND 1

struct sk_buff {
    unsigned char *data;
    unsigned char *tail;
    int len;
};

struct net_device {
    int ifindex;
};

struct Qdisc {
    struct net_device *dev;
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

struct tcf_proto;

struct tcf_proto_ops {
    char kind[IFNAMSIZ];
    int (*dump)(struct tcf_proto *, unsigned long, struct sk_buff *, struct tcmsg *);
};

struct tcf_proto {
    struct Qdisc *q;
    uint32_t classid;
    uint32_t prio;
    uint32_t protocol;
    struct tcf_proto_ops *ops;
};

struct nlmsghdr {
    uint32_t nlmsg_len;
};

static inline void skb_trim(struct sk_buff *skb, unsigned int len) {
    skb->tail = skb->data + len;
    skb->len = len;
}

#define NLMSG_NEW(skb, pid, seq, type, len, flags) \
    ({ struct nlmsghdr *__nlh = (struct nlmsghdr *)skb->tail; \
       __nlh->nlmsg_len = NLMSG_LENGTH(len); \
       skb->tail += NLMSG_ALIGN(__nlh->nlmsg_len); \
       __nlh; })

#define NLMSG_DATA(nlh) ((void*)(((char*)nlh) + NLMSG_LENGTH(0)))
#define RTA_PUT(skb, attrtype, attrlen, data) \
    ({ memcpy(skb->tail, data, attrlen); skb->tail += attrlen; skb->len += attrlen; 0; })
#define TC_H_MAKE(maj,min) (((maj) << 16) | (min))
#define NLMSG_LENGTH(len) ((len) + sizeof(struct nlmsghdr))
#define NLMSG_ALIGN(len) (((len) + 3) & ~3)