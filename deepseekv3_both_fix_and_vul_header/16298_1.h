#include <stdbool.h>
#include <stddef.h>

typedef struct spinlock {
    int dummy;
} spinlock_t;

struct vm_area_struct {
    struct mm_struct *vm_mm;
};

struct mm_struct;

struct page;

struct mmu_notifier_range {
    unsigned long start;
    unsigned long end;
};

typedef struct {
    unsigned long pmd;
} pmd_t;

#define HPAGE_PMD_MASK (~(HPAGE_PMD_SIZE - 1))
#define HPAGE_PMD_SIZE (1UL << 21)  // Assuming PMD_SHIFT is 21
#define MMU_NOTIFY_CLEAR 0

#define VM_BUG_ON(cond) ((void)0)
#define PageMlocked(page) (false)
#define pmd_trans_huge(pmd) (false)
#define pmd_devmap(pmd) (false)
#define is_pmd_migration_entry(pmd) (false)

static inline struct page *pmd_page(pmd_t pmd) { return NULL; }
static inline void clear_page_mlock(struct page *page) {}
static inline void mmu_notifier_range_init(struct mmu_notifier_range *range,
                      unsigned long action, unsigned long flags,
                      struct vm_area_struct *vma,
                      struct mm_struct *mm,
                      unsigned long start,
                      unsigned long end) {}
static inline void mmu_notifier_invalidate_range_start(struct mmu_notifier_range *range) {}
static inline void mmu_notifier_invalidate_range_only_end(struct mmu_notifier_range *range) {}
static inline spinlock_t *pmd_lock(struct mm_struct *mm, pmd_t *pmd) { return NULL; }
static inline void __split_huge_pmd_locked(struct vm_area_struct *vma, pmd_t *pmd,
                      unsigned long address, bool freeze) {}
static inline void spin_unlock(spinlock_t *lock) {}