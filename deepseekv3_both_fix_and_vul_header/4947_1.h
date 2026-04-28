#include <stdint.h>

struct cpu_user_regs {
    uint32_t pc;
};

struct domain {
    struct {
        uint32_t vpidr;
    } arch;
};

struct hsr_cp32 {
    unsigned int reg:4;
    unsigned int read:1;
    unsigned int op1:3;
    unsigned int crn:4;
    unsigned int crm:4;
    unsigned int op2:3;
};

union hsr {
    uint32_t bits;
    struct hsr_cp32 cp32;
    uint32_t len;
};

struct current {
    struct domain *domain;
};
extern struct current *current;

#define HSR_CP32_REGS_MASK 0x0000ffff
#define HSR_CPREG32(reg) (0x10000 | (reg))
#define DBGDIDR 0
#define DBGDSCRINT 1
#define DBGDSCREXT 2
#define DBGVCR 3
#define DBGOSLAR 4
#define DBGBVR0 5
#define DBGBCR0 6
#define DBGWVR0 7
#define DBGWCR0 8
#define DBGBVR1 9
#define DBGBCR1 10
#define DBGOSDLR 11

#define NDEBUG
#define XENLOG_ERR 0
#define PRIregister "lx"

void *select_user_reg(struct cpu_user_regs *regs, unsigned int reg);
int check_conditional_instr(struct cpu_user_regs *regs, union hsr hsr);
void advance_pc(struct cpu_user_regs *regs, union hsr hsr);
void gdprintk(int level, const char *fmt, ...);
void inject_undef_exception(struct cpu_user_regs *regs, uint32_t len);