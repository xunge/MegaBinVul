#include <stdint.h>

#define ASSERT(cond) ((void)0)

#define X86_CR4_PGE    (1UL << 7)
#define X86_CR4_PCIDE  (1UL << 17)
#define X86_CR4_FSGSBASE (1UL << 16)

struct cpu_info {
    unsigned long cr4;
};

struct cpu_info *get_cpu_info(void);