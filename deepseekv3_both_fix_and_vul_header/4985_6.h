#include <stdint.h>
#include <time.h>

typedef uint32_t u32;
typedef uint64_t u64;

typedef struct {
    u64 tv64;
} ktime_t;

struct hrtimer_sleeper {
    void *timer;
    void *task;
};

struct restart_block {
    long (*fn)(struct restart_block *);
    union {
        struct {
            u32 *uaddr;
            u32 val;
            u64 time;
            u32 bitset;
            u32 flags;
        } futex;
    };
};

struct futex_hash_bucket {
    // implementation dependent
};

struct futex_q {
    void *list;
    void *task;
    void *lock_ptr;
    void *key;
    void *pi_state;
    void *rt_waiter;
    void *requeue_pi_key;
    u32 bitset;
};

struct task_struct {
    u64 timer_slack_ns;
};

struct thread_info {
    struct restart_block restart_block;
};

#define CLOCK_REALTIME 0
#define CLOCK_MONOTONIC 1
#define HRTIMER_MODE_ABS 0

#define FLAGS_HAS_TIMEOUT 0x01
#define FLAGS_SHARED 0x02
#define FLAGS_CLOCKRT 0x04

#define EINVAL 22
#define ETIMEDOUT 110
#define ERESTARTSYS 512
#define ERESTART_RESTARTBLOCK 516

// Dummy function declarations
static void hrtimer_init_on_stack(void *timer, int clock_type, int mode) {}
static void hrtimer_init_sleeper(struct hrtimer_sleeper *to, void *task) {}
static void hrtimer_set_expires_range_ns(void *timer, ktime_t time, u64 slack) {}
static int futex_wait_setup(u32 *uaddr, u32 val, int fshared, struct futex_q *q, struct futex_hash_bucket **hb) { return 0; }
static void futex_wait_queue_me(struct futex_hash_bucket *hb, struct futex_q *q, struct hrtimer_sleeper *to) {}
static int unqueue_me(struct futex_q *q) { return 0; }
static int signal_pending(void *task) { return 0; }
static void put_futex_key(int fshared, void *key) {}
static void hrtimer_cancel(void *timer) {}
static void destroy_hrtimer_on_stack(void *timer) {}

// Dummy function pointer
static long futex_wait_restart(struct restart_block *restart) { return 0; }

// Current task definitions
static struct task_struct dummy_task = {0};
#define current (&dummy_task)
static struct thread_info dummy_thread_info;
#define current_thread_info() (&dummy_thread_info)

#define __user