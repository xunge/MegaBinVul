#include <stddef.h>
#include <stdint.h>

#define es SEG_ES
#define ds SEG_DS
#define fs SEG_FS
#define gs SEG_GS

enum {
    SEG_ES = 0,
    SEG_DS = 1,
    SEG_FS = 2,
    SEG_GS = 3
};

#define unlikely(x) (x)

struct thread_struct {
    unsigned es;
    unsigned ds;
    unsigned fsindex;
    unsigned gsindex;
    unsigned fs;
    unsigned gs;
    unsigned long usersp;
};

struct task_struct {
    struct thread_struct thread;
};

struct tss_struct {};
struct thread_info {
    unsigned long saved_preempt_count;
    unsigned long flags;
};

typedef struct {} fpu_switch_t;

extern int smp_processor_id(void);
extern struct tss_struct init_tss;
extern unsigned long old_rsp;
extern unsigned long __preempt_count;
extern unsigned long kernel_stack;
extern struct task_struct *current_task;

#define per_cpu(var, cpu) (var)
#define THREAD_SIZE 8192
#define KERNEL_STACK_OFFSET 0
#define MSR_FS_BASE 0xC0000100
#define MSR_KERNEL_GS_BASE 0xC0000101
#define _TIF_WORK_CTXSW_NEXT (1 << 0)
#define _TIF_WORK_CTXSW_PREV (1 << 1)

static inline void load_sp0(struct tss_struct *tss, struct thread_struct *next) {}
static inline void savesegment(int seg, unsigned value) {}
static inline void loadsegment(int seg, unsigned value) {}
static inline void load_TLS(struct thread_struct *next, int cpu) {}
static inline void arch_end_context_switch(struct task_struct *next_p) {}
static inline void load_gs_index(unsigned value) {}
static inline void wrmsrl(unsigned msr, unsigned long value) {}
static inline fpu_switch_t switch_fpu_prepare(struct task_struct *prev_p, struct task_struct *next_p, int cpu) { return (fpu_switch_t){}; }
static inline void switch_fpu_finish(struct task_struct *next_p, fpu_switch_t fpu) {}
static inline void __switch_to_xtra(struct task_struct *prev_p, struct task_struct *next_p, struct tss_struct *tss) {}

#define this_cpu_read(var) (var)
#define this_cpu_write(var, value) ((var) = (value))

static inline struct thread_info *task_thread_info(struct task_struct *task) { return NULL; }
static inline void *task_stack_page(struct task_struct *task) { return NULL; }