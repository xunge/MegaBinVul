#include <stdint.h>
#include <time.h>

typedef int64_t ktime_t;
typedef uint32_t u32;
#define __user

#define EINVAL 22
#define EFAULT 14
#define EINTR 4
#define EWOULDBLOCK 11

#define CLOCK_REALTIME 0
#define CLOCK_MONOTONIC 1
#define HRTIMER_MODE_ABS 0

struct task_struct {
    int64_t timer_slack_ns;
};

#define current ((struct task_struct*)0)
#define unlikely(x) (x)
#define WARN_ON(cond) (void)(cond)

struct hrtimer_sleeper {
    struct {
        int dummy;
    } timer;
    struct task_struct* task;
};

struct rt_mutex_waiter {
    struct task_struct* task;
};

struct rt_mutex {
    struct task_struct* owner;
};

struct futex_hash_bucket {
    int lock;
};

struct futex_pi_state {
    struct rt_mutex pi_mutex;
    struct task_struct* owner;
};

typedef union futex_key {
    struct {
        unsigned long pgoff;
        void* inode;
        int offset;
    } shared;
    struct {
        unsigned long address;
        void* mm;
        int offset;
    } private;
} futex_key_t;

struct futex_q {
    struct futex_pi_state* pi_state;
    u32 bitset;
    struct rt_mutex_waiter *rt_waiter;
    futex_key_t *requeue_pi_key;
    futex_key_t key;
    int* lock_ptr;
};

#define FUTEX_KEY_INIT ((futex_key_t){ .private = { 0 } })

static inline void spin_lock(int* lock) {}
static inline void spin_unlock(int* lock) {}
static inline void hrtimer_init_on_stack(void* timer, int clock, int mode) {}
static inline void hrtimer_init_sleeper(void* sleeper, struct task_struct* task) {}
static inline void hrtimer_set_expires_range_ns(void* timer, ktime_t time, int64_t slack) {}
static inline void hrtimer_cancel(void* timer) {}
static inline void destroy_hrtimer_on_stack(void* timer) {}
static inline void debug_rt_mutex_init_waiter(struct rt_mutex_waiter* waiter) {}
static inline void debug_rt_mutex_free_waiter(struct rt_mutex_waiter* waiter) {}

extern int get_futex_key(u32* uaddr, int fshared, futex_key_t* key);
extern int futex_wait_setup(u32* uaddr, u32 val, int fshared, struct futex_q* q, struct futex_hash_bucket** hb);
extern void futex_wait_queue_me(struct futex_hash_bucket* hb, struct futex_q* q, struct hrtimer_sleeper* timeout);
extern int handle_early_requeue_pi_wakeup(struct futex_hash_bucket* hb, struct futex_q* q, futex_key_t* key, struct hrtimer_sleeper* timeout);
extern int fixup_pi_state_owner(u32* uaddr, struct futex_q* q, struct task_struct* newowner, int fshared);
extern int fixup_owner(u32* uaddr, int fshared, struct futex_q* q, int locked);
extern void unqueue_me_pi(struct futex_q* q);
extern void put_futex_key(int fshared, futex_key_t* key);
extern int rt_mutex_finish_proxy_lock(struct rt_mutex* lock, struct hrtimer_sleeper* to, struct rt_mutex_waiter* waiter, int detect_deadlock);
extern struct task_struct* rt_mutex_owner(struct rt_mutex* lock);
extern void rt_mutex_unlock(struct rt_mutex* lock);