#include <stddef.h>

struct pt_regs {
    unsigned long ip;
};

struct task_struct {
    char comm[16];
};

extern struct task_struct *current;
extern int task_pid_nr(struct task_struct *t);
extern void printk(const char *fmt, ...);
extern void preempt_disable(void);
extern void preempt_enable(void);
extern void show_regs(struct pt_regs *regs);
extern int __get_user(unsigned char, unsigned char *);