#include <stdint.h>

typedef uint64_t register_t;
typedef uint64_t vaddr_t;

#define BUG_ON(condition) ((void)0)
#define WRITE_SYSREG(v, name) ((void)0)
#define WRITE_SYSREG32(v, name) ((void)0)
#define READ_SYSREG(name) (0)

#define PSR_MODE_EL0t 0
#define PSR_MODE_EL1h 0
#define PSR_ABT_MASK 0
#define PSR_FIQ_MASK 0
#define PSR_IRQ_MASK 0
#define PSR_DBG_MASK 0

#define HSR_EC_INSTR_ABORT_LOWER_EL 0
#define HSR_EC_DATA_ABORT_LOWER_EL 0
#define HSR_EC_INSTR_ABORT_CURR_EL 0
#define HSR_EC_DATA_ABORT_CURR_EL 0

#define VECTOR64_SYNC_OFFSET 0
#define VECTOR64_CURRENT_SPx_SYNC 0

struct cpu_user_regs {
    uint64_t cpsr;
    uint64_t pc;
    uint64_t spsr_el1;
    uint64_t elr_el1;
};

struct domain {
    int dummy;
};

extern struct domain *current;

union hsr {
    struct {
        uint32_t iss;
        uint32_t ec;
        uint32_t len;
    };
    uint32_t bits;
};

static inline int psr_mode_is_32bit(uint64_t cpsr) { return 0; }
static inline int psr_mode(uint64_t cpsr, int mode) { return 0; }
static inline int is_32bit_domain(struct domain *d) { return 0; }
static inline vaddr_t exception_handler64(struct cpu_user_regs *regs, int offset) { return 0; }