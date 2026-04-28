#include <stdbool.h>
#include <stddef.h>

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct hlist_head {
    struct hlist_node *first;
};

#define hlist_entry(ptr, type, member) container_of(ptr, type, member)
#define hlist_empty(ptr) ((ptr)->first == NULL)
#define hlist_del_init_rcu(ptr) do { } while (0)
#define hlist_unhashed(ptr) (0)

#define rcu_read_lock() do { } while (0)
#define rcu_read_unlock() do { } while (0)
#define rcu_dereference(ptr) (ptr)
#define rcu_assign_pointer(ptr, val) do { (ptr) = (val); } while (0)

#define spin_lock_bh(lock) do { } while (0)
#define spin_unlock_bh(lock) do { } while (0)
#define spin_lock(lock) do { } while (0)
#define spin_unlock(lock) do { } while (0)

struct watch_queue;
struct watch_list;
struct watch;

struct watch_queue {
    int lock;
    bool defunct;
    struct hlist_head watches;
};

struct watch_list {
    int lock;
    void (*release_watch)(struct watch *);
};

struct watch {
    struct hlist_node queue_node;
    struct hlist_node list_node;
    struct watch_list *watch_list;
};

void put_watch(struct watch *watch);