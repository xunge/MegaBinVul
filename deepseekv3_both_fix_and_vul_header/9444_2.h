#include <stddef.h>
#include <stdbool.h>

struct pt_regs {
    unsigned long args[6];
};

struct trace_array {
    struct {
        struct ring_buffer *buffer;
    } trace_buffer;
    struct ftrace_event_file **enter_syscall_files;
};

struct ftrace_event_file {
    bool dummy;
};

struct syscall_trace_enter {
    long nr;
    unsigned long args[];
};

struct syscall_metadata {
    int nb_args;
    struct {
        struct {
            int type;
        } event;
    } *enter_event;
};

struct ring_buffer;
struct ring_buffer_event;

extern struct task_struct {
    int dummy;
} *current;

extern int NR_syscalls;

extern int trace_get_syscall_nr(struct task_struct *task, struct pt_regs *regs);
extern struct syscall_metadata *syscall_nr_to_meta(int syscall_nr);
extern void syscall_get_arguments(struct task_struct *task, struct pt_regs *regs, unsigned long start, unsigned long count, unsigned long *args);
extern void local_save_flags(unsigned long *flags);
extern int preempt_count(void);
extern void event_trigger_unlock_commit(struct ftrace_event_file *file, struct ring_buffer *buffer, struct ring_buffer_event *event, void *entry, unsigned long irq_flags, int pc);
extern bool ftrace_trigger_soft_disabled(struct ftrace_event_file *file);
extern struct ftrace_event_file *rcu_dereference_sched(struct ftrace_event_file *file);
extern struct ring_buffer_event *trace_buffer_lock_reserve(struct ring_buffer *buffer, int type, int size, unsigned long flags, int pc);
extern void *ring_buffer_event_data(struct ring_buffer_event *event);