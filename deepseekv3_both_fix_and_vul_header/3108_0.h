#include <stddef.h>

struct pmu;
struct perf_event;
struct pmu_hw_events;
struct arm_pmu;

enum {
    PERF_EVENT_STATE_OFF,
};

struct perf_event {
    struct pmu *pmu;
    struct perf_event *group_leader;
    int state;
    struct {
        int enable_on_exec;
    } attr;
};

struct arm_pmu {
    int (*get_event_idx)(struct pmu_hw_events *hw_events, struct perf_event *event);
};

static inline struct arm_pmu *to_arm_pmu(struct pmu *pmu) {
    return (struct arm_pmu *)pmu;
}