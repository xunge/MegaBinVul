struct devlink;
struct notifier_block {
    int (*notifier_call)(struct notifier_block *, unsigned long, void *);
    struct notifier_block *next;
    int priority;
};
struct work_struct {
    unsigned long data;
};
struct rhashtable {
    unsigned int size;
};
struct list_head {
    struct list_head *next, *prev;
};
struct mutex {
    void *lock;
};

enum {
    NSIM_RESOURCE_IPV4_FIB,
    NSIM_RESOURCE_IPV4_FIB_RULES,
    NSIM_RESOURCE_IPV6_FIB,
    NSIM_RESOURCE_IPV6_FIB_RULES,
    NSIM_RESOURCE_NEXTHOPS,
};

struct nsim_fib_data {
    struct notifier_block fib_nb;
    struct notifier_block nexthop_nb;
    struct work_struct fib_flush_work;
    struct work_struct fib_event_work;
    struct rhashtable fib_rt_ht;
    struct rhashtable nexthop_ht;
    struct list_head fib_event_queue;
    struct list_head fib_rt_list;
    struct mutex fib_lock;
    struct mutex nh_lock;
};

void devlink_resource_occ_get_unregister(struct devlink *devlink, int id);
void unregister_fib_notifier(void *net, struct notifier_block *nb);
void unregister_nexthop_notifier(void *net, struct notifier_block *nb);
void cancel_work_sync(struct work_struct *work);
void flush_work(struct work_struct *work);
void rhashtable_free_and_destroy(struct rhashtable *ht, void (*free_fn)(void *, void *), void *arg);
void nsim_fib_rt_free(void *ptr, void *arg);
void nsim_nexthop_free(void *ptr, void *arg);
void WARN_ON_ONCE(int condition);
void mutex_destroy(struct mutex *lock);
void nsim_fib_debugfs_exit(struct nsim_fib_data *data);
void kfree(const void *objp);
void *devlink_net(struct devlink *devlink);
int list_empty(const struct list_head *head);