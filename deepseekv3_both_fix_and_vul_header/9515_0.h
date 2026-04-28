#include <stdarg.h>
#include <stddef.h>

#define BUG_ON(condition) do { if (condition) ; } while (0)
#define test_bit(nr, addr) (0)
#define _MCSF_in_multicall 0
#define _MCSF_call_preempted 1

struct mc_state {
    unsigned long flags;
    struct {
        unsigned int args[6];
    } call;
};

struct cpu_user_regs {
    unsigned long ebx;
    unsigned long ecx;
    unsigned long edx;
    unsigned long esi;
    unsigned long edi;
    unsigned long ebp;
};

extern struct cpu_user_regs *guest_cpu_user_regs(void);
extern struct {
    struct mc_state mc_state;
} *current;