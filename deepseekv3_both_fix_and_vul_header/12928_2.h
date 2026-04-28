#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define FLUSH_ORDER_MASK 0x1f
#define FLUSH_TLB (1U << 0)
#define FLUSH_TLB_GLOBAL (1U << 1)
#define FLUSH_HVM_ASID_CORE (1U << 2)
#define FLUSH_CACHE (1U << 3)
#define FLUSH_VA_VALID (1U << 4)
#define FLUSH_ROOT_PGTBL (1U << 5)

#define X86_CR4_PCIDE (1U << 17)
#define X86_FEATURE_CLFLUSHOPT (1U << 23)

#define PAGE_SHIFT 12
#define BITS_PER_LONG (sizeof(unsigned long) * 8)

#define PCID_PV_PRIV 0
#define PCID_PV_USER 1
#define PCID_PV_XPTI 2

struct cpuinfo_x86 {
    unsigned int x86_clflush_size;
    unsigned int x86_cache_size;
};

struct cpu_info {
    bool root_pgt_changed;
};

extern struct cpuinfo_x86 current_cpu_data;
extern bool opt_xpti_hwdom;
extern bool opt_xpti_domu;

static inline unsigned long read_cr4(void) { return 0; }
static inline void invpcid_flush_one(unsigned int pcid, unsigned long addr) {}
static inline void do_tlb_flush(void) {}
static inline void hvm_flush_guest_tlbs(void) {}
static inline void wbinvd(void) {}
static inline struct cpu_info *get_cpu_info(void) { return NULL; }

#define alternative(old, new, feature) \
    asm volatile (new ::: "memory")

#define alternative_input(old, new, feature, input) \
    asm volatile (new : : input)