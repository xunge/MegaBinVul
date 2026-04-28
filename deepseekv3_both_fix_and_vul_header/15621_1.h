#include <stddef.h>
#include <stdatomic.h>

struct list_head {
    struct list_head *next, *prev;
};

struct fib6_info {
    struct fib6_table *fib6_table;
    struct list_head nh_list;
    struct nh_info *nh;
    atomic_int fib6_ref;
};

struct fib6_node {
    struct fib6_info *leaf;
    struct fib6_node *parent;
    unsigned int fn_flags;
};

struct fib6_table {
    struct list_head tb6_lock;
};

struct net;

#define RTN_RTINFO 0x01

#define rcu_dereference_protected(p, cond) (p)
#define rcu_assign_pointer(p, v) ((p) = (v))
#define lockdep_is_held(lock) (1)

static void rt6_flush_exceptions(struct fib6_info *rt) {}
static void fib6_drop_pcpu_from(struct fib6_info *rt, struct fib6_table *table) {}
static struct fib6_info *fib6_find_prefix(struct net *net, struct fib6_table *table, struct fib6_node *fn) { return NULL; }
static void fib6_info_hold(struct fib6_info *rt) {}
static void fib6_info_release(struct fib6_info *rt) {}
static void fib6_clean_expires_locked(struct fib6_info *rt) {}

static int refcount_read(atomic_int *ref) { return atomic_load(ref); }
static int list_empty(const struct list_head *head) { return head->next == head; }
static void list_del_init(struct list_head *entry) {}