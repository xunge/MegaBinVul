#include <stdint.h>
#include <string.h>

#define MAX_FIXED_PEBS_EVENTS 4
#define INTEL_PMC_IDX_FIXED 32
#define PMU_FL_PEBS_ALL (1 << 0)

typedef uint64_t u64;

struct pt_regs;
struct perf_sample_data;

struct cpu_hw_events {
    struct debug_store *ds;
    u64 pebs_enabled;
    struct perf_event **events;
};

struct debug_store {
    u64 pebs_buffer_base;
    u64 pebs_index;
};

struct pebs_record_nhm {
    u64 status;
};

struct perf_event {
    struct {
        u64 precise_ip;
    } attr;
};

struct x86_pmu {
    unsigned pebs_active;
    unsigned max_pebs_events;
    unsigned flags;
    unsigned num_counters_fixed;
    unsigned pebs_record_size;
    struct {
        unsigned pebs_format;
    } intel_cap;
};

extern struct x86_pmu x86_pmu;
extern struct cpu_hw_events cpu_hw_events;

#define this_cpu_ptr(ptr) (&cpu_hw_events)
#define unlikely(cond) (cond)
#define WARN_ON_ONCE(cond) ((cond) ? 1 : 0)

static inline int find_first_bit(const unsigned long *addr, unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        if (addr[i / (sizeof(long)*8)] & (1UL << (i % (sizeof(long)*8)))) {
            return i;
        }
    }
    return size;
}

static inline int find_next_bit(const unsigned long *addr, unsigned size, unsigned offset) {
    for (unsigned i = offset; i < size; i++) {
        if (addr[i / (sizeof(long)*8)] & (1UL << (i % (sizeof(long)*8)))) {
            return i;
        }
    }
    return size;
}

#define for_each_set_bit(bit, addr, size) \
    for ((bit) = find_first_bit((addr), (size)); \
         (bit) < (size); \
         (bit) = find_next_bit((addr), (size), (bit) + 1))

static void intel_pmu_pebs_event_update_no_drain(struct cpu_hw_events *cpuc, int size) {}
static void perf_log_lost_samples(struct perf_event *event, int count) {}
static int perf_event_account_interrupt(struct perf_event *event) { return 0; }
static void x86_pmu_stop(struct perf_event *event, int flags) {}
static void __intel_pmu_pebs_event(struct perf_event *event, struct pt_regs *iregs,
                                  struct perf_sample_data *data, void *base,
                                  void *top, int bit, int count,
                                  void (*setup)(void)) {}
static void setup_pebs_fixed_sample_data(void) {}