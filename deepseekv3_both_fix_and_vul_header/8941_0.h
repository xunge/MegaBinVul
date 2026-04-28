#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

struct mc_state {
    unsigned long flags;
    struct {
        unsigned long args[6];
        unsigned long result;
    } call;
};

struct cpu_user_regs {
    uint64_t pc;
    union {
        struct {
            uint64_t x0, x1, x2, x3, x4, x5, x16;
        };
        struct {
            uint32_t r0, r1, r2, r3, r4, r5, r12;
        };
    };
};

struct vcpu {
    struct domain *domain;
    struct mc_state mc_state;
};

extern struct vcpu *current;

#define _MCSF_in_multicall 0
#define _MCSF_call_preempted 1
#define BUG_ON(cond) do { if (cond) BUG(); } while (0)
#define BUG() (*(volatile int *)0 = 0)
#define test_bit(nr, addr) ((*(addr) & (1UL << (nr))) != 0)
#define __set_bit(nr, addr) (*(addr) |= (1UL << (nr)))

static inline unsigned long next_arg(const char **p, va_list args) {
    switch (*(*p)++) {
        case 'l': return va_arg(args, unsigned long);
        case 'i': return va_arg(args, unsigned int);
        default: BUG(); return 0;
    }
}

static inline struct cpu_user_regs *guest_cpu_user_regs(void) {
    extern struct cpu_user_regs guest_regs;
    return &guest_regs;
}

static inline int is_32bit_domain(struct domain *d) {
    return 0;
}