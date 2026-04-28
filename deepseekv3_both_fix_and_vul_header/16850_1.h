#include <stdint.h>
#include <linux/types.h>

#define X86_VENDOR_INTEL 0
#define INTEL_FAM6_IVYBRIDGE 0
#define INTEL_FAM6_SKYLAKE_X 0
#define X86_FEATURE_RDRAND 0
#define X86_FEATURE_CLWB 0
#define X86_FEATURE_RTM 0

struct cpuinfo_x86 {
    int x86_vendor;
    int x86;
    int x86_model;
};

extern struct cpuinfo_x86 boot_cpu_data;
extern int cpu_has_rdrand;
extern int rtm_disabled;
extern int is_forced_cpu_cap(int);
extern void __clear_bit(int, uint32_t*);

struct {
    struct {
        int clwb;
    } feat;
} raw_cpu_policy;

#define __init