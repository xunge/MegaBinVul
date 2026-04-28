#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <x86intrin.h>

#define __init
#define ENODEV 19
#define KERN_ERR
#define WARN(cond, fmt, ...)
#define pr_cont(fmt, ...)
#define min_t(type, x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define X86_FEATURE_ARCH_PERFMON (1 << 0)
#define ARCH_PERFMON_EVENTS_COUNT 7
#define MAX_PEBS_EVENTS 4
#define INTEL_PMC_MAX_GENERIC 32
#define INTEL_PMC_MAX_FIXED 3
#define INTEL_PMC_IDX_FIXED 32
#define X86_RAW_EVENT_MASK 0xffff
#define INTEL_PMC_MSK_FIXED_REF_CYCLES (1ULL << INTEL_PMC_IDX_FIXED)
#define PERF_COUNT_HW_STALLED_CYCLES_FRONTEND 0
#define PERF_COUNT_HW_STALLED_CYCLES_BACKEND 1
#define MSR_IA32_PERF_CAPABILITIES 0x345
#define ERF_HAS_RSP_1 (1 << 0)
#define ERF_NO_HT_SHARING (1 << 1)

typedef uint64_t u64;

struct cpuinfo_x86 {
    int x86;
    int x86_model;
    int x86_mask;
};

struct event_constraint {
    unsigned long idxmsk64;
    unsigned int weight;
    unsigned int cmask;
};

struct x86_pmu {
    int version;
    int num_counters;
    int cntval_bits;
    unsigned long cntval_mask;
    unsigned long events_maskl;
    int events_mask_len;
    int max_pebs_events;
    int num_counters_fixed;
    unsigned long intel_ctrl;
    struct event_constraint *event_constraints;
    struct event_constraint *pebs_constraints;
    struct event_constraint *pebs_aliases;
    void (*enable_all)(void);
    unsigned long *extra_regs;
    unsigned int er_flags;
    struct {
        u64 capabilities;
    } intel_cap;
};

union cpuid10_eax {
    struct {
        unsigned int version_id:8;
        unsigned int num_counters:8;
        unsigned int bit_width:8;
        unsigned int mask_length:8;
    } split;
    unsigned int full;
};

union cpuid10_ebx {
    struct {
        unsigned int reserved:24;
        unsigned int counters_mask:8;
    } split;
    unsigned int full;
};

union cpuid10_edx {
    struct {
        unsigned int num_counters_fixed:5;
        unsigned int reserved:27;
    } split;
    unsigned int full;
};

struct cpuinfo_x86 boot_cpu_data;
struct x86_pmu x86_pmu;
struct x86_pmu core_pmu;
struct x86_pmu intel_pmu;
unsigned int hw_cache_event_ids[32];
unsigned int hw_cache_extra_regs[32];
unsigned int intel_perfmon_event_map[2];
unsigned int core2_hw_cache_event_ids[32];
unsigned int nehalem_hw_cache_event_ids[32];
unsigned int nehalem_hw_cache_extra_regs[32];
unsigned int atom_hw_cache_event_ids[32];
unsigned int westmere_hw_cache_event_ids[32];
unsigned int snb_hw_cache_event_ids[32];
unsigned int snb_hw_cache_extra_regs[32];
struct event_constraint *intel_core2_event_constraints;
struct event_constraint *intel_core2_pebs_event_constraints;
struct event_constraint *intel_nehalem_event_constraints;
struct event_constraint *intel_nehalem_pebs_event_constraints;
struct event_constraint *intel_gen_event_constraints;
struct event_constraint *intel_atom_pebs_event_constraints;
struct event_constraint *intel_westmere_event_constraints;
struct event_constraint *intel_westmere_pebs_event_constraints;
struct event_constraint *intel_snb_event_constraints;
struct event_constraint *intel_snb_pebs_event_constraints;
struct event_constraint *intel_pebs_aliases_snb;
struct event_constraint *intel_ivb_event_constraints;
struct event_constraint *intel_ivb_pebs_event_constraints;
struct event_constraint *intel_v1_event_constraints;
unsigned long *intel_nehalem_extra_regs;
unsigned long *intel_westmere_extra_regs;
unsigned long *intel_snb_extra_regs;
unsigned long *intel_snbep_extra_regs;

static inline int cpu_has(struct cpuinfo_x86 *c, int bit) { return 1; }
static inline void cpuid(unsigned int op, unsigned int *eax, unsigned int *ebx, unsigned int *ecx, unsigned int *edx) {}
static inline void rdmsrl(unsigned int msr, u64 *val) {}
static inline void intel_ds_init(void) {}
static inline void intel_pmu_lbr_init_core(void) {}
static inline void intel_pmu_lbr_init_nhm(void) {}
static inline void intel_pmu_lbr_init_atom(void) {}
static inline void intel_pmu_lbr_init_snb(void) {}
static inline void x86_add_quirk(void (*quirk)(void)) {}
static inline void intel_arch_events_quirk(void) {}
static inline void intel_clovertown_quirk(void) {}
static inline void intel_nehalem_quirk(void) {}
static inline void intel_sandybridge_quirk(void) {}
static inline void intel_pmu_nhm_enable_all(void) {}
static inline int p6_pmu_init(void) { return 0; }
static inline int knc_pmu_init(void) { return 0; }
static inline int p4_pmu_init(void) { return 0; }
#define X86_CONFIG(...) 0
#define for_each_event_constraint(c, constraints) for ((c) = (constraints); (c); (c) = NULL)