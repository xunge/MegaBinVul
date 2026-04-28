#include <stddef.h>

typedef unsigned long pmd_t;
typedef unsigned long pte_t;
typedef unsigned long spinlock_t;

#define PAGE_SIZE 4096

struct mm_walk {
    void *mm;
    void *private;
};

struct vm_area_struct {
    void *vm_mm;
};

struct page {
    unsigned long flags;
};

#define pte_present(x) (1)
#define PageReserved(x) (0)
#define ClearPageReferenced(x) ((x)->flags &= ~(1UL))
#define cond_resched() do {} while (0)

static inline void split_huge_page_pmd(void *mm, pmd_t *pmd) {}
static inline pte_t *pte_offset_map_lock(void *mm, pmd_t *pmd, unsigned long addr, spinlock_t **ptl) { return NULL; }
static inline void pte_unmap_unlock(pte_t *pte, spinlock_t *ptl) {}
static inline struct page *vm_normal_page(struct vm_area_struct *vma, unsigned long addr, pte_t ptent) { return NULL; }
static inline int ptep_test_and_clear_young(struct vm_area_struct *vma, unsigned long addr, pte_t *pte) { return 0; }