#include <stdlib.h>

struct kobject {
    // Minimal kobject definition
    const char *name;
    struct kset *kset;
};

struct kset {
    // Minimal kset definition
    struct kobject kobj;
};

struct net_device {
    struct {
        struct kobject kobj;
    } dev;
    struct kset *queues_kset;
    unsigned int real_num_rx_queues;
    unsigned int real_num_tx_queues;
};

#define CONFIG_SYSFS
#define ENOMEM 12

struct kset *kset_create_and_add(const char *name, void *null, struct kobject *kobj);
int net_rx_queue_update_kobjects(struct net_device *dev, int start, int count);
int netdev_queue_update_kobjects(struct net_device *dev, int start, int count);