#include <stdint.h>
#include <stdlib.h>
#include <time.h>

struct timer_list {
    unsigned long data;
};

typedef struct {
    int lock;
} spinlock_t;

struct Qdisc {
    int dummy;
};

struct sfq_sched_data {
    struct Qdisc *sch;
    struct timer_list perturb_timer;
    uint32_t perturbation;
    unsigned int perturb_period;
    struct Qdisc *filter_list;
    struct Qdisc *tail;
};

typedef uint32_t siphash_key_t;

#define from_timer(ptr, timer, member) ((ptr) = (struct sfq_sched_data*)(timer))
#define spin_lock(lock) ((void)(lock))
#define spin_unlock(lock) ((void)(lock))
#define jiffies ((unsigned long)time(NULL))
#define mod_timer(timer, expires) ((void)0)

static inline uint32_t prandom_u32(void) { return rand(); }
static inline void get_random_bytes(void *buf, size_t len) { 
    for (size_t i = 0; i < len; i++) {
        ((uint8_t*)buf)[i] = rand() % 256;
    }
}
static inline spinlock_t *qdisc_lock(struct Qdisc *q) { return (spinlock_t*)&q->dummy; }
static inline struct Qdisc *qdisc_root_sleeping(struct Qdisc *q) { return q; }
static inline void sfq_rehash(struct Qdisc *sch) {}