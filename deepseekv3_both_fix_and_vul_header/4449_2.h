#include <stddef.h>
#include <stdbool.h>

struct list_head {
    struct list_head *next, *prev;
};

struct llist_node {
    struct llist_node *next;
};

struct callback_head {
    struct callback_head *next;
    void (*func)(struct callback_head *head);
};

struct delayed_work {
    int dummy;
};

struct task_struct {
    unsigned int flags;
};

struct mount {
    struct {
        unsigned int mnt_flags;
    } mnt;
    struct list_head mnt_instance;
    struct list_head mnt_mounts;
    struct list_head mnt_child;
    int mnt_ns;
    struct llist_node mnt_llist;
    struct callback_head mnt_rcu;
};

extern void mnt_add_count(struct mount *mnt, int count);
extern int mnt_get_count(struct mount *mnt);
extern void lock_mount_hash(void);
extern void unlock_mount_hash(void);
extern void umount_mnt(struct mount *p);
extern void __cleanup_mnt(struct callback_head *head);
extern void cleanup_mnt(struct mount *mnt);
extern struct llist_head delayed_mntput_list;
extern struct delayed_work delayed_mntput_work;
extern struct task_struct *current;

#define likely(x)       __builtin_expect(!!(x), 1)
#define unlikely(x)     __builtin_expect(!!(x), 0)
#define MNT_DOOMED      (1 << 0)
#define MNT_INTERNAL    (1 << 1)
#define PF_KTHREAD      (1 << 2)

static inline void list_del(struct list_head *entry) {}
static inline int list_empty(const struct list_head *head) { return 1; }
#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = NULL, n = NULL; pos != NULL; pos = n)
static inline int llist_add(struct llist_node *new, struct llist_head *head) { return 0; }
static inline void schedule_delayed_work(struct delayed_work *dwork, unsigned long delay) {}
static inline void init_task_work(struct callback_head *twork, void (*func)(struct callback_head *)) {}
static inline int task_work_add(struct task_struct *task, struct callback_head *twork, bool notify) { return 0; }
static inline void rcu_read_lock(void) {}
static inline void rcu_read_unlock(void) {}