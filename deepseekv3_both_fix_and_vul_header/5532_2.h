#include <stdatomic.h>
#include <stdbool.h>

struct rcu_head {
    struct rcu_head *next;
    void (*func)(struct rcu_head *head);
};

struct llist_node {
    struct llist_node *next;
};

struct llist_head {
    struct llist_node *first;
};

struct work_struct {
    unsigned long data;
};

struct file {
    _Atomic long f_count;
    union {
        struct rcu_head fu_rcuhead;
        struct llist_node fu_llist;
    } f_u;
};

struct task_struct {
    unsigned int flags;
};

extern struct task_struct *current;
extern int in_interrupt(void);
extern void file_sb_list_del(struct file *file);
extern void init_task_work(struct rcu_head *rcuhead, void (*func)(struct rcu_head *rcuhead));
extern bool task_work_add(struct task_struct *task, struct rcu_head *rcuhead, bool notify);
extern void ____fput(struct rcu_head *rcuhead);
extern bool llist_add(struct llist_node *new, struct llist_head *head);
extern void schedule_work(struct work_struct *work);

extern struct llist_head delayed_fput_list;
extern struct work_struct delayed_fput_work;

#define PF_KTHREAD 0x00200000
#define likely(x) __builtin_expect(!!(x), 1)