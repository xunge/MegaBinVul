#include <linux/connector.h>
#include <linux/errno.h>
#include <stdbool.h>

struct cn_msg;
struct netlink_skb_parms;
struct cn_dev {
    void *cbdev;
};

extern struct cn_dev cdev;
extern bool cn_already_initialized;

int cn_queue_add_callback(void *cbdev, char *name, struct cb_id *id, 
                         void (*callback)(struct cn_msg *, struct netlink_skb_parms *));
int cn_notify(struct cb_id *id, int val);