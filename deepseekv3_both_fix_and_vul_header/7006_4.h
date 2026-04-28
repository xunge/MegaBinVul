#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;

struct Qdisc_ops {
    void (*attach)(struct Qdisc *);
    struct Qdisc_class_ops *cl_ops;
};

struct Qdisc_class_ops {
    unsigned long (*find)(struct Qdisc *, u32);
    int (*graft)(struct Qdisc *, unsigned long, struct Qdisc *, struct Qdisc **,
                 struct netlink_ext_ack *);
};

struct Qdisc {
    unsigned int flags;
    struct Qdisc_ops *ops;
};

struct net_device {
    unsigned int num_tx_queues;
    unsigned int flags;
    struct Qdisc *qdisc;
};

struct netdev_queue;
struct net;
struct nlmsghdr;
struct sk_buff;
struct netlink_ext_ack;

extern struct Qdisc noop_qdisc;
extern struct Qdisc_ops noqueue_qdisc_ops;

#define TCQ_F_INGRESS 0x1
#define TCQ_F_NOLOCK 0x2
#define IFF_UP 0x1
#define ENOENT 2
#define EOPNOTSUPP 95
#define EINVAL 22

static inline struct net *dev_net(struct net_device *dev) { return NULL; }
static inline struct netdev_queue *dev_ingress_queue(struct net_device *dev) { return NULL; }
static inline void NL_SET_ERR_MSG(struct netlink_ext_ack *extack, const char *msg) {}
static inline void dev_deactivate(struct net_device *dev) {}
static inline void qdisc_offload_graft_root(struct net_device *dev, struct Qdisc *new, 
                                          struct Qdisc *old, struct netlink_ext_ack *extack) {}
static inline struct netdev_queue *netdev_get_tx_queue(struct net_device *dev, int i) { return NULL; }
static inline struct Qdisc *dev_graft_qdisc(struct netdev_queue *dev_queue, struct Qdisc *new) { return NULL; }
static inline void qdisc_refcount_inc(struct Qdisc *q) {}
static inline void qdisc_put(struct Qdisc *q) {}
static inline struct Qdisc *rtnl_dereference(struct Qdisc *q) { return q; }
static inline void rcu_assign_pointer(struct Qdisc *q, struct Qdisc *new) {}
static inline void notify_and_destroy(struct net *net, struct sk_buff *skb, 
                                    struct nlmsghdr *n, u32 classid, 
                                    struct Qdisc *old, struct Qdisc *new) {}
static inline void dev_activate(struct net_device *dev) {}
static inline void qdisc_clear_nolock(struct Qdisc *q) {}