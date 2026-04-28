#include <stdbool.h>
#include <stddef.h>

typedef unsigned long pmd_t;
typedef unsigned long pud_t;
typedef unsigned long pte_t;

#define MMU_NOTIFY_UNMAP 0
#define NORMAL_PUD 0
#define NORMAL_PMD 0
#define HPAGE_PUD_SIZE (1UL << 30)
#define HPAGE_PMD_SIZE (1UL << 21)
#define PUD_SIZE (1UL << 30)
#define PMD_SIZE (1UL << 21)
#define CONFIG_HAVE_MOVE_PUD 0
#define CONFIG_HAVE_MOVE_PMD 0
#define HPAGE_PUD 1
#define HPAGE_PMD 2

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    struct mm_struct *vm_mm;
};

struct mm_struct;
struct mmu_notifier_range {
    int type;
    int flags;
    struct vm_area_struct *vma;
    struct mm_struct *mm;
    unsigned long start;
    unsigned long end;
};

#define IS_ENABLED(x) (x)

void flush_cache_range(struct vm_area_struct *vma, unsigned long start, unsigned long end);
void mmu_notifier_range_init(struct mmu_notifier_range *range, int type, int flags,
                            struct vm_area_struct *vma, struct mm_struct *mm,
                            unsigned long start, unsigned long end);
void mmu_notifier_invalidate_range_start(struct mmu_notifier_range *range);
void mmu_notifier_invalidate_range_end(struct mmu_notifier_range *range);
unsigned long get_extent(int type, unsigned long old_addr, unsigned long old_end, unsigned long new_addr);
pud_t *get_old_pud(struct mm_struct *mm, unsigned long addr);
pud_t *alloc_new_pud(struct mm_struct *mm, struct vm_area_struct *vma, unsigned long addr);
int move_pgt_entry(int type, struct vm_area_struct *vma, unsigned long old_addr, unsigned long new_addr,
                  void *old_entry, void *new_entry, bool need_rmap_locks);
int pud_trans_huge(pud_t pud);
int pud_devmap(pud_t pud);
pmd_t *get_old_pmd(struct mm_struct *mm, unsigned long addr);
pmd_t *alloc_new_pmd(struct mm_struct *mm, struct vm_area_struct *vma, unsigned long addr);
int is_swap_pmd(pmd_t pmd);
int pmd_trans_huge(pmd_t pmd);
int pmd_devmap(pmd_t pmd);
void split_huge_pmd(struct vm_area_struct *vma, pmd_t *pmd, unsigned long address);
int pmd_trans_unstable(pmd_t *pmd);
int pte_alloc(struct mm_struct *mm, pmd_t *pmd);
void move_ptes(struct vm_area_struct *vma, pmd_t *old_pmd, unsigned long old_addr,
              unsigned long old_end, struct vm_area_struct *new_vma,
              pmd_t *new_pmd, unsigned long new_addr, bool need_rmap_locks);
void cond_resched(void);