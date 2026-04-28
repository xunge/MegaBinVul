#include <stdlib.h>
#include <stdint.h>

#define MLD_MAX_SKBS 64
#define EINVAL 22
#define ENODEV 19

struct sk_buff {
    void *dev;
};

struct sk_buff_head {
    int dummy;
};

struct delayed_work {
    int dummy;
};

struct inet6_dev {
    int dead;
    struct sk_buff_head mc_query_queue;
    int mc_query_lock;
    struct delayed_work mc_query_work;
};

struct workqueue_struct {
    int dummy;
};

extern struct workqueue_struct *mld_wq;
extern struct inet6_dev *__in6_dev_get(const void *dev);
extern void in6_dev_hold(struct inet6_dev *idev);
extern void spin_lock_bh(int *lock);
extern void spin_unlock_bh(int *lock);
extern int skb_queue_len(struct sk_buff_head *queue);
extern void __skb_queue_tail(struct sk_buff_head *queue, struct sk_buff *skb);
extern int mod_delayed_work(struct workqueue_struct *wq, struct delayed_work *dwork, unsigned long delay);
extern void kfree_skb(struct sk_buff *skb);