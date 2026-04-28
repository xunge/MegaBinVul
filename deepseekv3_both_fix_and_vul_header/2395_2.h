#include <signal.h>
#include <linux/kernel.h>

#define CONFIG_ALTIVEC 0
#define KERN_EMERG "<0>"

struct pt_regs {
    unsigned long nip;
    unsigned long trap;
};

int user_mode(struct pt_regs *regs);
void _exception(int sig, struct pt_regs *regs, int code, unsigned long addr);
void printk(const char *fmt, ...); 
void die(const char *str, struct pt_regs *regs, long err);