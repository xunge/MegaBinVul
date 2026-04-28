#include <stddef.h>

typedef struct {
    unsigned long pmd;
} pmd_t;

typedef struct {
    unsigned long pte;
} pte_t;

typedef struct {
    int lock;
} spinlock_t;

struct mm_walk {
    struct mm_struct *mm;
    void *private;
};

struct mem_size_stats {
    struct vm_area_struct *vma;
    unsigned long anonymous_thp;
};

struct vm_area_struct {
    struct mm_struct *vm_mm;
    struct anon_vma *anon_vma;
    spinlock_t *ptl;
};

struct mm_struct {
    spinlock_t page_table_lock;
};

struct anon_vma {
};

#define HPAGE_PMD_SIZE (1UL << 21)
#define PAGE_SIZE 4096

static inline void spin_lock(spinlock_t *lock) { (void)lock; }
static inline void spin_unlock(spinlock_t *lock) { (void)lock; }
static inline int pmd_trans_huge(pmd_t pmd) { (void)pmd; return 0; }
static inline int pmd_trans_splitting(pmd_t pmd) { (void)pmd; return 0; }
static inline void wait_split_huge_page(struct anon_vma *anon_vma, pmd_t *pmd) { (void)anon_vma; (void)pmd; }
static inline pte_t *pte_offset_map_lock(struct mm_struct *mm, pmd_t *pmd, unsigned long addr, spinlock_t **ptl) { (void)mm; (void)pmd; (void)addr; (void)ptl; return NULL; }
static inline void pte_unmap_unlock(pte_t *pte, spinlock_t *ptl) { (void)pte; (void)ptl; }
static inline void cond_resched(void) {}
static inline void smaps_pte_entry(pte_t pte, unsigned long addr, unsigned long size, struct mm_walk *walk) { (void)pte; (void)addr; (void)size; (void)walk; }