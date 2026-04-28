#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;

struct sk_buff {
    void *sk;
};

struct nlmsghdr {
    int nlmsg_type;
};

struct tcmsg {
    int tcm_ifindex;
    u32 tcm_parent;
    u32 tcm_handle;
};

struct nlattr;

struct net_device {
    struct Qdisc *qdisc;
};

struct Qdisc {
    u32 handle;
    struct Qdisc_ops *ops;
};

struct Qdisc_ops {
    const char *id;
};

struct net;

struct ingress_queue {
    struct Qdisc *qdisc_sleeping;
};

#define TCA_MAX 16
#define TCA_KIND 1
#define CAP_NET_ADMIN 12
#define EPERM 1
#define ENODEV 19
#define ENOENT 2
#define EINVAL 22

#define RTM_GETQDISC 1
#define RTM_DELQDISC 2
#define TC_H_ROOT 0xFFFFFFFF
#define TC_H_INGRESS 0xFFFFFFF1
#define TC_H_MAJ(h) ((h) & 0xFFFF0000)

static inline struct net* sock_net(void* sk) { return (struct net*)0; }
static inline struct tcmsg* nlmsg_data(struct nlmsghdr* n) { return (struct tcmsg*)0; }
static inline int capable(int cap) { return 0; }
static inline int nlmsg_parse(struct nlmsghdr* n, int size, struct nlattr** tca, int max, void* null) { return 0; }
static inline struct net_device* __dev_get_by_index(struct net* net, int index) { return (struct net_device*)0; }
static inline struct Qdisc* qdisc_lookup(struct net_device* dev, u32 handle) { return (struct Qdisc*)0; }
static inline struct Qdisc* qdisc_leaf(struct Qdisc* p, u32 clid) { return (struct Qdisc*)0; }
static inline struct ingress_queue* dev_ingress_queue(struct net_device* dev) { return (struct ingress_queue*)0; }
static inline int nla_strcmp(struct nlattr* attr, const char* str) { return 0; }
static inline int qdisc_graft(struct net_device* dev, struct Qdisc* p, struct sk_buff* skb, struct nlmsghdr* n, u32 clid, void* null, struct Qdisc* q) { return 0; }
static inline void qdisc_notify(struct net* net, struct sk_buff* skb, struct nlmsghdr* n, u32 clid, void* null, struct Qdisc* q) {}