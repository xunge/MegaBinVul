#include <stddef.h>

struct pt_regs {
    unsigned long uregs[18];
    unsigned long ARM_pc;
};

struct thread_info {
    unsigned long tp_value[1];
};

static inline struct thread_info *current_thread_info(void)
{
    return NULL;
}