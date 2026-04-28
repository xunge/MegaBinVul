#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct work_struct {
    struct list_head entry;
};

struct net;
struct pernet_operations {
    void (*exit)(struct net *net);
    struct list_head list;
};

struct net {
    struct list_head list;
    struct list_head cleanup_list;
    struct work_struct work;
};

struct mutex {
    int dummy;
};

struct spinlock {
    int dummy;
};

extern struct list_head cleanup_list;
extern struct list_head pernet_list;
extern struct list_head *first_device;
extern struct mutex net_mutex;
extern struct spinlock cleanup_list_lock;

void net_free(struct net *net);
void unregister_netdevices(struct net *net, struct list_head *dev_kill_list);
void unregister_netdevice_many(struct list_head *dev_kill_list);
void spin_lock_irq(struct spinlock *lock);
void spin_unlock_irq(struct spinlock *lock);
void mutex_lock(struct mutex *lock);
void mutex_unlock(struct mutex *lock);
void rtnl_lock(void);
void rtnl_unlock(void);
void synchronize_rcu(void);
void rcu_barrier(void);
void list_del_rcu(struct list_head *entry);
void list_del_init(struct list_head *entry);
void list_replace_init(struct list_head *old, struct list_head *new);

#define LIST_HEAD(name) struct list_head name = { &(name), &(name) }
#define list_for_each_entry(pos, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = container_of(pos->member.next, typeof(*pos), member))
#define list_for_each_entry_reverse(pos, head, member) \
    for (pos = container_of((head)->prev, typeof(*pos), member); \
         &pos->member != (head); \
         pos = container_of(pos->member.prev, typeof(*pos), member))
#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member), \
         n = container_of(pos->member.next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = n, n = container_of(n->member.next, typeof(*n), member))
#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))