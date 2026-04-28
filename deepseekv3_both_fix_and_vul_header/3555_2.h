#include <stdint.h>
#include <stddef.h>

#define TCA_MAX 16
#define CAP_NET_ADMIN 12
#define EPERM 1
#define ENODEV 19
#define EINVAL 22
#define ENOENT 2
#define EEXIST 17
#define EOPNOTSUPP 95
#define RTM_GETTCLASS 42
#define RTM_NEWTCLASS 40
#define RTM_DELTCLASS 41
#define NLM_F_CREATE 0x400
#define NLM_F_EXCL 0x200
#define TC_H_ROOT 0xFFFFFFFF
#define TC_H_MAJ(h) ((h)&0xFFFF0000)
#define TC_H_MAKE(maj,min) (((maj)&0xFFFF)<<16|((min)&0xFFFF))

typedef uint32_t u32;

struct sk_buff {
    void *sk;
};

struct nlmsghdr {
    int nlmsg_type;
    int nlmsg_flags;
};

struct tcmsg {
    u32 tcm_ifindex;
    u32 tcm_parent;
    u32 tcm_handle;
};

struct nlattr;

struct net;

struct net_device {
    struct Qdisc *qdisc;
};

struct Qdisc_ops {
    const struct Qdisc_class_ops *cl_ops;
};

struct Qdisc {
    u32 handle;
    struct Qdisc_ops *ops;
};

struct Qdisc_class_ops {
    unsigned long (*get)(struct Qdisc *, u32);
    int (*delete)(struct Qdisc *, unsigned long);
    int (*change)(struct Qdisc *, u32, u32, struct nlattr **, unsigned long *);
    void (*put)(struct Qdisc *, unsigned long);
};

static inline struct net *sock_net(void *sk) { return NULL; }
static inline struct tcmsg *nlmsg_data(struct nlmsghdr *n) { return NULL; }
static inline int nlmsg_parse(struct nlmsghdr *n, int size, struct nlattr **tca, int max, void *arg) { return 0; }
static inline struct net_device *__dev_get_by_index(struct net *net, u32 ifindex) { return NULL; }
static inline struct Qdisc *qdisc_lookup(struct net_device *dev, u32 qid) { return NULL; }
static inline int tclass_notify(struct net *net, struct sk_buff *skb, struct nlmsghdr *n, struct Qdisc *q, unsigned long cl, int type) { return 0; }
static inline int capable(int cap) { return 0; }