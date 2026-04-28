#include <stddef.h>

struct mm_struct;
struct task_struct {
    struct mm_struct *mm;
};
extern struct task_struct *current;

#define preempt_disable()
#define preempt_enable()
#define NR_TLB_LOCAL_FLUSH_ALL 0
#define TLB_LOCAL_SHOOTDOWN 0
#define TLB_FLUSH_ALL 0

void count_vm_tlb_event(int event);
void local_flush_tlb(void);
void trace_tlb_flush(int reason, int scope);
int cpumask_any_but(const void *mask, int cpu);
void *mm_cpumask(struct mm_struct *mm);
int smp_processor_id(void);
extern int nr_cpu_ids;
void flush_tlb_others(const void *cpumask, struct mm_struct *mm, unsigned long va, unsigned int flush_type);