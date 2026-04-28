#define TLB_FLUSH_ALL (~0UL)
#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)
#define VM_HUGETLB 0x00400000

struct mm_struct;
struct task_struct {
    struct mm_struct *mm;
    struct mm_struct *active_mm;
};

extern struct task_struct *current;
extern void preempt_disable(void);
extern void preempt_enable(void);
extern void leave_mm(int cpu);
extern int smp_processor_id(void);
extern void local_flush_tlb(void);
extern void __flush_tlb_single(unsigned long addr);
extern void flush_tlb_others(const void *cpumask, struct mm_struct *mm, unsigned long start, unsigned long end);
extern int cpumask_any_but(const void *srcp, int cpu);
extern const void *mm_cpumask(struct mm_struct *mm);
extern int nr_cpu_ids;
extern unsigned long tlb_single_page_flush_ceiling;

enum {
    NR_TLB_LOCAL_FLUSH_ALL,
    NR_TLB_LOCAL_FLUSH_ONE
};

enum tlb_flush_reason {
    TLB_LOCAL_MM_SHOOTDOWN
};

void trace_tlb_flush(enum tlb_flush_reason reason, unsigned long pages);
void count_vm_tlb_event(int item);