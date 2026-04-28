#include <signal.h>
#include <stddef.h>

#define dotraplinkage
#define DIE_TRAP 1
#define NOTIFY_STOP 1

struct pt_regs;
int notify_die(int, const char*, struct pt_regs*, long, int, int);
void preempt_conditional_sti(struct pt_regs*);
void preempt_conditional_cli(struct pt_regs*);
void do_trap(int, int, const char*, struct pt_regs*, long, void*);