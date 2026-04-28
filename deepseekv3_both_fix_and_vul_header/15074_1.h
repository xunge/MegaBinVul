#include <stdio.h>
#include <stddef.h>

#define KERN_DEBUG ""
#define KERN_CRIT ""
#define RFMT "%lx"
#define PRINTREGS(level, reg, name, fmt, i)
#define print_gr(level, regs)
#define print_fr(level, regs)
#define print_symbol(fmt, addr)
#define parisc_show_stack(current, NULL, regs)
#define printk printf

struct pt_regs {
    unsigned long gr[32];
    unsigned long sr[8];
    unsigned long iasq[2];
    unsigned long iaoq[2];
    unsigned long orig_r28;
    unsigned long iir;
    unsigned long isr;
    unsigned long ior;
};

struct thread_info {
    int cpu;
};

extern struct thread_info _current_thread_info;
#define current_thread_info() (&_current_thread_info)

static inline int user_mode(struct pt_regs *regs) { return 0; }
static inline unsigned long mfctl(int cr) { return 0; }