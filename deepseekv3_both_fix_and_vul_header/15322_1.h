#include <linux/connector.h>

struct cn_dev {
    void *cbdev;
};

struct cn_dev cdev;

void cn_queue_del_callback(void *cbdev, struct cb_id *id);
void cn_notify(struct cb_id *id, int status);