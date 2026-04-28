#include <stdarg.h>
#include <stdbool.h>

struct mc_state {
    unsigned int flags;
    struct {
        unsigned long args[6];
    } call;
};

struct cpu_user_regs {
    unsigned long rax;
    unsigned long rbx;
    unsigned long rcx;
    unsigned long rdx;
    unsigned long rsi;
    unsigned long rdi;
    unsigned long rbp;
    unsigned long r8;
    unsigned long r9;
    unsigned long r10;
};

struct domain;

struct vcpu {
    bool hcall_preempted;
    bool hcall_compat;
    struct mc_state mc_state;
    struct domain *domain;
};

#define MCSF_in_multicall (1 << 0)
#define XENLOG_ERR 0

extern struct vcpu *current;
extern struct cpu_user_regs *guest_cpu_user_regs(void);
extern unsigned long next_arg(const char *p, va_list args);
extern void gprintk(int level, const char *fmt, ...);
extern void ASSERT_UNREACHABLE(void);
extern void domain_crash(struct domain *d);