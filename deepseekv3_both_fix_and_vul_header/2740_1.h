#include <stdbool.h>

#define DEBUGCTLMSR_BTF (1 << 0)
#define TIF_BLOCKSTEP 0

struct task_struct {
    // minimal definition
};

extern struct task_struct *current;

void local_irq_disable(void);
void local_irq_enable(void);
unsigned long get_debugctlmsr(void);
void update_debugctlmsr(unsigned long debugctl);
void set_tsk_thread_flag(struct task_struct *task, int flag);
void clear_tsk_thread_flag(struct task_struct *task, int flag);