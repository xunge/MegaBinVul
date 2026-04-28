#include <stdint.h>
#include <stddef.h>

#define PAGE_SHIFT 12
#define __init
#define __initconst
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

#define X86_FEATURE_HYPERVISOR (1 << 31)
#define X86_FEATURE_HLE (1 << 4)

struct platform_bad_page {
    unsigned long mfn;
    unsigned int order;
};

static inline uint32_t cpuid_eax(uint32_t level) { return 0; }
static inline uint32_t cpuid_ecx(uint32_t level) { return 0; }
static inline uint32_t cpuid_count_ebx(uint32_t level, uint32_t count) { return 0; }
static inline uint32_t cpufeat_mask(uint32_t feature) { return feature; }
static inline uint32_t pci_conf_read32(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e) { return 0; }
#define IS_SNB_GFX(id) (0)

typedef uint32_t u32;