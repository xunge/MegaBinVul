#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define X86_FEATURE_ARCH_PERFMON 0
#define X86_FEATURE_XTOPOLOGY 0
#define X86_FEATURE_CONSTANT_TSC 0
#define X86_FEATURE_ITSC 0
#define X86_FEATURE_NONSTOP_TSC 0
#define X86_FEATURE_TSC_RELIABLE 0
#define X86_FEATURE_ARAT 0
#define X86_FEATURE_CLWB 0
#define INTEL_FAM6_SKYLAKE_X 0

struct cpuinfo_x86 {
    unsigned int cpuid_level;
    unsigned int x86_capability[1];
    unsigned int x86;
    unsigned int x86_model;
    unsigned int x86_max_cores;
    unsigned int x86_num_siblings;
    unsigned int apicid;
};

extern struct cpuinfo_x86 boot_cpu_data;
extern bool opt_arat;
extern bool opt_cpu_info;

static inline void __set_bit(int nr, volatile void *addr) {}
static inline bool cpu_has(const struct cpuinfo_x86 *c, int feature) { return false; }
static inline unsigned int cpuid_eax(unsigned int op) { return 0; }
static inline void detect_extended_topology(struct cpuinfo_x86 *c) {}
static inline void init_intel_cacheinfo(struct cpuinfo_x86 *c) {}
static inline unsigned int num_cpu_cores(struct cpuinfo_x86 *c) { return 0; }
static inline void detect_ht(struct cpuinfo_x86 *c) {}
static inline void Intel_errata_workarounds(struct cpuinfo_x86 *c) {}
static inline void intel_log_freq(struct cpuinfo_x86 *c) {}
static inline void setup_clear_cpu_cap(int feature) {}

#define cf_check