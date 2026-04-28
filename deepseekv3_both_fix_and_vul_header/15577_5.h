#include <stdbool.h>
#include <errno.h>

struct Qdisc {
    struct netdev_queue *dev_queue;
    unsigned int handle;
    void *priv;
};

struct nlattr;
struct netlink_ext_ack;
struct net_device;
struct netdev_queue {
    int dummy;
};
struct sk_buff;

struct qdisc_watchdog {
    int dummy;
};

struct pfifo_qdisc_ops {
    int dummy;
};

extern struct pfifo_qdisc_ops pfifo_qdisc_ops;

struct cbs_sched_data {
    struct Qdisc *qdisc;
    struct netdev_queue *queue;
    bool offload;
    struct qdisc_watchdog watchdog;
    int (*enqueue)(struct sk_buff *skb, struct Qdisc *sch, struct sk_buff **to_free);
    struct sk_buff *(*dequeue)(struct Qdisc *sch);
    struct cbs_sched_data *cbs_list;
};

extern struct cbs_sched_data *cbs_list;
extern int cbs_list_lock;

static inline struct cbs_sched_data *qdisc_priv(struct Qdisc *sch) {
    return (struct cbs_sched_data *)sch->priv;
}

static inline struct net_device *qdisc_dev(struct Qdisc *sch) {
    return (struct net_device *)0;
}

#define NL_SET_ERR_MSG(extack, msg) do {} while(0)

static inline struct Qdisc *qdisc_create_dflt(struct netdev_queue *dev_queue,
                                            struct pfifo_qdisc_ops *ops,
                                            unsigned int handle,
                                            struct netlink_ext_ack *extack) {
    return (struct Qdisc *)0;
}

static inline void qdisc_hash_add(struct Qdisc *qdisc, bool invisible) {}

static inline struct netdev_queue *netdev_get_tx_queue(struct net_device *dev, int index) {
    return (struct netdev_queue *)0;
}

static inline void qdisc_watchdog_init(struct qdisc_watchdog *wd, struct Qdisc *sch) {}

static inline int cbs_change(struct Qdisc *sch, struct nlattr *opt,
                           struct netlink_ext_ack *extack) {
    return 0;
}

static inline void spin_lock(int *lock) {}
static inline void spin_unlock(int *lock) {}
static inline void list_add(struct cbs_sched_data **list, struct cbs_sched_data **head) {}

int cbs_enqueue_soft(struct sk_buff *skb, struct Qdisc *sch, struct sk_buff **to_free);
struct sk_buff *cbs_dequeue_soft(struct Qdisc *sch);