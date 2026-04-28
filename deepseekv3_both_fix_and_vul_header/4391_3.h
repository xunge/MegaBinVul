#define CONFIG_PGSTE
#define _ASCE_TABLE_LENGTH 0
#define _ASCE_USER_BITS 0
#define _ASCE_TYPE_REGION3 0
#define STACK_TOP_MAX 0

struct task_struct;
struct list_head {
    struct list_head *next, *prev;
};
struct cpumask {
    unsigned long bits[1];
};
typedef struct {
    int lock;
} spinlock_t;

struct mm_struct {
    struct {
        spinlock_t list_lock;
        struct list_head pgtable_list;
        struct list_head gmap_list;
        struct cpumask cpu_attach_mask;
        int attach_count;
        int flush_mm;
#ifdef CONFIG_PGSTE
        int alloc_pgste;
        int has_pgste;
        int use_skey;
#endif
        unsigned long asce_limit;
        unsigned long asce_bits;
    } context;
    void *pgd;
};

static inline void spin_lock_init(spinlock_t *lock) { lock->lock = 0; }
static inline void INIT_LIST_HEAD(struct list_head *list) { list->next = list->prev = list; }
static inline void cpumask_clear(struct cpumask *mask) { mask->bits[0] = 0; }
static inline void atomic_set(int *v, int i) { *v = i; }
static inline void mm_inc_nr_pmds(struct mm_struct *mm) {}
static inline void crst_table_init(unsigned long *pgd, int type) {}
static inline int pgd_entry_type(struct mm_struct *mm) { return 0; }
static inline int page_table_allocate_pgste = 0;