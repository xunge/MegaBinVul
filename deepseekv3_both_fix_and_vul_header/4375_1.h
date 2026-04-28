#include <stdbool.h>

struct mm_struct {
    unsigned long pgd;
    struct {
        void *ldt;
    } context;
};

struct task_struct;

#define CONFIG_SMP
#define CONFIG_MODIFY_LDT_SYSCALL
#define likely(x)       __builtin_expect(!!(x), 1)
#define unlikely(x)     __builtin_expect(!!(x), 0)
#define BUG() while(1)
#define BUG_ON(condition) do { if (unlikely(condition)) BUG(); } while (0)

#define TLBSTATE_OK 1
#define TLB_FLUSH_ON_TASK_SWITCH 0
#define TLB_FLUSH_ALL 0

struct cpu_tlbstate {
    int state;
    struct mm_struct *active_mm;
};

extern struct cpu_tlbstate cpu_tlbstate;

typedef struct {
    unsigned long bits[1];
} cpumask_t;

#define cpumask_set_cpu(cpu, mask) ((void)0)
#define cpumask_clear_cpu(cpu, mask) ((void)0)
#define cpumask_test_cpu(cpu, mask) (false)

static inline unsigned smp_processor_id(void) { return 0; }
static inline void this_cpu_write(int var, int val) {}
static inline int this_cpu_read(int var) { return 0; }
static inline void load_cr3(unsigned long pgd) {}
static inline void load_mm_cr4(struct mm_struct *mm) {}
static inline void load_mm_ldt(struct mm_struct *mm) {}
static inline void trace_tlb_flush(int reason, int scope) {}

static inline cpumask_t *mm_cpumask(struct mm_struct *mm) { 
    static cpumask_t mask;
    return &mask; 
}