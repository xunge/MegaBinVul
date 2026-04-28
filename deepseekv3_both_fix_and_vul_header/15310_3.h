#include <stdint.h>

typedef uint32_t u32;
#define __user

struct list_head {
    struct list_head *next, *prev;
};

struct task_struct {
    struct list_head pi_state_list;
    struct list_head pi_lock;
};

struct rt_mutex {
    struct list_head wait_lock;
};

struct futex_pi_state {
    struct rt_mutex pi_mutex;
    struct task_struct *owner;
    struct list_head list;
};

struct futex_q {
    struct task_struct *task;
    struct futex_pi_state *pi_state;
};

#define FUTEX_WAITERS 0x80000000
#define FUTEX_OWNER_DIED 0x40000000
#define EINVAL 22
#define EFAULT 14

extern struct task_struct *current;
extern int cmpxchg_futex_value_locked(u32 *uaddr, u32 oldval, u32 newval);
extern void raw_spin_lock(struct list_head *lock);
extern void raw_spin_unlock(struct list_head *lock);
extern void raw_spin_lock_irq(struct list_head *lock);
extern void raw_spin_unlock_irq(struct list_head *lock);
extern struct task_struct *rt_mutex_next_owner(struct rt_mutex *lock);
extern void rt_mutex_unlock(struct rt_mutex *lock);
extern int task_pid_vnr(struct task_struct *task);
extern void WARN_ON(int condition);
extern void list_del_init(struct list_head *entry);
extern void list_add(struct list_head *new, struct list_head *head);
extern int list_empty(const struct list_head *head);