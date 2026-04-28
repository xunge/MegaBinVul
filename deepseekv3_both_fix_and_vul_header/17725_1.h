#include <stddef.h>

struct kobject {
    void *kset;
};

struct attribute_group;

struct kset;

struct kobj_type;

struct netdev_rx_queue {
    struct kobject kobj;
    void *dev;
};

struct net_device {
    struct netdev_rx_queue *_rx;
    struct kset *queues_kset;
    const struct attribute_group *sysfs_rx_queue_group;
};

extern const struct kobj_type rx_queue_ktype;
extern int kobject_init_and_add(struct kobject *, const struct kobj_type *, void *, const char *, unsigned int);
extern void kobject_put(struct kobject *);
extern int sysfs_create_group(struct kobject *, const struct attribute_group *);
extern void kobject_uevent(struct kobject *, int);
extern void dev_hold(void *);

#define KOBJ_ADD 0