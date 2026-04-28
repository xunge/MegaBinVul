#include <stdatomic.h>
#include <stddef.h>

struct pt_regs;
#define CONFIG_DYNAMIC_FFTCE
#define CONFIG_KGDB_LOW_LEVEL_TRAP
#define CONFIG_KPROBES
#define X86_TRAP_BP 3
#define SIGTRAP 5
#define NOTIFY_STOP 0x8000
#define DIE_INT3 1

extern atomic_int modifying_ftrace_code;
extern int ftrace_int3_handler(struct pt_regs *regs);
extern int poke_int3_handler(struct pt_regs *regs);
extern void ist_enter(struct pt_regs *regs);
extern void ist_exit(struct pt_regs *regs);
extern int rcu_is_watching(void);
extern int kgdb_ll_trap(int type, const char *str, struct pt_regs *regs, long err, int trap, int sig);
extern int kprobe_int3_handler(struct pt_regs *regs);
extern int notify_die(int val, const char *str, struct pt_regs *regs, long err, int trap, int sig);
extern void debug_stack_usage_inc(void);
extern void debug_stack_usage_dec(void);
extern void cond_local_irq_enable(struct pt_regs *regs);
extern void cond_local_irq_disable(struct pt_regs *regs);
extern void do_trap(int trapnr, int signr, char *str, struct pt_regs *regs, long error_code, void *addr);

#define atomic_read(v) atomic_load(v)
#define RCU_LOCKDEP_WARN(cond, msg) ((void)(cond))
#define unlikely(x) (x)
#define notrace __attribute__((no_instrument_function))