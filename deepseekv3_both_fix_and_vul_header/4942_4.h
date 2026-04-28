#include <stdint.h>
#include <stdbool.h>

struct cpu_user_regs {
    uint32_t pc;
};

struct vcpu {
    struct {
        uint32_t actlr;
    } arch;
};

struct hsr_cp32 {
    unsigned int reg:4;
    bool read:1;
    unsigned int op1:3;
    unsigned int crn:4;
    unsigned int crm:4;
    unsigned int op2:3;
};

union hsr {
    uint32_t bits;
    struct hsr_cp32 cp32;
    struct {
        uint32_t len:2;
    };
};

#define HSR_CP32_REGS_MASK 0x0000FFFF
#define HSR_CPREG32(reg) (reg##_VAL)

#define CLIDR_VAL 0x00000001
#define CCSIDR_VAL 0x00000002
#define DCCISW_VAL 0x00000003
#define CNTP_CTL_VAL 0x00000004
#define CNTP_TVAL_VAL 0x00000005
#define ACTLR_VAL 0x00000006
#define PMCR_VAL 0x00000007
#define PMCNTENSET_VAL 0x00000008
#define PMCNTENCLR_VAL 0x00000009
#define PMOVSR_VAL 0x0000000A
#define PMSWINC_VAL 0x0000000B
#define PMSELR_VAL 0x0000000C
#define PMCEID0_VAL 0x0000000D
#define PMCEID1_VAL 0x0000000E
#define PMCCNTR_VAL 0x0000000F
#define PMXEVCNTR_VAL 0x00000010
#define PMXEVCNR_VAL 0x00000011
#define PMUSERENR_VAL 0x00000012
#define PMINTENSET_VAL 0x00000013
#define PMINTENCLR_VAL 0x00000014
#define PMOVSSET_VAL 0x00000015

#define CONFIG_ARM_32
#define XENLOG_ERR 0
#define PRIregister "lx"

#define READ_SYSREG32(reg) (0)
#define WRITE_CP32(val, reg) do {} while (0)

static void *select_user_reg(struct cpu_user_regs *regs, unsigned int reg);
static bool check_conditional_instr(struct cpu_user_regs *regs, union hsr hsr);
static void advance_pc(struct cpu_user_regs *regs, union hsr hsr);
static void dprintk(int level, const char *fmt, ...);
static void domain_crash_synchronous(void);
static bool vtimer_emulate(struct cpu_user_regs *regs, union hsr hsr);
static void gdprintk(int level, const char *fmt, ...);
static void inject_undef_exception(struct cpu_user_regs *regs, unsigned int len);
#define current ((struct vcpu *)0)
#define NDEBUG