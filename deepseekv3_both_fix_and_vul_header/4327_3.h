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
    X86_FEATURE_FPU = 0,
    X86_FEATURE_SSE3 = 1,
    X86_FEATURE_CLFLUSH = 2
};

#define gcv_host_early 0

static inline void cpuid(uint32_t op, uint32_t *eax, uint32_t *ebx, uint32_t *ecx, uint32_t *edx) {
    *eax = op;
    *ebx = 0;
    *ecx = 0;
    *edx = 0;
}

static inline uint32_t cpuid_eax(uint32_t op) {
    uint32_t eax, ebx, ecx, edx;
    cpuid(op, &eax, &ebx, &ecx, &edx);
    return eax;
}

static inline uint32_t cpufeat_word(enum cpufeat_word feat) {
    return feat / 32;
}

static inline uint32_t cpufeat_mask(enum cpufeat_word feat) {
    return 1U << (feat % 32);
}

static inline int get_cpu_vendor(const char *vendor_id, int host) {
    return 0;
}