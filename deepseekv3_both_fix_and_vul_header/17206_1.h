#include <stddef.h>
#include <stdint.h>

#define X86_DR6_DEFAULT 0xFFFF0FF0
#define X86_EFLAGS_TF 0x00000100
#define TRAP_debug 1
#define X86_EVENT_NO_EC 0

struct cpu_user_regs {
    unsigned long rip;
    unsigned long eflags;
};

struct vcpu {
    struct {
        unsigned long debugreg[8];
    } arch;
};

struct vcpu *current;

unsigned long read_debugreg(int reg);
void write_debugreg(int reg, unsigned long value);
int debugger_trap_entry(int trap, struct cpu_user_regs *regs);
int debugger_trap_fatal(int trap, struct cpu_user_regs *regs);
int guest_mode(struct cpu_user_regs *regs);
void WARN(void);
int WARN_ON(int condition);
int search_exception_table(struct cpu_user_regs *regs);
void ler_enable(void);
void pv_inject_hw_exception(int trap, int error_code);

extern unsigned long sysenter_entry;
extern unsigned long sysenter_eflags_saved;