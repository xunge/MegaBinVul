#include <stdbool.h>
#include <assert.h>

struct cpu_user_regs;

struct hsr_cp {
    bool tas;
    int coproc;
};

union hsr {
    struct {
        unsigned int len;
    };
    struct hsr_cp cp;
};

#define XENLOG_ERR 0

bool check_conditional_instr(struct cpu_user_regs *regs, union hsr hsr);
void advance_pc(struct cpu_user_regs *regs, union hsr hsr);
void inject_undef_exception(struct cpu_user_regs *regs, int len);
void gdprintk(int level, const char *fmt, ...);
#define ASSERT(x) assert(x)