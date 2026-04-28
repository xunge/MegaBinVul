#include <stdatomic.h>
#include <stddef.h>
#include <pthread.h>
#include <stdint.h>
#include <string.h>

typedef uint32_t u32;

struct list_head {
    struct list_head *next, *prev;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }
#define LIST_HEAD(name) struct list_head name = LIST_HEAD_INIT(name)

struct net {
    _Atomic int count;
    _Atomic int passive;
    u32 hash_mix;
    unsigned int dev_base_seq;
    struct user_namespace *user_ns;
    void *netns_ids;
    pthread_spinlock_t nsid_lock;
    struct {
        pthread_mutex_t ra_mutex;
    } ipv4;
    struct list_head list;
    struct list_head exit_list;
};

struct pernet_operations {
    struct list_head list;
};

struct user_namespace;

extern pthread_rwlock_t net_rwsem;
extern struct list_head pernet_list;
extern struct list_head net_namespace_list;

#define __net_init
#define refcount_set(ptr, val) (*(ptr) = (val))
#define idr_init(ptr) (*(ptr) = NULL)
#define spin_lock_init(lock) pthread_spin_init(lock, 0)
#define mutex_init(lock) pthread_mutex_init(lock, NULL)
#define down_write(lock) pthread_rwlock_wrlock(lock)
#define up_write(lock) pthread_rwlock_unlock(lock)
#define rcu_barrier() do {} while(0)
#define get_random_bytes(ptr, size) memset((ptr), 0, (size))

#define list_for_each_entry(pos, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = container_of(pos->member.next, typeof(*pos), member))

#define list_for_each_entry_continue_reverse(pos, head, member) \
    for (pos = container_of(pos->member.prev, typeof(*pos), member); \
         &pos->member != (head); \
         pos = container_of(pos->member.prev, typeof(*pos), member))

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

static inline void list_add_tail_rcu(struct list_head *new, struct list_head *head) {
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}

static inline void list_add(struct list_head *new, struct list_head *head) {
    new->next = head->next;
    new->prev = head;
    head->next->prev = new;
    head->next = new;
}

static int ops_init(const struct pernet_operations *ops, struct net *net) { return 0; }
static void ops_exit_list(const struct pernet_operations *ops, struct list_head *list) {}
static void ops_free_list(const struct pernet_operations *ops, struct list_head *list) {}