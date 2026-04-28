#include <stddef.h>

struct vm_area_struct {
    struct mm_struct *vm_mm;
};

struct mm_struct {
    unsigned long dummy;
};

struct task_struct {
    struct mm_struct *active_mm;
    struct mm_struct *mm;
};

extern struct task_struct *current;
extern int smp_processor_id(void);
extern int nr_cpu_ids;
extern void __flush_tlb_one(unsigned long);
extern void leave_mm(int cpu);
extern int cpumask_any_but(const void *mask, int cpu);
extern void *mm_cpumask(struct mm_struct *mm);
extern void flush_tlb_others(const void *cpumask, struct mm_struct *mm, unsigned long start, unsigned long end);

static inline void preempt_disable(void) {}
static inline void preempt_enable(void) {}