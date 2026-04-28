#include <stddef.h>

struct pmu_hw_events;

struct hw_perf_event {
    int idx;
    int state;
    int config;
};

struct pmu {
    int dummy;
};

struct perf_event {
    struct pmu *pmu;
    struct hw_perf_event hw;
    struct perf_event *group_leader;
    int state;
    struct {
        int enable_on_exec;
    } attr;
};

struct arm_pmu {
    int (*get_event_idx)(struct pmu_hw_events *hw_events, struct hw_perf_event *event);
};

#define PERF_EVENT_STATE_OFF 0

static inline int is_software_event(struct perf_event *event) { return 0; }
static inline struct arm_pmu *to_arm_pmu(struct pmu *pmu) { return NULL; }