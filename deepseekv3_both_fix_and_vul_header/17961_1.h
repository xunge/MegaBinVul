#include <stddef.h>

struct mm_walk {
    void *private;
    void *mm;
};

struct vm_area_struct {
    void *vm_mm;
};

typedef struct { } pmd_t;
typedef struct { } pte_t;
typedef struct { } spinlock_t;

struct {
    int precharge;
} mc;

#define PAGE_SIZE 4096

static inline void split_huge_page_pmd(void *mm, pmd_t *pmd) {}
static inline pte_t *pte_offset_map_lock(void *mm, pmd_t *pmd, unsigned long addr, spinlock_t **ptl) { return NULL; }
static inline void pte_unmap_unlock(pte_t *pte, spinlock_t *ptl) {}
static inline void cond_resched(void) {}
static inline int is_target_pte_for_mc(struct vm_area_struct *vma, unsigned long addr, pte_t pte, void *arg) { return 0; }