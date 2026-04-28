#include <stdbool.h>
#include <stddef.h>

struct sk_buff {
    struct net_device *dev;
};

struct net_device;

struct sk_buff_head {
    int dummy;
};

struct delayed_work {
    int dummy;
};

struct inet6_dev {
    bool dead;
    int mc_report_lock;
    struct sk_buff_head mc_report_queue;
    struct delayed_work mc_report_work;
};

#define MLD_MAX_SKBS 64
#define EINVAL 22
#define ENODEV 19

extern struct workqueue_struct *mld_wq;
extern struct inet6_dev *__in6_dev_get(const struct net_device *dev);
extern void in6_dev_hold(struct inet6_dev *idev);
extern void kfree_skb(struct sk_buff *skb);
extern int skb_queue_len(const struct sk_buff_head *list);
extern void __skb_queue_tail(struct sk_buff_head *list, struct sk_buff *skb);
extern bool mod_delayed_work(struct workqueue_struct *wq, struct delayed_work *dwork, unsigned long delay);
extern void spin_lock_bh(int *lock);
extern void spin_unlock_bh(int *lock);