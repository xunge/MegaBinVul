#include <stddef.h>
#include <stdint.h>

#define TCA_MAX 16
#define TCA_KIND 1
#define TC_H_ROOT 0xFFFFFFFF
#define TC_H_INGRESS 0xFFFFFFF1
#define TC_H_MAJ(h) ((h)&0xFFFF0000U)
#define TC_H_MIN(h) ((h)&0x0000FFFFU)
#define CAP_NET_ADMIN 12
#define NLM_F_REPLACE 0x100
#define NLM_F_EXCL 0x200
#define NLM_F_CREATE 0x400
#define EPERM 1
#define ENODEV 19
#define ENOENT 2
#define EEXIST 17
#define EINVAL 22
#define ELOOP 40
#define EAGAIN 11

typedef uint32_t u32;

struct net;
struct sk_buff {
    void *sk;
};
struct nlmsghdr {
    uint32_t nlmsg_flags;
};
struct net_device {
    struct Qdisc *qdisc;
};
struct tcmsg {
    uint8_t tcm_family;
    uint8_t tcm__pad1;
    uint16_t tcm__pad2;
    uint32_t tcm_ifindex;
    uint32_t tcm_handle;
    uint32_t tcm_parent;
    uint32_t tcm_info;
};
struct Qdisc_class_ops {
    struct netdev_queue* (*select_queue)(struct Qdisc*, struct tcmsg*);
};
struct Qdisc_ops {
    const char *id;
    struct Qdisc_class_ops *cl_ops;
};
struct Qdisc {
    struct Qdisc_ops *ops;
    struct netdev_queue *dev_queue;
    u32 handle;
    int refcnt;
};
struct netdev_queue {
    struct Qdisc *qdisc_sleeping;
};
struct nlattr {
    uint16_t nla_len;
    uint16_t nla_type;
};

static inline int capable(int cap) { return 1; }
static inline struct net *sock_net(void *sk) { return NULL; }
static inline int nlmsg_parse(struct nlmsghdr *n, int len, struct nlattr *tb[], int maxtype, void *policy) { return 0; }
static inline void *nlmsg_data(struct nlmsghdr *n) { return NULL; }
static inline struct net_device *__dev_get_by_index(struct net *net, int ifindex) { return NULL; }
static inline struct Qdisc *qdisc_lookup(struct net_device *dev, uint32_t handle) { return NULL; }
static inline struct Qdisc *qdisc_leaf(struct Qdisc *p, uint32_t clid) { return NULL; }
static inline int dev_ingress_queue_create(struct net_device *dev) { return 0; }
static inline struct netdev_queue *dev_ingress_queue(struct net_device *dev) { return NULL; }
static inline int check_loop(struct Qdisc *q, struct Qdisc *p, int depth) { return 0; }
static inline void atomic_inc(int *v) { (*v)++; }
static inline int nla_strcmp(struct nlattr *nla, const char *str) { return 0; }
static inline int qdisc_change(struct Qdisc *q, struct nlattr *tca[]) { return 0; }
static inline void qdisc_notify(struct net *net, struct sk_buff *skb, struct nlmsghdr *n, uint32_t clid, void *old, struct Qdisc *new) {}
static inline struct Qdisc *qdisc_create(struct net_device *dev, struct netdev_queue *dev_queue, struct Qdisc *p, uint32_t parent, uint32_t handle, struct nlattr *tca[], int *err) { return NULL; }
static inline int qdisc_graft(struct net_device *dev, struct Qdisc *p, struct sk_buff *skb, struct nlmsghdr *n, uint32_t clid, struct Qdisc *new, struct Qdisc *old) { return 0; }
static inline void qdisc_destroy(struct Qdisc *q) {}
static inline struct netdev_queue *netdev_get_tx_queue(struct net_device *dev, int index) { return NULL; }