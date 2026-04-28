#include <stdint.h>

#define BUG_ON(condition) do { if (condition) {} } while (0)
#define READ_SYSREG(reg) (0)
#define WRITE_SYSREG32(value, reg) do {} while (0)

#define HSR_EC_UNKNOWN 0
#define VECTOR64_SYNC_OFFSET 0
#define VECTOR64_CURRENT_SPx_SYNC 0
#define PSR_MODE_EL1h 0
#define PSR_ABT_MASK 0
#define PSR_FIQ_MASK 0
#define PSR_IRQ_MASK 0
#define PSR_DBG_MASK 0
#define ESR_EL1 0
#define VBAR_EL1 0

typedef uint64_t vaddr_t;

struct cpu_user_regs {
    uint64_t cpsr;
    uint64_t pc;
    uint64_t spsr_el1;
    uint64_t elr_el1;
};

struct domain {
    int unused;
};

struct task_struct {
    struct domain *domain;
};

extern struct task_struct *current;

union hsr {
    struct {
        uint32_t iss : 25;
        uint32_t len : 4;
        uint32_t ec : 8;
    };
    uint32_t bits;
};

vaddr_t exception_handler64(struct cpu_user_regs *regs, int offset);
int is_32bit_domain(struct domain *d);