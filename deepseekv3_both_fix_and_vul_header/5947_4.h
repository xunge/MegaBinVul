#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct net {
    struct list_head list;
    struct list_head cleanup_list;
};

struct pernet_operations {
    struct list_head list;
    void (*exit)(struct net *net);
    size_t size;
    int *id;
};

struct work_struct;

typedef struct {
    int lock;
} spinlock_t;

extern spinlock_t cleanup_list_lock;
extern struct list_head cleanup_list;
extern struct {
    int lock;
} net_mutex;
extern struct list_head pernet_list;
extern struct list_head *first_device;

#define LIST_HEAD(name) struct list_head name = { &(name), &(name) }

static inline void spin_lock_irq(spinlock_t *lock) { (void)lock; }
static inline void spin_unlock_irq(spinlock_t *lock) { (void)lock; }
static inline void mutex_lock(void *mutex) { (void)mutex; }
static inline void mutex_unlock(void *mutex) { (void)mutex; }
static inline void rtnl_lock(void) {}
static inline void rtnl_unlock(void) {}
static inline void synchronize_rcu(void) {}
static inline void rcu_barrier(void) {}
static inline void list_replace_init(struct list_head *old, struct list_head *new) { (void)old; (void)new; }
static inline void list_del_rcu(struct list_head *entry) { (void)entry; }
static inline void list_del_init(struct list_head *entry) { (void)entry; }
static inline void unregister_netdevices(struct net *net, struct list_head *list) { (void)net; (void)list; }
static inline void unregister_netdevice_many(struct list_head *list) { (void)list; }
static inline void ops_free(const struct pernet_operations *ops, struct net *net) { (void)ops; (void)net; }
static inline void net_free(struct net *net) { (void)net; }

#define list_for_each_entry(pos, head, member) \
    for (pos = (typeof(pos))((head)->next); pos != (typeof(pos))(head); pos = (typeof(pos))(pos->member.next))
#define list_for_each_entry_reverse(pos, head, member) \
    for (pos = (typeof(pos))((head)->prev); pos != (typeof(pos))(head); pos = (typeof(pos))(pos->member.prev))
#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = (typeof(pos))((head)->next), n = (typeof(pos))(pos->member.next); \
         pos != (typeof(pos))(head); \
         pos = n, n = (typeof(pos))(pos->member.next))