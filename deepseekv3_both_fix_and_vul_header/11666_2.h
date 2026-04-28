#include <stdbool.h>

#define PMD_SIZE 4096
#define PMD_MASK (~(PMD_SIZE - 1))
#define HPAGE_PMD_SIZE (PMD_SIZE * 512)

struct vm_area_struct {
    struct mm_struct *vm_mm;
};

struct mm_struct;

typedef struct {
    unsigned long pmd;
} pmd_t;

void flush_cache_range(struct vm_area_struct *vma, unsigned long start, unsigned long end);
void mmu_notifier_invalidate_range_start(struct mm_struct *mm, unsigned long start, unsigned long end);
void mmu_notifier_invalidate_range_end(struct mm_struct *mm, unsigned long start, unsigned long end);
void cond_resched(void);
pmd_t *get_old_pmd(struct mm_struct *mm, unsigned long addr);
pmd_t *alloc_new_pmd(struct mm_struct *mm, struct vm_area_struct *vma, unsigned long addr);
bool is_swap_pmd(pmd_t pmd);
bool pmd_trans_huge(pmd_t pmd);
void take_rmap_locks(struct vm_area_struct *vma);
void drop_rmap_locks(struct vm_area_struct *vma);
bool move_huge_pmd(struct vm_area_struct *vma, unsigned long old_addr, unsigned long new_addr, unsigned long old_end, pmd_t *old_pmd, pmd_t *new_pmd, ...);
void split_huge_pmd(struct vm_area_struct *vma, pmd_t *pmd, unsigned long addr);
bool pmd_trans_unstable(pmd_t *pmd);
bool pte_alloc(struct mm_struct *mm, pmd_t *pmd, unsigned long addr);
void move_ptes(struct vm_area_struct *vma, pmd_t *old_pmd, unsigned long old_addr, unsigned long old_end, struct vm_area_struct *new_vma, pmd_t *new_pmd, unsigned long new_addr, bool need_rmap_locks, ...);
void flush_tlb_range(struct vm_area_struct *vma, unsigned long start, unsigned long end);