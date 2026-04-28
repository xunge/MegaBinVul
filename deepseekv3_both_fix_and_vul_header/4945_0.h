#include <stdint.h>

#define PSR_THUMB (1 << 5)
#define PSR_MODE_UND 0x1b
#define VECTOR32_UND 0x04

struct cpu_user_regs {
    uint32_t cpsr;
    uint32_t pc32;
    uint32_t spsr_und;
    uint32_t lr_und;
};

struct domain {
    // placeholder for domain structure
};

struct vcpu {
    struct domain *domain;
    // other vcpu fields
};

extern struct vcpu *current;

#define BUG_ON(condition) ((void)0)

static void cpsr_switch_mode(struct cpu_user_regs *regs, uint32_t mode);
static uint32_t exception_handler(uint32_t vector);
static int is_32bit_domain(struct domain *d);