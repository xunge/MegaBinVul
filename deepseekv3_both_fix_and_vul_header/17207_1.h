#include <stddef.h>
#include <stdint.h>

#define X86_DR6_DEFAULT 0xffff0ff0
#define DR_GENERAL_DETECT 0x2000
#define DR_TRAP0 0x1
#define DR_TRAP1 0x2
#define DR_TRAP2 0x4
#define DR_TRAP3 0x8
#define DR_CONTROL_SHIFT 16
#define DR_CONTROL_SIZE 2

#define X86_EFLAGS_TF 0x100
#define TRAP_debug 1
#define X86_EVENT_NO_EC 0
#define XENLOG_ERR ""
#define XENLOG_WARNING ""

struct cpu_user_regs {
    unsigned long rip;
    unsigned long rsp;
    unsigned long eflags;
    unsigned short cs;
    unsigned short ss;
};

struct vcpu {
    struct {
        unsigned long debugreg[8];
    } arch;
};

struct vcpu *current;

unsigned long read_debugreg(int reg);
void write_debugreg(int reg, unsigned long val);
int debugger_trap_entry(int trap, struct cpu_user_regs *regs);
int debugger_trap_fatal(int trap, struct cpu_user_regs *regs);
int guest_mode(struct cpu_user_regs *regs);
void fatal_trap(struct cpu_user_regs *regs, int error_code);
void printk(const char *fmt, ...);
void gprintk(const char *fmt, ...);
void WARN(void);
void ler_enable(void);
void pv_inject_hw_exception(int trap, int error_code);
void *sysenter_entry;
void *sysenter_eflags_saved;
void *_p(void *ptr);