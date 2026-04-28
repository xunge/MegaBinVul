#include <stdlib.h>
#include <errno.h>

struct t3cdev {
    void *ulp;
};

struct cxio_rdev;
struct sk_buff;

int cxio_fatal_error(struct cxio_rdev *rdev);
int cxgb3_ofld_send(struct t3cdev *tdev, struct sk_buff *skb);
void kfree_skb(struct sk_buff *skb);

#define EIO 5