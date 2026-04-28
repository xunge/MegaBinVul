#include <stdint.h>
#include <inttypes.h>

#define PRIregister "lx"
#define XENLOG_ERR 1

typedef uint64_t register_t;

#define HSR_SYSREG_REGS_MASK 0xFFFF
#define HSR_SYSREG_DBG_CASES(reg) \
    case HSR_SYSREG_##reg##0_EL1: \
    case HSR_SYSREG_##reg##1_EL1: \
    case HSR_SYSREG_##reg##2_EL1: \
    case HSR_SYSREG_##reg##3_EL1: \
    case HSR_SYSREG_##reg##4_EL1: \
    case HSR_SYSREG_##reg##5_EL1: \
    case HSR_SYSREG_##reg##6_EL1: \
    case HSR_SYSREG_##reg##7_EL1: \
    case HSR_SYSREG_##reg##8_EL1: \
    case HSR_SYSREG_##reg##9_EL1: \
    case HSR_SYSREG_##reg##10_EL1: \
    case HSR_SYSREG_##reg##11_EL1: \
    case HSR_SYSREG_##reg##12_EL1: \
    case HSR_SYSREG_##reg##13_EL1: \
    case HSR_SYSREG_##reg##14_EL1: \
    case HSR_SYSREG_##reg##15_EL1

struct cpu_user_regs {
    register_t pc;
};

struct hsr_sysreg {
    uint32_t reg:5;
    uint32_t read:1;
    uint32_t len:1;
    uint32_t op0:2;
    uint32_t op1:3;
    uint32_t crn:4;
    uint32_t crm:4;
    uint32_t op2:3;
};

union hsr {
    uint32_t bits;
    struct hsr_sysreg sysreg;
};

enum {
    HSR_SYSREG_MDSCR_EL1,
    HSR_SYSREG_PMINTENSET_EL1,
    HSR_SYSREG_PMINTENCLR_EL1,
    HSR_SYSREG_PMCR_EL0,
    HSR_SYSREG_PMCNTENSET_EL0,
    HSR_SYSREG_PMCNTENCLR_EL0,
    HSR_SYSREG_PMOVSCLR_EL0,
    HSR_SYSREG_PMSWINC_EL0,
    HSR_SYSREG_PMSELR_EL0,
    HSR_SYSREG_PMCEID0_EL0,
    HSR_SYSREG_PMCEID1_EL0,
    HSR_SYSREG_PMCCNTR_EL0,
    HSR_SYSREG_PMXEVTYPER_EL0,
    HSR_SYSREG_PMXEVCNTR_EL0,
    HSR_SYSREG_PMUSERENR_EL0,
    HSR_SYSREG_PMOVSSET_EL0,
    HSR_SYSREG_OSDLR_EL1,
    HSR_SYSREG_OSLAR_EL1,
    HSR_SYSREG_CNTP_CTL_EL0,
    HSR_SYSREG_CNTP_TVAL_EL0,
    HSR_SYSREG_DBGBVR0_EL1,
    HSR_SYSREG_DBGBVR1_EL1,
    HSR_SYSREG_DBGBVR2_EL1,
    HSR_SYSREG_DBGBVR3_EL1,
    HSR_SYSREG_DBGBVR4_EL1,
    HSR_SYSREG_DBGBVR5_EL1,
    HSR_SYSREG_DBGBVR6_EL1,
    HSR_SYSREG_DBGBVR7_EL1,
    HSR_SYSREG_DBGBVR8_EL1,
    HSR_SYSREG_DBGBVR9_EL1,
    HSR_SYSREG_DBGBVR10_EL1,
    HSR_SYSREG_DBGBVR11_EL1,
    HSR_SYSREG_DBGBVR12_EL1,
    HSR_SYSREG_DBGBVR13_EL1,
    HSR_SYSREG_DBGBVR14_EL1,
    HSR_SYSREG_DBGBVR15_EL1,
    HSR_SYSREG_DBGBCR0_EL1,
    HSR_SYSREG_DBGBCR1_EL1,
    HSR_SYSREG_DBGBCR2_EL1,
    HSR_SYSREG_DBGBCR3_EL1,
    HSR_SYSREG_DBGBCR4_EL1,
    HSR_SYSREG_DBGBCR5_EL1,
    HSR_SYSREG_DBGBCR6_EL1,
    HSR_SYSREG_DBGBCR7_EL1,
    HSR_SYSREG_DBGBCR8_EL1,
    HSR_SYSREG_DBGBCR9_EL1,
    HSR_SYSREG_DBGBCR10_EL1,
    HSR_SYSREG_DBGBCR11_EL1,
    HSR_SYSREG_DBGBCR12_EL1,
    HSR_SYSREG_DBGBCR13_EL1,
    HSR_SYSREG_DBGBCR14_EL1,
    HSR_SYSREG_DBGBCR15_EL1,
    HSR_SYSREG_DBGWVR0_EL1,
    HSR_SYSREG_DBGWVR1_EL1,
    HSR_SYSREG_DBGWVR2_EL1,
    HSR_SYSREG_DBGWVR3_EL1,
    HSR_SYSREG_DBGWVR4_EL1,
    HSR_SYSREG_DBGWVR5_EL1,
    HSR_SYSREG_DBGWVR6_EL1,
    HSR_SYSREG_DBGWVR7_EL1,
    HSR_SYSREG_DBGWVR8_EL1,
    HSR_SYSREG_DBGWVR9_EL1,
    HSR_SYSREG_DBGWVR10_EL1,
    HSR_SYSREG_DBGWVR11_EL1,
    HSR_SYSREG_DBGWVR12_EL1,
    HSR_SYSREG_DBGWVR13_EL1,
    HSR_SYSREG_DBGWVR14_EL1,
    HSR_SYSREG_DBGWVR15_EL1,
    HSR_SYSREG_DBGWCR0_EL1,
    HSR_SYSREG_DBGWCR1_EL1,
    HSR_SYSREG_DBGWCR2_EL1,
    HSR_SYSREG_DBGWCR3_EL1,
    HSR_SYSREG_DBGWCR4_EL1,
    HSR_SYSREG_DBGWCR5_EL1,
    HSR_SYSREG_DBGWCR6_EL1,
    HSR_SYSREG_DBGWCR7_EL1,
    HSR_SYSREG_DBGWCR8_EL1,
    HSR_SYSREG_DBGWCR9_EL1,
    HSR_SYSREG_DBGWCR10_EL1,
    HSR_SYSREG_DBGWCR11_EL1,
    HSR_SYSREG_DBGWCR12_EL1,
    HSR_SYSREG_DBGWCR13_EL1,
    HSR_SYSREG_DBGWCR14_EL1,
    HSR_SYSREG_DBGWCR15_EL1
};

register_t *select_user_reg(struct cpu_user_regs *regs, uint32_t reg);
int vtimer_emulate(struct cpu_user_regs *regs, union hsr hsr);
void dprintk(int level, const char *fmt, ...);
void domain_crash_synchronous(void);
void gdprintk(int level, const char *fmt, ...);
void inject_undef_exception(struct cpu_user_regs *regs, uint32_t len);
void inject_undef64_exception(struct cpu_user_regs *regs, uint32_t len);