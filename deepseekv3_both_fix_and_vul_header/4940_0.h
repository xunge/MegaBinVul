#include <stdint.h>

#define PSR_THUMB (1 << 5)
#define PSR_MODE_ABT 0x17

#define VECTOR32_PABT 0x0C
#define VECTOR32_DABT 0x10

#define FSR_LPAE (1 << 9)
#define FSRL_STATUS_DEBUG 0x22
#define FSRS_FS_DEBUG 0x02

#define TTBCR_EAE (1 << 31)

struct cpu_user_regs {
    uint32_t cpsr;
    uint32_t spsr_abt;
    uint32_t lr_abt;
    uint32_t pc32;
};

struct domain {
    int dummy;
};

struct vcpu {
    struct domain *domain;
};

extern struct vcpu *current;

#define BUG_ON(condition) ((void)0)

#define READ_SYSREG(reg) (0)
#define WRITE_SYSREG(value, reg) ((void)0)

#define CONFIG_ARM_32 1

typedef uint64_t register_t;

uint32_t exception_handler(uint32_t vector);

static inline void cpsr_switch_mode(struct cpu_user_regs *regs, uint32_t mode)
{
    regs->cpsr = (regs->cpsr & ~0x1F) | mode;
}

static inline int is_32bit_domain(const struct domain *d)
{
    return 1;
}