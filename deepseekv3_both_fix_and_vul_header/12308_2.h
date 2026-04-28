#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define CONFIG_TIMER_STATS
#define TASK_COMM_LEN 16

struct seq_file {
    // dummy structure
};

struct hrtimer {
    void *function;
    unsigned int state;
#ifdef CONFIG_TIMER_STATS
    void *start_site;
    char start_comm[TASK_COMM_LEN];
    int start_pid;
#endif
};

typedef uint64_t u64;

#define SEQ_printf(m, fmt, ...) printf(fmt, ##__VA_ARGS__)

static inline void print_name_offset(struct seq_file *m, void *addr) {}

static inline uint64_t ktime_to_ns(uint64_t t) { return t; }
static inline uint64_t hrtimer_get_softexpires(struct hrtimer *t) { return 0; }
static inline uint64_t hrtimer_get_expires(struct hrtimer *t) { return 0; }