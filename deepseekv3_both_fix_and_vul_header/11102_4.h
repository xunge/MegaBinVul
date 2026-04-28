#include <stdint.h>
#include <stdio.h>

#define TRAP_debug 1
#define X86_DR6_DEFAULT 0xffff0ff0
#define X86_EFLAGS_TF 0x00000100
#define DR_TRAP0 (1 << 0)
#define DR_TRAP1 (1 << 1)
#define DR_TRAP2 (1 << 2)
#define DR_TRAP3 (1 << 3)
#define DR_GENERAL_DETECT (1 << 13)
#define DR_ENABLE_SIZE 2
#define DR_CONTROL_SIZE 2
#define DR_CONTROL_SHIFT 16
#define DR_RW_EXECUTE 0
#define X86_EVENT_NO_EC 0
#define XENLOG_ERR "XENLOG_ERR: "
#define XENLOG_WARNING "XENLOG_WARNING: "

struct cpu_user_regs {
    unsigned long rip;
    unsigned long rsp;
    uint16_t cs;
    uint16_t ss;
    unsigned long eflags;
};

struct vcpu {
    struct {
        unsigned long debugreg[8];
    } arch;
};

extern struct vcpu *current;
extern unsigned long read_debugreg(int reg);
extern void write_debugreg(int reg, unsigned long val);
extern int debugger_trap_entry(int trap, struct cpu_user_regs *regs);
extern int debugger_trap_fatal(int trap, struct cpu_user_regs *regs);
extern int guest_mode(struct cpu_user_regs *regs);
extern void WARN(void);
extern void ASSERT_UNREACHABLE(void);
extern int printk(const char *fmt, ...);
extern int gprintk(const char *fmt, ...);
extern void fatal_trap(struct cpu_user_regs *regs, int error_code);
extern void ler_enable(void);
extern void pv_inject_hw_exception(int trap, int error_code);
extern void *sysenter_entry;
extern void *sysenter_eflags_saved;
extern void *_p(unsigned long addr);