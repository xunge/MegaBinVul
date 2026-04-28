#include <errno.h>
#include <time.h>
#include <stdint.h>
#include <stddef.h>

#define FLAGS_CLOCKRT 1
#define FLAGS_SHARED 2
#define VERIFY_WRITE 1
#define CLOCK_REALTIME 0
#define CLOCK_MONOTONIC 1
#define HRTIMER_MODE_ABS 0

typedef uint32_t u32;
typedef int64_t ktime_t;

#define __user
#define unlikely(x) (x)
#define WARN_ON(cond) do { } while (0)

struct task_struct {
    long timer_slack_ns;
};

struct rt_mutex {
    struct task_struct *owner;
};

struct futex_pi_state {
    struct rt_mutex pi_mutex;
    struct task_struct *owner;
};

struct futex_hash_bucket {
    int lock;
};

union futex_key {
    int initialized;
};

struct rt_mutex_waiter {
    struct task_struct *task;
};

struct hrtimer_sleeper {
    void *timer;
    struct task_struct *task;
};

struct futex_q {
    u32 bitset;
    struct rt_mutex_waiter *rt_waiter;
    union futex_key *requeue_pi_key;
    union futex_key key;
    struct futex_pi_state *pi_state;
    int *lock_ptr;
};

#define FUTEX_KEY_INIT {0}

static struct futex_q futex_q_init = {
    .bitset = 0,
    .rt_waiter = NULL,
    .requeue_pi_key = NULL,
    .pi_state = NULL,
    .lock_ptr = NULL
};

static inline void spin_lock(int *lock) {}
static inline void spin_unlock(int *lock) {}

extern struct task_struct *current;
extern void hrtimer_init_on_stack(void *timer, int clock_type, int mode);
extern void hrtimer_init_sleeper(struct hrtimer_sleeper *sleeper, struct task_struct *task);
extern void hrtimer_set_expires_range_ns(void *timer, ktime_t time, long slack);
extern void hrtimer_cancel(void *timer);
extern void destroy_hrtimer_on_stack(void *timer);
extern void debug_rt_mutex_init_waiter(struct rt_mutex_waiter *waiter);
extern void debug_rt_mutex_free_waiter(struct rt_mutex_waiter *waiter);
extern int get_futex_key(u32 *uaddr, int shared, union futex_key *key, int write);
extern int futex_wait_setup(u32 *uaddr, u32 val, unsigned int flags, struct futex_q *q, struct futex_hash_bucket **hb);
extern void futex_wait_queue_me(struct futex_hash_bucket *hb, struct futex_q *q, struct hrtimer_sleeper *to);
extern int handle_early_requeue_pi_wakeup(struct futex_hash_bucket *hb, struct futex_q *q, union futex_key *key2, struct hrtimer_sleeper *to);
extern int fixup_pi_state_owner(u32 *uaddr2, struct futex_q *q, struct task_struct *new_owner);
extern int fixup_owner(u32 *uaddr2, struct futex_q *q, int locked);
extern void unqueue_me_pi(struct futex_q *q);
extern void put_futex_key(union futex_key *key);
extern int rt_mutex_finish_proxy_lock(struct rt_mutex *lock, struct hrtimer_sleeper *to, struct rt_mutex_waiter *waiter, int detect_deadlock);
extern struct task_struct *rt_mutex_owner(struct rt_mutex *lock);
extern void rt_mutex_unlock(struct rt_mutex *lock);