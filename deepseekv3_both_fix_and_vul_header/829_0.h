#include <stdint.h>

#define X86_CR4_FSGSBASE (1UL << 16)
#define MSR_FS_BASE 0xc0000100

static inline unsigned long read_cr4(void)
{
    unsigned long cr4;
    asm volatile("mov %%cr4, %0" : "=r" (cr4));
    return cr4;
}

static inline void wrmsrl(uint32_t msr, uint64_t val)
{
    uint32_t low = val, high = val >> 32;
    asm volatile("wrmsr" :: "c" (msr), "a" (low), "d" (high));
}

extern int cpu_has_fsgsbase;