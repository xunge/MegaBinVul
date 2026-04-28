#include <stdint.h>

#define X86_VENDOR_INTEL 0
#define X86_FEATURE_ARCH_CAPS 0
#define X86_FEATURE_RSBA 0
#define X86_FEATURE_RRSBA 0
#define X86_FEATURE_CLWB 0
#define INTEL_FAM6_SKYLAKE_X 0

struct cpuinfo_x86 {
    int x86_vendor;
    int x86;
    int x86_model;
};

struct cpu_policy {
    struct {
        unsigned int clwb;
    } feat;
};

extern struct cpuinfo_x86 boot_cpu_data;
extern struct cpu_policy raw_cpu_policy;

static inline void __set_bit(int nr, uint32_t *addr) {
    addr[nr / 32] |= (1U << (nr % 32));
}

#define __init