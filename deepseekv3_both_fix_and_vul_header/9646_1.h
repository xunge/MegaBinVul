#define OVERCOMMIT_ALWAYS 0
#define OVERCOMMIT_GUESS 1
#define ENOMEM 12

struct mm_struct {
    unsigned long total_vm;
};

extern int sysctl_overcommit_memory;
extern int sysctl_overcommit_ratio;
extern unsigned long totalram_pages;
extern unsigned long hugetlb_total_pages(void);
extern unsigned long total_swap_pages;
extern unsigned long nr_swap_pages;
extern unsigned long totalreserve_pages;

typedef struct {
    long counter;
} atomic_long_t;
extern atomic_long_t vm_committed_space;

extern void vm_acct_memory(long pages);
extern void vm_unacct_memory(long pages);

enum zone_stat_item {
    NR_FILE_PAGES,
    NR_SLAB_RECLAIMABLE
};
extern unsigned long global_page_state(enum zone_stat_item item);
extern unsigned long nr_free_pages(void);

long atomic_long_read(const atomic_long_t *v);