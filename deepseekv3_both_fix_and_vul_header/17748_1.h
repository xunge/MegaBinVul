#include <stdbool.h>

struct vm_area_struct {
    void *vm_mm;
};

struct mmu_notifier_range {
    int dummy;
};

typedef struct {
    int dummy;
} pmd_t;

#define PMD_SIZE 0
#define PMD_MASK 0
#define HPAGE_PMD_SIZE 0
#define MMU_NOTIFY_UNMAP 0

void flush_cache_range(struct vm_area_struct *vma, unsigned long start, unsigned long end);
void mmu_notifier_range_init(struct mmu_notifier_range *range, int type, int flags,
                            struct vm_area_struct *vma, void *mm,
                            unsigned long start, unsigned long end);
void mmu_notifier_invalidate_range_start(struct mmu_notifier_range *range);
void mmu_notifier_invalidate_range_end(struct mmu_notifier_range *range);
void cond_resched();
pmd_t *get_old_pmd(void *mm, unsigned long addr);
pmd_t *alloc_new_pmd(void *mm, struct vm_area_struct *vma, unsigned long addr);
bool is_swap_pmd(pmd_t pmd);
bool pmd_trans_huge(pmd_t pmd);
void take_rmap_locks(struct vm_area_struct *vma);
void drop_rmap_locks(struct vm_area_struct *vma);
bool move_huge_pmd(struct vm_area_struct *vma, unsigned long old_addr,
                  unsigned long new_addr, unsigned long old_end,
                  pmd_t *old_pmd, pmd_t *new_pmd);
void split_huge_pmd(struct vm_area_struct *vma, pmd_t *pmd, unsigned long addr);
bool pmd_trans_unstable(pmd_t *pmd);
bool move_normal_pmd(struct vm_area_struct *vma, unsigned long old_addr,
                    unsigned long new_addr, unsigned long old_end,
                    pmd_t *old_pmd, pmd_t *new_pmd);
bool pte_alloc(void *mm, pmd_t *pmd);
void move_ptes(struct vm_area_struct *vma, pmd_t *old_pmd,
              unsigned long old_addr, unsigned long old_end,
              struct vm_area_struct *new_vma, pmd_t *new_pmd,
              unsigned long new_addr, bool need_rmap_locks);