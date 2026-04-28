#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>

struct mc_state {
    unsigned int flags;
    struct {
        unsigned long args[6];
        unsigned long result;
    } call;
};

struct cpu_user_regs {
    unsigned long x0, x1, x2, x3, x4, x5, x16;
    unsigned long r0, r1, r2, r3, r4, r5, r12;
};

struct vcpu {
    struct mc_state mc_state;
    bool hcall_preempted;
    struct domain *domain;
};

struct domain {
    // domain fields
};

extern struct vcpu *current;

#define MCSF_in_multicall (1 << 0)
#define NEXT_ARG(p, args) next_arg(p, args)
#define BUG_ON(cond) do { if (cond) for(;;); } while (0)
#define ASSERT_UNREACHABLE() BUG_ON(1)
#define XENLOG_ERR 1

static inline unsigned long next_arg(const char *p, va_list args) {
    return va_arg(args, unsigned long);
}

static inline struct cpu_user_regs *guest_cpu_user_regs(void) {
    return NULL;
}

static inline bool is_32bit_domain(struct domain *d) {
    return false;
}

static inline void gprintk(int level, const char *fmt, ...) {
    (void)level;
    (void)fmt;
}

static inline void domain_crash(struct domain *d) {
    (void)d;
}