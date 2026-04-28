#include <stdbool.h>

struct pt_regs {
    unsigned long nip;
};

struct power_pmu {
    unsigned long flags;
};

#define PPMU_P10_DD1 (1UL << 0)
#define SPRN_SIAR 0x1F0

extern struct power_pmu *ppmu;

unsigned long mfspr(unsigned long spr);
bool regs_use_siar(struct pt_regs *regs);
bool siar_valid(struct pt_regs *regs);
unsigned long perf_ip_adjust(struct pt_regs *regs);