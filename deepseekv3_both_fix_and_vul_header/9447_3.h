#include <stdint.h>
#include <stddef.h>

#define ALIGN(x, a) (((x) + (a) - 1) & ~((a) - 1))

typedef uint32_t u32;
typedef uint64_t u64;

struct task_struct *current;

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
        void *perf_events;
    } *enter_event;
};

struct hlist_head {
    struct hlist_node *first;
};

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct pt_regs;

extern struct syscall_metadata *syscall_nr_to_meta(int nr);
extern long trace_get_syscall_nr(struct task_struct *task, struct pt_regs *regs);
extern unsigned long *enabled_perf_enter_syscalls;
extern int NR_syscalls;
extern void *this_cpu_ptr(void *ptr);
extern int hlist_empty(struct hlist_head *head);
extern void *perf_trace_buf_prepare(int size, int type, struct pt_regs *regs, int *rctx);
extern void syscall_get_arguments(struct task_struct *task, struct pt_regs *regs,
                                unsigned long start, unsigned long count,
                                unsigned long *args);
extern void perf_trace_buf_submit(void *rec, int size, int rctx,
                                unsigned long addr, int count,
                                struct pt_regs *regs, void *head, void *task);
extern int test_bit(int nr, const unsigned long *addr);