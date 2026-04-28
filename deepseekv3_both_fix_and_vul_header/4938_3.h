#include <stdint.h>
#include <inttypes.h>

#define XENLOG_ERR 0
#define PRIregister "llx"
#define HSR_CP64_REGS_MASK 0xF
#define HSR_CPREG64(x) (0)
#define CNTPCT 0
#define NDEBUG

struct cpu_user_regs {
    uint64_t pc;
};

union hsr {
    uint32_t bits;
    struct {
        uint32_t len:1;
        uint32_t crm:4;
        uint32_t reg2:4;
        uint32_t reg1:4;
        uint32_t op1:3;
        uint32_t read:1;
    } cp64;
    uint32_t len;
};

struct hsr_cp64 {
    uint8_t read;
    uint8_t op1;
    uint8_t reg1;
    uint8_t reg2;
    uint8_t crm;
};

static int check_conditional_instr(struct cpu_user_regs *regs, union hsr hsr);
static void advance_pc(struct cpu_user_regs *regs, union hsr hsr);
static int vtimer_emulate(struct cpu_user_regs *regs, union hsr hsr);
static void dprintk(int level, const char *fmt, ...);
static void domain_crash_synchronous(void);
static void gdprintk(int level, const char *fmt, ...);
static void inject_undef_exception(struct cpu_user_regs *regs, int len);