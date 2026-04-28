#include <stdatomic.h>

#define OVERCOMMIT_ALWAYS 0
#define OVERCOMMIT_GUESS 1
#define ENOMEM 12

typedef _Atomic long atomic_long_t;

struct mm_struct {
    unsigned long total_vm;
};

extern int sysctl_overcommit_memory;
extern int sysctl_overcommit_ratio;
extern atomic_long_t vm_committed_space;
extern unsigned long totalram_pages;
extern unsigned long total_swap_pages;
extern unsigned long totalreserve_pages;
extern unsigned long nr_swap_pages;

extern struct task_struct {
    struct mm_struct *mm;
} *current;

unsigned long nr_free_pages(void);
unsigned long global_page_state(int item);
void vm_acct_memory(long pages);
void vm_unacct_memory(long pages);

#define NR_FILE_PAGES 0
#define NR_SLAB_RECLAIMABLE 1

static inline long atomic_long_read(atomic_long_t *v) {
    return atomic_load(v);
}