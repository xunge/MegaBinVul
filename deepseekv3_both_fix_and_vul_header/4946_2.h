#include <stdint.h>
#include <inttypes.h>

struct cpu_user_regs {
    uintptr_t pc;
};

struct hsr_cp64 {
    unsigned int read : 1;
    unsigned int op1 : 3;
    unsigned int reg1 : 4;
    unsigned int reg2 : 4;
    unsigned int crm : 4;
};

union hsr {
    struct {
        uint32_t len : 1;
        uint32_t bits;
    };
    struct hsr_cp64 cp64;
};

#define NDEBUG
#define XENLOG_ERR 0
#define HSR_CP64_REGS_MASK 0xFFFF
#define PRIregister "lx"

static int check_conditional_instr(struct cpu_user_regs *regs, union hsr hsr);
static void advance_pc(struct cpu_user_regs *regs, union hsr hsr);
static void gdprintk(int level, const char *fmt, ...);
static void inject_undef_exception(struct cpu_user_regs *regs, int len);