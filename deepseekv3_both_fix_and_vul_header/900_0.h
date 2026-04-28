#include <stdarg.h>
#include <stdbool.h>

#define NEXT_ARG(p, args) next_arg(p, args)
#define MCSF_in_multicall (1 << 0)

struct cpu_user_regs {
    unsigned long x0, x1, x2, x3, x4, x5, x16;
    unsigned long r0, r1, r2, r3, r4, r5, r12;
};

struct mc_call {
    unsigned long args[6];
    unsigned long result;
};

struct mc_state {
    unsigned int flags;
    struct mc_call call;
};

struct domain;
struct vcpu {
    struct domain *domain;
    bool hcall_preempted;
    struct mc_state mc_state;
};

extern struct vcpu *current;
extern struct cpu_user_regs *guest_cpu_user_regs(void);
extern unsigned long next_arg(const char *p, va_list args);
extern void gprintk(int level, const char *fmt, ...);
extern void domain_crash(struct domain *d);
#define XENLOG_ERR 0
#define ASSERT_UNREACHABLE() 
#define BUG_ON(cond) 