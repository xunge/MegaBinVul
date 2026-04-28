#include <stddef.h>

struct ring_buffer {
    void *buffer;
};

struct trace_buffer {
    struct ring_buffer *buffer; 
};

struct trace_array {
    int stop_count;
    int allocated_snapshot;
    struct tracer *current_trace;
    struct trace_buffer trace_buffer;
    struct trace_buffer max_buffer;
    void *max_lock;
};

struct task_struct;
struct tracer;

extern int irqs_disabled(void);
extern void arch_spin_lock(void *);
extern void arch_spin_unlock(void *); 
extern void WARN_ON_ONCE(int);
extern struct tracer nop_trace;
extern void __update_max_tr(struct trace_array *tr, struct task_struct *tsk, int cpu);