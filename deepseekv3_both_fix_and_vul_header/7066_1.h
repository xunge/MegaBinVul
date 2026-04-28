#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#define NUMA_NO_NODE (-1)
#define __maybe_unused
#define CONFIG_VMAP_STACK
#define CONFIG_THREAD_INFO_IN_TASK
#define CONFIG_SECCOMP
#define CONFIG_STACKPROTECTOR
#define CONFIG_BLK_DEV_IO_TRACE
#define CONFIG_FAULT_INJECTION
#define CONFIG_BLK_CGROUP
#define CONFIG_MEMCG

typedef struct {
    int counter;
} refcount_t;

struct seccomp_filter;
struct pipe_inode_info;
struct wake_q_node;
struct request_queue;
struct mem_cgroup;
struct page;
struct vm_struct;
struct io_worker;

struct task_struct {
    unsigned long *stack;
#ifdef CONFIG_VMAP_STACK
    void *stack_vm_area;
#endif
#ifdef CONFIG_THREAD_INFO_IN_TASK
    refcount_t stack_refcount;
#endif
#ifdef CONFIG_SECCOMP
    struct {
        struct seccomp_filter *filter;
    } seccomp;
#endif
#ifdef CONFIG_STACKPROTECTOR
    unsigned long stack_canary;
#endif
    unsigned long cpus_mask;
    unsigned long *cpus_ptr;
    refcount_t rcu_users;
    refcount_t usage;
#ifdef CONFIG_BLK_DEV_IO_TRACE
    unsigned int btrace_seq;
#endif
    struct pipe_inode_info *splice_pipe;
    struct {
        struct page *page;
    } task_frag;
    struct {
        struct wake_q_node *next;
    } wake_q;
    struct io_worker *pf_io_worker;
#ifdef CONFIG_FAULT_INJECTION
    unsigned int fail_nth;
#endif
#ifdef CONFIG_BLK_CGROUP
    struct request_queue *throttle_queue;
    unsigned int use_memdelay;
#endif
#ifdef CONFIG_MEMCG
    struct mem_cgroup *active_memcg;
#endif
};

static inline int tsk_fork_get_node(struct task_struct *tsk) { return 0; }
static inline struct task_struct *alloc_task_struct_node(int node) { return malloc(sizeof(struct task_struct)); }
static inline unsigned long *alloc_thread_stack_node(struct task_struct *tsk, int node) { return malloc(4096); }
static inline int memcg_charge_kernel_stack(struct task_struct *tsk) { return 0; }
static inline void *task_stack_vm_area(struct task_struct *tsk) { return NULL; }
static inline int arch_dup_task_struct(struct task_struct *dst, struct task_struct *src) { return 0; }
static inline int scs_prepare(struct task_struct *tsk, int node) { return 0; }
static inline void setup_thread_stack(struct task_struct *tsk, struct task_struct *orig) {}
static inline void clear_user_return_notifier(struct task_struct *tsk) {}
static inline void clear_tsk_need_resched(struct task_struct *tsk) {}
static inline void set_task_stack_end_magic(struct task_struct *tsk) {}
static inline unsigned long get_random_canary(void) { return 0; }
static inline void account_kernel_stack(struct task_struct *tsk, int account) {}
static inline void kcov_task_init(struct task_struct *tsk) {}
static inline void free_thread_stack(struct task_struct *tsk) { free(tsk->stack); }
static inline void free_task_struct(struct task_struct *tsk) { free(tsk); }

static inline void refcount_set(refcount_t *r, int value) {
    r->counter = value;
}