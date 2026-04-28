#include <stdint.h>
#include <time.h>
#include <stddef.h>

#define ENOMEM 12
#define EFAULT 14
#define EAGAIN 11
#define EINTR 4
#define ERESTARTNOINTR 512
#define EWOULDBLOCK EAGAIN

#define CLOCK_REALTIME 0
#define HRTIMER_MODE_ABS 0

#define unlikely(x) (x)
#define WARN_ON(cond) do { if (cond) {} } while (0)

typedef uint32_t u32;
typedef int ktime_t;
#define __user

struct hrtimer_sleeper {
    int timer;
    void *task;
};

struct futex_hash_bucket {
    int lock;
    struct futex_q *chain;
};

struct futex_pi_state {
    int pi_mutex;
    void *owner;
};

struct futex_q {
    void *list;
    void *task;
    int *lock_ptr;
    int key;
    struct futex_pi_state *pi_state;
    void *rt_waiter;
    void *requeue_pi_key;
    struct futex_hash_bucket *hb;
};

#define FUTEX_KEY_INIT 0
#define current ((void*)0)

static inline int refill_pi_state_cache(void) { return 0; }
static inline int get_futex_key(u32 *uaddr, int fshared, int *key) { return 0; }
static inline struct futex_hash_bucket *queue_lock(struct futex_q *q) { return NULL; }
static inline void queue_unlock(struct futex_q *q, struct futex_hash_bucket *hb) {}
static inline void put_futex_key(int fshared, int *key) {}
static inline void cond_resched(void) {}
static inline int futex_lock_pi_atomic(u32 *uaddr, struct futex_hash_bucket *hb,
                                      int *key, struct futex_pi_state **ps, 
                                      void *task, int set_waiters) { return 0; }
static inline void queue_me(struct futex_q *q, struct futex_hash_bucket *hb) {}
static inline int rt_mutex_timed_lock(int *lock, struct hrtimer_sleeper *to, int detect) { return 0; }
static inline int rt_mutex_trylock(int *lock) { return 0; }
static inline void *rt_mutex_owner(int *lock) { return NULL; }
static inline void rt_mutex_unlock(int *lock) {}
static inline int fixup_owner(u32 *uaddr, int fshared, struct futex_q *q, int locked) { return 0; }
static inline void unqueue_me_pi(struct futex_q *q) {}
static inline int fault_in_user_writeable(u32 *uaddr) { return 0; }
static inline void hrtimer_init_on_stack(int *timer, int clock, int mode) {}
static inline void hrtimer_init_sleeper(struct hrtimer_sleeper *sl, void *task) {}
static inline void hrtimer_set_expires(int *timer, ktime_t time) {}
static inline void destroy_hrtimer_on_stack(int *timer) {}
static inline void spin_lock(int *lock) {}