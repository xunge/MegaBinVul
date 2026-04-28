#include <stdarg.h>
#include <stdbool.h>

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

struct domain;
struct vcpu {
    struct mc_state mc_state;
    struct domain *domain;
    bool hcall_preempted;
};

extern struct vcpu *current;
extern struct cpu_user_regs *guest_cpu_user_regs(void);
extern void gprintk(int level, const char *fmt, ...);
extern void domain_crash(struct domain *d);
#define XENLOG_ERR 0
#define MCSF_in_multicall (1 << 0)
#define CONFIG_ARM_64 1
#define ASSERT_UNREACHABLE() do { } while (0)
#define BUG_ON(cond) do { if (cond) { } } while (0)

static inline bool is_32bit_domain(struct domain *d) { return false; }
static inline unsigned long NEXT_ARG(const char *p, va_list args) { return va_arg(args, unsigned long); }
static inline unsigned long next_arg(const char *p, va_list args) { return va_arg(args, unsigned long); }