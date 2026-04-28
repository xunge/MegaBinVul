#include <stdint.h>
#include <stdbool.h>

typedef uint64_t u64;

struct perf_event;
struct perf_event_context {
    unsigned long lock;
};

struct perf_event {
    struct perf_event_context *ctx;
    struct perf_event *parent;
    struct perf_event *sibling_list;
    u64 total_time_enabled;
    u64 total_time_running;
    struct {
        long counter;
    } child_total_time_enabled;
    struct {
        long counter;
    } child_total_time_running;
    struct {
        long counter;
    } lost_samples;
    unsigned int group_generation;
    unsigned int nr_siblings;
};

#define PERF_FORMAT_TOTAL_TIME_ENABLED  (1U << 0)
#define PERF_FORMAT_TOTAL_TIME_RUNNING  (1U << 1)
#define PERF_FORMAT_ID                  (1U << 2)
#define PERF_FORMAT_LOST                (1U << 3)

#define ECHILD 10

static inline long atomic64_read(const volatile void *v)
{
    return ((const struct { long counter; } *)v)->counter;
}

static int perf_event_read(struct perf_event *event, bool inherit) { return 0; }
static u64 perf_event_count(struct perf_event *event) { return 0; }
static u64 primary_event_id(struct perf_event *event) { return 0; }

#define raw_spin_lock_irqsave(lock, flags) (void)(flags)
#define raw_spin_unlock_irqrestore(lock, flags) (void)(flags)

#define for_each_sibling_event(sub, leader) \
    for ((sub) = (leader)->sibling_list; (sub); (sub) = (sub)->sibling_list)