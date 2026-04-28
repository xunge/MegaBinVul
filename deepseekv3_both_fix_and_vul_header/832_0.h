#include <stdint.h>
#include <asm/msr.h>

#define X86_CR4_FSGSBASE (1UL << 16)

static inline unsigned long read_cr4(void)
{
    unsigned long val;
    asm volatile("mov %%cr4, %0" : "=r" (val));
    return val;
}

static inline void wrmsrl(uint32_t msr, uint64_t val)
{
    uint32_t low = val;
    uint32_t high = val >> 32;
    asm volatile("wrmsr" : : "c" (msr), "a" (low), "d" (high));
}

#define MSR_SHADOW_GS_BASE 0xc0000102
extern int cpu_has_fsgsbase;