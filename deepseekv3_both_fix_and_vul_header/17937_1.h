#include <stdatomic.h>
#include <stdlib.h>

struct task_struct {
    struct thread_info *stack;
    atomic_int usage;
    atomic_int fs_excl;
    int btrace_seq;
    void *splice_pipe;
    unsigned long stack_canary;
    int dirties;
};

struct thread_info;

#define STACK_END_MAGIC 0x57AC6E9D
#define CONFIG_CC_STACKPROTECTOR
#define CONFIG_BLK_DEV_IO_TRACE

extern void prepare_to_copy(struct task_struct *);
extern struct task_struct *alloc_task_struct(void);
extern void free_task_struct(struct task_struct *);
extern struct thread_info *alloc_thread_info(struct task_struct *);
extern void free_thread_info(struct thread_info *);
extern int arch_dup_task_struct(struct task_struct *, struct task_struct *);
extern void setup_thread_stack(struct task_struct *, struct task_struct *);
extern void clear_user_return_notifier(struct task_struct *);
extern unsigned long *end_of_stack(struct task_struct *);
extern void account_kernel_stack(struct thread_info *, int);
extern int prop_local_init_single(int *);
extern unsigned int get_random_int(void);