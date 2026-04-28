#include <sys/types.h>

#define EPERM 1
#define CAP_SYS_ADMIN 0

struct ftrace_event_call {
    unsigned long flags;
};

struct perf_event {
    struct {
        unsigned long long sample_type;
    } attr;
    int attach_state;
};

#define TRACE_EVENT_FL_CAP_ANY 0x1
#define PERF_SAMPLE_RAW 0x1
#define PERF_ATTACH_TASK 0x1

static inline int ftrace_event_is_function(struct ftrace_event_call *tp_event) { return 0; }
static inline int perf_paranoid_kernel(void) { return 0; }
static inline int capable(int cap) { return 0; }
static inline int perf_paranoid_tracepoint_raw(void) { return 0; }