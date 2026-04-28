#include <stddef.h>

struct kobject {
    void *kset;
};

struct netdev_queue {
    struct kobject kobj;
    struct net_device *dev;
};

struct net_device {
    struct netdev_queue *_tx;
    struct kobject *queues_kset;
};

struct kobj_type;
struct attribute_group;

extern struct kobj_type netdev_queue_ktype;
extern struct attribute_group dql_group;

int kobject_init_and_add(struct kobject *, struct kobj_type *, void *, const char *, ...);
int sysfs_create_group(struct kobject *, struct attribute_group *);
void kobject_put(struct kobject *);
void kobject_uevent(struct kobject *, int);
void dev_hold(struct net_device *);

#define KOBJ_ADD 0
#define CONFIG_BQL 1