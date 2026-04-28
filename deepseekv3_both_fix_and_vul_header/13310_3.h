#include <stddef.h>
#include <stdlib.h>

#define GFP_KERNEL 0
#define ENOMEM 12
#define ERR_PTR(err) ((void *)(long)(err))
#define pr_err(fmt, ...)

struct mutex {
    int dummy;
};

struct rhashtable {
    int dummy;
};

struct list_head {
    struct list_head *next, *prev;
};

struct spinlock {
    int dummy;
};

struct work_struct {
    int dummy;
};

struct notifier_block {
    int (*notifier_call)(struct notifier_block *, unsigned long, void *);
};

struct devlink;
struct netlink_ext_ack;
struct nsim_dev;

struct nsim_nexthop_ht_params {
    unsigned int key_len;
    unsigned int key_offset;
    unsigned int head_offset;
    unsigned int hashfn;
    unsigned int obj_hashfn;
    unsigned int obj_cmpfn;
};

struct nsim_fib_rt_ht_params {
    unsigned int key_len;
    unsigned int key_offset;
    unsigned int head_offset;
    unsigned int hashfn;
    unsigned int obj_hashfn;
    unsigned int obj_cmpfn;
};

struct nsim_fib_data {
    struct devlink *devlink;
    struct mutex nh_lock;
    struct rhashtable nexthop_ht;
    struct mutex fib_lock;
    struct list_head fib_rt_list;
    struct rhashtable fib_rt_ht;
    struct work_struct fib_event_work;
    struct work_struct fib_flush_work;
    struct list_head fib_event_queue;
    struct spinlock fib_event_queue_lock;
    struct notifier_block nexthop_nb;
    struct notifier_block fib_nb;
};

static struct nsim_nexthop_ht_params nsim_nexthop_ht_params;
static struct nsim_fib_rt_ht_params nsim_fib_rt_ht_params;

extern struct nsim_dev *devlink_priv(struct devlink *devlink);
extern void *kzalloc(size_t size, int flags);
extern void kfree(void *ptr);
extern void mutex_init(struct mutex *lock);
extern void mutex_destroy(struct mutex *lock);
extern int rhashtable_init(struct rhashtable *ht, const void *params);
extern void rhashtable_free_and_destroy(struct rhashtable *ht, void (*free_fn)(void *ptr, void *arg), void *arg);
extern void INIT_LIST_HEAD(struct list_head *list);
extern void INIT_WORK(struct work_struct *work, void (*func)(struct work_struct *work));
extern void spin_lock_init(struct spinlock *lock);
extern void flush_work(struct work_struct *work);
extern void cancel_work_sync(struct work_struct *work);
extern int register_nexthop_notifier(void *net, struct notifier_block *nb, struct netlink_ext_ack *extack);
extern int unregister_nexthop_notifier(void *net, struct notifier_block *nb);
extern int register_fib_notifier(void *net, struct notifier_block *nb, int (*dump_fn)(struct notifier_block *nb, struct netlink_ext_ack *extack), struct netlink_ext_ack *extack);
extern void *devlink_net(struct devlink *devlink);
extern void devlink_resource_occ_get_register(struct devlink *devlink, unsigned int resource_id, unsigned long long (*occ_get)(void *), void *priv);

extern int nsim_fib_debugfs_init(struct nsim_fib_data *data, struct nsim_dev *nsim_dev);
extern void nsim_fib_debugfs_exit(struct nsim_fib_data *data);
extern void nsim_fib_set_max_all(struct nsim_fib_data *data, struct devlink *devlink);
extern int nsim_nexthop_event_nb(struct notifier_block *nb, unsigned long event, void *ptr);
extern int nsim_fib_event_nb(struct notifier_block *nb, unsigned long event, void *ptr);
extern int nsim_fib_dump_inconsistent(struct notifier_block *nb, struct netlink_ext_ack *extack);
extern void nsim_fib_event_work(struct work_struct *work);
extern void nsim_fib_flush_work(struct work_struct *work);
extern void nsim_fib_rt_free(void *ptr, void *arg);
extern void nsim_nexthop_free(void *ptr, void *arg);
extern unsigned long long nsim_fib_ipv4_resource_occ_get(void *priv);
extern unsigned long long nsim_fib_ipv4_rules_res_occ_get(void *priv);
extern unsigned long long nsim_fib_ipv6_resource_occ_get(void *priv);
extern unsigned long long nsim_fib_ipv6_rules_res_occ_get(void *priv);
extern unsigned long long nsim_fib_nexthops_res_occ_get(void *priv);

enum {
    NSIM_RESOURCE_IPV4_FIB,
    NSIM_RESOURCE_IPV4_FIB_RULES,
    NSIM_RESOURCE_IPV6_FIB,
    NSIM_RESOURCE_IPV6_FIB_RULES,
    NSIM_RESOURCE_NEXTHOPS
};