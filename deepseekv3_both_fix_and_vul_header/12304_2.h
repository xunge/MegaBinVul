#include <stddef.h>
#include <string.h>
#include <time.h>

enum hrtimer_mode {
    HRTIMER_MODE_ABS,
    HRTIMER_MODE_REL
};

struct timerqueue_node {
    struct timerqueue_node *next;
    struct timerqueue_node *prev;
};

struct hrtimer_clock_base {
    int dummy;
};

struct hrtimer_cpu_base {
    struct hrtimer_clock_base clock_base[1];
};

struct hrtimer {
    struct hrtimer_clock_base *base;
    struct timerqueue_node node;
    void *start_site;
    int start_pid;
    char start_comm[16];
};

extern struct hrtimer_cpu_base hrtimer_bases;

#define raw_cpu_ptr(ptr) (ptr)
#define TASK_COMM_LEN 16
#define CLOCK_REALTIME 0
#define CLOCK_MONOTONIC 1
#define CONFIG_TIMER_STATS 1

static inline void timerqueue_init(struct timerqueue_node *node) {
    node->next = node;
    node->prev = node;
}

static inline int hrtimer_clockid_to_base(clockid_t clock_id) { return 0; }