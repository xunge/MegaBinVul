#include <stddef.h>
#include <stdbool.h>

struct mm_struct {
    unsigned long *cpu_vm_mask;
};

struct task_struct;

#define unlikely(x) (x)
#define smp_processor_id() 0

static inline void cpu_set(int cpu, unsigned long *mask) {
    *mask |= (1UL << cpu);
}

static inline void update_mm(struct mm_struct *mm, struct task_struct *tsk) {}