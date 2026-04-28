#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;
typedef uint64_t u64;

struct pt_regs;
struct task_struct;
struct hlist_head;

struct event {
    unsigned short type;
};

struct exit_event {
    struct event event;
    struct hlist_head *perf_events;
};

struct syscall_metadata {
    struct exit_event *exit_event;
};

struct syscall_trace_exit {
    int nr;
    long ret;
};

extern struct task_struct *current;
extern unsigned long enabled_perf_exit_syscalls[];
extern int NR_syscalls;

extern struct syscall_metadata *syscall_nr_to_meta(int nr);
extern int trace_get_syscall_nr(struct task_struct *task, struct pt_regs *regs);
extern long syscall_get_return_value(struct task_struct *task, struct pt_regs *regs);
extern void *perf_trace_buf_prepare(int size, unsigned short type, struct pt_regs *regs, int *rctx);
extern void perf_trace_buf_submit(void *raw_data, int size, int rctx, int arg1, int arg2, struct pt_regs *regs, struct hlist_head *head, void *arg3);
extern void *this_cpu_ptr(void *ptr);
extern int hlist_empty(struct hlist_head *head);

#define ALIGN(x, a) (((x) + (a) - 1) & ~((a) - 1))
static inline int test_bit(int nr, const unsigned long *addr) {
    return (addr[nr / (8 * sizeof(long))] >> (nr % (8 * sizeof(long)))) & 1;
}