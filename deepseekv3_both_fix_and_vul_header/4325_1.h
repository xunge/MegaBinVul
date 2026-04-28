#include <stdint.h>

#define __init
typedef uint32_t u32;

struct cpuinfo_x86 {
    int cpuid_level;
    char x86_vendor_id[12];
    int x86_vendor;
    int x86;
    int x86_model;
    int x86_mask;
    int x86_cache_alignment;
    uint32_t x86_capability[2];
};

extern struct cpuinfo_x86 boot_cpu_data;
extern uint32_t cleared_caps[];
extern uint32_t paddr_bits;
extern uint32_t hap_paddr_bits;

enum cpufeat_word {
    X86_FEATURE_FPU,
    X86_FEATURE_SSE3,
    X86_FEATURE_CLFLUSH
};

enum gcv_host_early {
    gcv_host_early
};

static inline void cpuid(uint32_t op, uint32_t *eax, uint32_t *ebx, uint32_t *ecx, uint32_t *edx);
static inline uint32_t cpuid_eax(uint32_t op);
static inline uint32_t cpufeat_word(enum cpufeat_word feature);
static inline uint32_t cpufeat_mask(enum cpufeat_word feature);
static inline int get_cpu_vendor(const char *vendor_id, enum gcv_host_early early);