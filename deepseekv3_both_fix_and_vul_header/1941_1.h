#include <stdint.h>

#define X86_PMC_IDX_FIXED_BTS -1
#define X86_PMC_IDX_FIXED -2
#define MSR_ARCH_PERFMON_FIXED_CTR_CTRL 0x38D
#define MSR_ARCH_PERFMON_FIXED_CTR0 0x309

struct cpu_hw_events {
    int assign[256];
    int tags[256];
};

struct hw_perf_event {
    int idx;
    int last_cpu;
    int last_tag;
    uint64_t config_base;
    uint64_t event_base;
};

struct perf_event {
    struct hw_perf_event hw;
};

static inline int smp_processor_id(void) { return 0; }
static inline uint64_t x86_pmu_config_addr(int idx) { return 0; }
static inline uint64_t x86_pmu_event_addr(int idx) { return 0; }