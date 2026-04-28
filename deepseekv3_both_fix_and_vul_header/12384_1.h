#define asmlinkage

struct cpu_user_regs;

void do_unexpected_trap(const char *msg, struct cpu_user_regs *regs);