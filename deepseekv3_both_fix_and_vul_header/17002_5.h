#include <stdint.h>
#include <limits.h>
#include <stddef.h>

typedef uint8_t u8;
typedef uint32_t u32;

#define IS_ENABLED(x) 0
#define CONFIG_HAVE_EFFICIENT_UNALIGNED_ACCESS 0
#define CONFIG_UBSAN_BOUNDS 0
#define CONFIG_DEBUG_LIST 0
#define CONFIG_X86_64 0
#define CONFIG_UML 0
#define CONFIG_X86_32 0
#define CONFIG_ARM64 0
#define CONFIG_ARM64_PTR_AUTH_KERNEL 0

#define pr_err(fmt, ...) 
#define pr_info(fmt, ...) 
#define pr_expected_config(x) 

#define TASK_UNINTERRUPTIBLE 0
#define GFP_KERNEL 0
#define THREAD_SIZE 4096

#define X86_CR4_SMEP 0

struct list_head {
    struct list_head *next, *prev;
};

struct lkdtm_list {
    struct list_head node;
};

typedef struct {
    int lock;
} spinlock_t;

struct task_struct {
    // dummy definition
};

static spinlock_t lock_me_up;

static inline void preempt_disable(void) {}
static inline void cpu_relax(void) {}
static inline void local_irq_disable(void) {}
static inline void set_current_state(int state) {}
static inline void schedule(void) {}

static inline void spin_lock(spinlock_t *lock) {}
static inline void __release(void *lock) {}

static inline unsigned long native_read_cr4(void) { return 0; }
static inline void native_write_cr4(unsigned long val) {}

#define LIST_HEAD_INIT(name) { &(name), &(name) }
#define LIST_HEAD(name) struct list_head name = LIST_HEAD_INIT(name)

static inline void list_add(struct list_head *new, struct list_head *head) {}
static inline void list_del(struct list_head *entry) {}

static inline void *kmalloc(size_t size, int flags) { return NULL; }
static inline void kfree(void *ptr) {}

static struct task_struct dummy_task;
#define current (&dummy_task)
#define task_stack_page(task) ((void *)0)

#define GDT_ENTRY_TLS_MIN 0
#define DESCTYPE_S 0

static inline void write_gdt_entry(void *gdt, int entry, void *desc, int type) {}
static inline void *get_cpu_gdt_rw(int cpu) { return NULL; }
#define smp_processor_id() 0

#ifdef CONFIG_ARM64
#define noinline __attribute__((noinline))

static inline void ptrauth_thread_init_kernel(struct task_struct *tsk) {}
static inline void ptrauth_thread_switch_kernel(struct task_struct *tsk) {}
static inline int system_supports_address_auth(void) { return 0; }
#endif