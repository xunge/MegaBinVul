#include <stdatomic.h>
#include <stddef.h>
#include <string.h>

struct list_head {
    struct list_head *next, *prev;
};

struct rb_root {
    void *rb_node;
};

struct mm_struct {
    void *mmap;
    struct rb_root mm_rb;
    unsigned int vmacache_seqnum;
    atomic_int mm_users;
    atomic_int mm_count;
    void *mmap_sem;
    struct list_head mmlist;
    void *core_state;
    atomic_long nr_ptes;
    int map_count;
    unsigned long locked_vm;
    unsigned long pinned_vm;
    int rss_stat;
    void *page_table_lock;
    unsigned long flags;
    unsigned long def_flags;
    void *exe_file;
    void *pmd_huge_pte;
    void *user_ns;
};

struct task_struct {
    struct mm_struct *mm;
};

struct user_namespace;

#define RB_ROOT (struct rb_root){ NULL }
#define INIT_LIST_HEAD(ptr) do { (ptr)->next = (ptr); (ptr)->prev = (ptr); } while (0)
#define MMF_INIT_MASK 0
#define VM_INIT_DEF_MASK 0
#define CONFIG_TRANSPARENT_HUGEPAGE 0
#define USE_SPLIT_PMD_PTLOCKS 0

static unsigned int default_dump_filter;
static struct task_struct *current;

static inline void atomic_set(atomic_int *v, int i) { *v = i; }
static inline void atomic_long_set(atomic_long *v, long i) { *v = i; }
static inline void spin_lock_init(void *lock) {}
static inline void init_rwsem(void *sem) {}
static inline void RCU_INIT_POINTER(void **p, void *v) { *p = v; }
static inline void mmu_notifier_mm_init(struct mm_struct *mm) {}
static inline void init_tlb_flush_pending(struct mm_struct *mm) {}
static inline void mm_init_cpumask(struct mm_struct *mm) {}
static inline void mm_init_aio(struct mm_struct *mm) {}
static inline void mm_init_owner(struct mm_struct *mm, struct task_struct *p) {}
static inline int mm_alloc_pgd(struct mm_struct *mm) { return 0; }
static inline int init_new_context(struct task_struct *p, struct mm_struct *mm) { return 0; }
static inline void mm_free_pgd(struct mm_struct *mm) {}
static inline void free_mm(struct mm_struct *mm) {}
static inline void mm_nr_pmds_init(struct mm_struct *mm) {}
static inline struct user_namespace *get_user_ns(struct user_namespace *ns) { return ns; }