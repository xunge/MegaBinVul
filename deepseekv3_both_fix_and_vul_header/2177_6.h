#include <stddef.h>
#include <time.h>
#include <stdlib.h>

typedef int cnodeid_t;

struct k_itimer {
    struct {
        struct {
            int clock;
            cnodeid_t node;
            unsigned long incr;
            unsigned long expires;
        } mmtimer;
    } it;
};

struct mmtimer {
    struct k_itimer *timer;
    int cpu;
};

struct rb_node;

#define TIMER_ABSTIME 1
#define TIMER_SET 2
#define COMPARATOR 3
#define GFP_KERNEL 0
#define ENOMEM 1

struct mmtimer_node {
    unsigned long lock;
    struct rb_node *next;
};

extern struct mmtimer_node timers[];
extern unsigned long sgi_clock_period;

static inline unsigned long timespec_to_ns(const struct timespec *ts) {
    return ts->tv_sec * 1000000000UL + ts->tv_nsec;
}

static inline unsigned long timespec_to_ns_copy(struct timespec ts) {
    return ts.tv_sec * 1000000000UL + ts.tv_nsec;
}

#define timespec_to_ns(ts) _Generic((ts), \
    const struct timespec*: timespec_to_ns, \
    struct timespec*: timespec_to_ns, \
    struct timespec: timespec_to_ns_copy)(ts)

void *kmalloc(size_t size, int flags);
void sgi_timer_get(struct k_itimer *timr, struct itimerspec *setting);
void sgi_timer_del(struct k_itimer *timr);
void getnstimeofday(struct timespec *ts);
unsigned long rtc_time(void);
void preempt_disable(void);
void preempt_enable(void);
int smp_processor_id(void);
cnodeid_t cpu_to_node(int cpu);
void spin_lock_irqsave(unsigned long *lock, unsigned long flags);
void spin_unlock_irqrestore(unsigned long *lock, unsigned long flags);
void mmtimer_add_list(struct mmtimer *base);
void mmtimer_disable_int(int nasid, int comparator);
void mmtimer_set_next_timer(cnodeid_t nodeid);
int cnodeid_to_nasid(cnodeid_t nodeid);