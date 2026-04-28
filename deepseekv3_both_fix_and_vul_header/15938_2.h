#include <stddef.h>
#include <signal.h>

struct pt_regs;

#define DIE_INT3 1
#define DIE_TRAP 2  
#define NOTIFY_STOP 1
#define CONFIG_KGDB_LOW_LEVEL_TRAP
#define CONFIG_KPROBES
#define __kprobes

int kgdb_ll_trap(int, const char*, struct pt_regs*, long, int, int);
int notify_die(int, const char*, struct pt_regs*, long, int, int);
void preempt_conditional_sti(struct pt_regs*);
void do_trap(int, int, const char*, struct pt_regs*, long, void*); 
void preempt_conditional_cli(struct pt_regs*);