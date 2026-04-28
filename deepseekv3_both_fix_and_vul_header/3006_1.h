#include <stdint.h>
#include <errno.h>

#define PERF_TYPE_SOFTWARE 1
#define PERF_COUNT_SW_CPU_CLOCK 0
#define PERF_COUNT_SW_TASK_CLOCK 1
#define PERF_COUNT_SW_MAX 2

typedef uint64_t u64;

struct static_key {
    int enabled;
};
struct static_key perf_swevent_enabled[PERF_COUNT_SW_MAX];

struct perf_event_attr {
    int type;
    u64 config;
};

struct perf_event {
    struct perf_event_attr attr;
    struct perf_event *parent;
    void (*destroy)(struct perf_event *);
};

int has_branch_stack(struct perf_event *event);
int swevent_hlist_get(struct perf_event *event);
void sw_perf_event_destroy(struct perf_event *event);
void static_key_slow_inc(struct static_key *key);