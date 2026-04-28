#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

typedef struct { int lock; } spinlock_t;

struct pid {
    int nr;
};

struct signal_struct {
    struct tty_struct *tty;
};

struct task_struct {
    struct signal_struct *signal;
    int session;
};

struct tty_struct {
    spinlock_t ctrl_lock;
    struct pid *pgrp;
    int session;
};

#define EIO 5
#define ENOTTY 25
#define EFAULT 14
#define EINVAL 22
#define ESRCH 3
#define EPERM 1

#define __user

extern struct task_struct *current;

static inline int get_user(pid_t *dest, pid_t __user *src) { *dest = *src; return 0; }
static inline void rcu_read_lock() {}
static inline void rcu_read_unlock() {}
static inline void spin_lock_irq(spinlock_t *lock) { lock->lock = 1; }
static inline void spin_unlock_irq(spinlock_t *lock) { lock->lock = 0; }

struct pid *find_vpid(pid_t nr);
int session_of_pgrp(struct pid *pgrp);
void put_pid(struct pid *pid);
struct pid *get_pid(struct pid *pid);
int tty_check_change(struct tty_struct *tty);
int task_session(struct task_struct *task);