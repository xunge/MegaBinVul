#include <stddef.h>

struct pt_regs;
struct task_struct;

struct trace_array {
    struct {
        struct ring_buffer *buffer;
    } trace_buffer;
    struct ftrace_event_file **exit_syscall_files;
};

struct ftrace_event_file;
struct syscall_trace_exit {
    int nr;
    long ret;
};
struct syscall_metadata {
    struct {
        struct {
            int type;
        } event;
    } *exit_event;
};
struct ring_buffer;
struct ring_buffer_event;

extern struct task_struct *current;
extern int NR_syscalls;

int trace_get_syscall_nr(struct task_struct *task, struct pt_regs *regs);
struct syscall_metadata *syscall_nr_to_meta(int syscall_nr);
long syscall_get_return_value(struct task_struct *task, struct pt_regs *regs);
struct ftrace_event_file *rcu_dereference_sched(void *p);
int ftrace_trigger_soft_disabled(struct ftrace_event_file *file);
void local_save_flags(unsigned long flags);
int preempt_count(void);
struct ring_buffer_event *trace_buffer_lock_reserve(struct ring_buffer *buffer,
                                                  int type, size_t len,
                                                  unsigned long flags, int pc);
void *ring_buffer_event_data(struct ring_buffer_event *event);
void event_trigger_unlock_commit(struct ftrace_event_file *file,
                                struct ring_buffer *buffer,
                                struct ring_buffer_event *event,
                                void *entry, unsigned long flags, int pc);