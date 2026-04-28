#include <stddef.h>

struct pt_regs {
    unsigned long regs[18];  // 假设pt_regs包含18个寄存器
};

struct task_struct {
    struct {
        struct pt_regs *kregs;
        struct pt_regs *uregs;
    } thread;
};

extern struct task_struct *current;
extern struct task_struct *last_task_used_math;
extern struct pt_regs fake_swapper_regs;

#define THREAD_SIZE 8192
#define CONFIG_SH_FPU 1

void clear_used_math(void);