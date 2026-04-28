#include <stdatomic.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define CONFIG_FUTEX_PI 1
#define FLAGS_SHARED 0
#define VERIFY_READ 0
#define VERIFY_WRITE 1
#define FUTEX_KEY_INIT {0}
#define ENOSYS 38
#define EINVAL 22
#define ENOMEM 12
#define EAGAIN 11
#define EFAULT 14

#define IS_ENABLED(x) (x)
#define likely(x) (x)
#define unlikely(x) (x)
#define WARN_ON(x) (0)

typedef uint32_t u32;
typedef atomic_int atomic_t;

struct task_struct;
struct mm_struct;
struct inode;
struct wake_q_node;

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

struct plist_node {
    int prio;
    struct list_head list;
};

struct plist_head {
    struct list_head node_list;
};

struct wake_q_head {
    struct wake_q_node *first;
    struct wake_q_node **lastp;
};

struct rt_mutex {
    atomic_t owner;
};

struct rt_mutex_waiter {
    struct plist_node list_entry;
    struct task_struct *task;
};

union futex_key {
    struct {
        unsigned long pgoff;
        struct inode *inode;
        int offset;
    } shared;
    struct {
        unsigned long address;
        struct mm_struct *mm;
        int offset;
    } private;
};

struct futex_pi_state {
    struct rt_mutex pi_mutex;
    struct task_struct *owner;
    atomic_t refcount;
    union futex_key key;
};

struct futex_hash_bucket {
    void *lock;
    struct plist_head chain;
};

struct futex_q {
    struct plist_node list;
    struct task_struct *task;
    void *lock_ptr;
    union futex_key key;
    struct futex_pi_state *pi_state;
    struct rt_mutex_waiter *rt_waiter;
    union futex_key *requeue_pi_key;
};

#define DEFINE_WAKE_Q(name) struct wake_q_head name = {NULL, &(name).first}
#define __user

#define plist_for_each_entry_safe(pos, n, head, member) \
    for (pos = list_entry((head)->node_list.next, typeof(*pos), member.list), \
         n = list_entry(pos->member.list.next, typeof(*pos), member.list); \
         &pos->member.list != &(head)->node_list; \
         pos = n, n = list_entry(n->member.list.next, typeof(*n), member.list))

#define list_entry(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

static inline int rt_mutex_start_proxy_lock(struct rt_mutex *lock,
                      struct rt_mutex_waiter *waiter,
                      struct task_struct *task) { return 0; }

static inline void hb_waiters_inc(struct futex_hash_bucket *hb) {}
static inline void hb_waiters_dec(struct futex_hash_bucket *hb) {}
static inline void double_lock_hb(struct futex_hash_bucket *hb1, struct futex_hash_bucket *hb2) {}
static inline void double_unlock_hb(struct futex_hash_bucket *hb1, struct futex_hash_bucket *hb2) {}
static inline int get_futex_key(u32 *uaddr, int shared, union futex_key *key, int rw) { return 0; }
static inline void put_futex_key(union futex_key *key) {}
static inline int match_futex(union futex_key *key1, union futex_key *key2) { return 0; }
static inline struct futex_hash_bucket *hash_futex(union futex_key *key) { return NULL; }
static inline int get_futex_value_locked(u32 *val, u32 *uaddr) { return 0; }
static inline int futex_proxy_trylock_atomic(u32 *uaddr, struct futex_hash_bucket *hb1, struct futex_hash_bucket *hb2, union futex_key *key1, union futex_key *key2, struct futex_pi_state **ps, int set_waiters) { return 0; }
static inline int lookup_pi_state(u32 *uaddr, int pid, struct futex_hash_bucket *hb, union futex_key *key, struct futex_pi_state **ps) { return 0; }
static inline void mark_wake_futex(struct wake_q_head *wake_q, struct futex_q *q) {}
static inline void requeue_futex(struct futex_q *q, struct futex_hash_bucket *hb1, struct futex_hash_bucket *hb2, union futex_key *key) {}
static inline void requeue_pi_wake_futex(struct futex_q *q, union futex_key *key, struct futex_hash_bucket *hb) {}
static inline void get_pi_state(struct futex_pi_state *pi_state) {}
static inline void put_pi_state(struct futex_pi_state *pi_state) {}
static inline int refill_pi_state_cache(void) { return 0; }
static inline int fault_in_user_writeable(u32 *uaddr) { return 0; }
static inline void drop_futex_key_refs(union futex_key *key) {}
static inline void wake_up_q(struct wake_q_head *wake_q) {}
static inline void cond_resched(void) {}
static inline int get_user(u32 val, u32 *uaddr) { return 0; }