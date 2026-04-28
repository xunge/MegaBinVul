#include <stdbool.h>
#include <stddef.h>

#define HPAGE_PMD_MASK (~(HPAGE_PMD_SIZE - 1))
#define HPAGE_PMD_SIZE ((1UL) << PMD_SHIFT)
#define PMD_SHIFT 21
#define PMD_SIZE (1UL << PMD_SHIFT)
#define SINGLE_DEPTH_NESTING 1

struct vm_area_struct {
    struct mm_struct *vm_mm;
};
struct mm_struct;

typedef struct {
    unsigned long pmd;
} pmd_t;

typedef struct {
    int dummy;
} pgtable_t;

typedef struct {
    int lock;
} spinlock_t;

#define WARN_ON(cond) (cond)
#define VM_BUG_ON(cond) (cond)

static inline int pmd_none(pmd_t pmd) { return 0; }
static inline int pmd_trans_huge(pmd_t pmd) { return 0; }
static inline int pmd_present(pmd_t pmd) { return 0; }
static inline int pmd_dirty(pmd_t pmd) { return 0; }

static inline spinlock_t* __pmd_trans_huge_lock(pmd_t *pmd, struct vm_area_struct *vma) { return NULL; }
static inline spinlock_t* pmd_lockptr(struct mm_struct *mm, pmd_t *pmd) { return NULL; }
static inline void spin_lock_nested(spinlock_t *lock, int subclass) {}
static inline void spin_unlock(spinlock_t *lock) {}
static inline pmd_t pmdp_huge_get_and_clear(struct mm_struct *mm, unsigned long addr, pmd_t *pmd) { pmd_t p = {0}; return p; }
static inline int pmd_move_must_withdraw(spinlock_t *new_ptl, spinlock_t *old_ptl, struct vm_area_struct *vma) { return 0; }
static inline pgtable_t pgtable_trans_huge_withdraw(struct mm_struct *mm, pmd_t *pmd) { pgtable_t p = {0}; return p; }
static inline void pgtable_trans_huge_deposit(struct mm_struct *mm, pmd_t *pmd, pgtable_t pgtable) {}
static inline pmd_t move_soft_dirty_pmd(pmd_t pmd) { return pmd; }
static inline void set_pmd_at(struct mm_struct *mm, unsigned long addr, pmd_t *pmd, pmd_t entry) {}
static inline void flush_tlb_range(struct vm_area_struct *vma, unsigned long start, unsigned long end) {}