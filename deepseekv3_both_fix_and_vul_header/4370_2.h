struct t3cdev {
    void *ulp;
};

struct cxio_rdev;
struct l2t_entry;
struct sk_buff;

extern int l2t_send(struct t3cdev *tdev, struct sk_buff *skb, struct l2t_entry *l2e);
extern int cxio_fatal_error(struct cxio_rdev *rdev);
extern void kfree_skb(struct sk_buff *skb);

#define EIO 5