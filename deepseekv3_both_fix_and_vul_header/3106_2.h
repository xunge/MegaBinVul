#include <stdarg.h>
#include <stdio.h>
#include <signal.h>

struct pt_regs {
    unsigned long pc;
};

#define __user

extern const char *handler[];
extern void console_verbose(void);
extern void die(const char *msg, struct pt_regs *regs, long err);
extern void local_irq_disable(void);
extern void panic(const char *fmt, ...);
extern unsigned long instruction_pointer(struct pt_regs *regs);
extern void __show_regs(struct pt_regs *regs);
extern void arm64_notify_die(const char *str, struct pt_regs *regs, siginfo_t *info, int err);

#define pr_crit(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define asmlinkage