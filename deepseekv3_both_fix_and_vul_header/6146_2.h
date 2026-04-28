#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define TRANS_ATTACH 0
#define TRANS_JOIN_NOLOCK 1
#define BTRFS_FS_STATE_ERROR 0
#define EROFS 1
#define EBUSY 2
#define ENOENT 3
#define ENOMEM 4
#define GFP_NOFS 0
#define KERN_ERR 0
#define TRANS_STATE_RUNNING 0
#define IO_TREE_TRANS_DIRTY_PAGES 0
#define IO_TREE_FS_PINNED_EXTENTS 0

struct rb_node {
    unsigned long  __rb_parent_color;
    struct rb_node *rb_right;
    struct rb_node *rb_left;
};

struct rb_root {
    struct rb_node *rb_node;
};

struct rb_root_cached {
    struct rb_root rb_root;
    struct rb_node *rb_leftmost;
};

struct list_head {
    struct list_head *next, *prev;
};

struct mutex {
    int dummy;
};

struct spinlock {
    int dummy;
};

struct wait_queue_head {
    int dummy;
};

typedef struct {
    int counter;
} atomic_t;

typedef struct {
    long long counter;
} atomic64_t;

typedef struct {
    int refs;
} refcount_t;

struct extent_io_tree {
    int dummy;
};

struct btrfs_delayed_ref_root {
    struct rb_root_cached href_root;
    struct rb_root dirty_extent_root;
    atomic_t num_entries;
    struct spinlock lock;
};

struct btrfs_transaction {
    struct btrfs_fs_info *fs_info;
    atomic_t pending_ordered;
    struct wait_queue_head pending_wait;
    atomic_t num_writers;
    refcount_t use_count;
    struct wait_queue_head writer_wait;
    struct wait_queue_head commit_wait;
    unsigned int state;
    unsigned int flags;
    long start_time;
    struct btrfs_delayed_ref_root delayed_refs;
    struct list_head pending_snapshots;
    struct list_head dev_update_list;
    struct list_head switch_commits;
    struct list_head dirty_bgs;
    struct list_head io_bgs;
    struct list_head dropped_roots;
    struct mutex cache_write_mutex;
    struct spinlock dirty_bgs_lock;
    struct list_head deleted_bgs;
    struct spinlock dropped_roots_lock;
    struct list_head releasing_ebs;
    struct spinlock releasing_ebs_lock;
    atomic64_t chunk_bytes_reserved;
    struct wait_queue_head chunk_reserve_wait;
    struct list_head list;
    struct extent_io_tree dirty_pages;
    struct extent_io_tree pinned_extents;
    unsigned long transid;
    int aborted;
};

struct btrfs_fs_info {
    struct spinlock trans_lock;
    unsigned long fs_state;
    struct btrfs_transaction *running_transaction;
    struct list_head tree_mod_seq_list;
    struct rb_root tree_mod_log;
    atomic64_t tree_mod_seq;
    struct list_head trans_list;
    void *btree_inode;
    unsigned long generation;
};

static int btrfs_blocked_trans_types[] = {0};

static inline void spin_lock(struct spinlock *lock) {}
static inline void spin_unlock(struct spinlock *lock) {}
static inline void spin_lock_init(struct spinlock *lock) {}
static inline void mutex_init(struct mutex *lock) {}
static inline void init_waitqueue_head(struct wait_queue_head *wq) {}
static inline void refcount_inc(refcount_t *r) { r->refs++; }
static inline void refcount_set(refcount_t *r, int value) { r->refs = value; }
static inline void atomic_inc(atomic_t *v) { v->counter++; }
static inline void atomic_set(atomic_t *v, int i) { v->counter = i; }
static inline void atomic64_set(atomic64_t *v, long long i) { v->counter = i; }
static inline void extwriter_counter_inc(struct btrfs_transaction *t, unsigned int type) {}
static inline void extwriter_counter_init(struct btrfs_transaction *t, unsigned int type) {}
static inline int test_bit(int nr, const volatile unsigned long *addr) { return (*addr >> nr) & 1; }
static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline void INIT_LIST_HEAD(struct list_head *list) { list->next = list; list->prev = list; }
static inline void list_add_tail(struct list_head *new, struct list_head *head) {
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}
static inline int list_empty(const struct list_head *head) { return head->next == head; }
static inline int RB_EMPTY_ROOT(const struct rb_root *root) { return root->rb_node == NULL; }
static inline void extent_io_tree_init(struct btrfs_fs_info *fs_info,
                                      struct extent_io_tree *tree,
                                      int type, void *inode) {}
static inline long ktime_get_seconds(void) { return 0; }
#define BUG_ON(cond) do { if (cond) abort(); } while (0)
#define TRANS_ABORTED(t) ((t)->aborted)
#define smp_mb() __sync_synchronize()
#define WARN(cond, fmt...) do { if (cond) {} } while (0)
#define RB_ROOT_CACHED (struct rb_root_cached) { RB_ROOT, NULL }
#define RB_ROOT (struct rb_root) { NULL }
#define noinline __attribute__((noinline))