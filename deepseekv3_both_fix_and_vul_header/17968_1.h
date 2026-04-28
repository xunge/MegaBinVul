#include <stddef.h>

typedef struct spinlock {
    int dummy;
} spinlock_t;

typedef struct {
    unsigned long val;
} pmd_t;

typedef struct {
    unsigned long val;
} pte_t;

typedef struct mm_struct {
    spinlock_t page_table_lock;
} mm_struct;

typedef struct vm_area_struct {
    void *anon_vma;
} vm_area_struct;

typedef struct page {
    int dummy;
} page;

struct numa_maps {
    struct vm_area_struct *vma;
};

struct mm_walk {
    struct mm_struct *mm;
    void *private;
};

#define pmd_trans_huge(pmd) (0)
#define pmd_trans_splitting(pmd) (0)
#define HPAGE_PMD_SIZE (0)
#define PAGE_SIZE (4096)

static inline void spin_lock(spinlock_t *lock) {}
static inline void spin_unlock(spinlock_t *lock) {}
static inline void wait_split_huge_page(void *anon_vma, pmd_t *pmd) {}
static inline struct page *can_gather_numa_stats(pte_t pte, struct vm_area_struct *vma, unsigned long addr) { return NULL; }
static inline void gather_stats(struct page *page, struct numa_maps *md, int dirty, int size) {}
static inline pte_t *pte_offset_map_lock(struct mm_struct *mm, pmd_t *pmd, unsigned long addr, spinlock_t **ptl) { return NULL; }
static inline void pte_unmap_unlock(pte_t *pte, spinlock_t *ptl) {}
static inline int pte_dirty(pte_t pte) { return 0; }