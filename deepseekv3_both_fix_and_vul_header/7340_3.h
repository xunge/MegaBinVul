#include <stdbool.h>
#include <stddef.h>

struct mmu_gather;
struct page;

struct vm_area_struct {
    struct mm_struct *vm_mm;
};

struct mm_struct;
struct hstate;

struct mmu_notifier_range {
    unsigned long start;
    unsigned long end;
};

typedef struct {
    unsigned long pte;
} pte_t;

typedef struct {
} spinlock_t;

#define PUD_MASK 0
#define PUD_SIZE 0
#define HPAGE_RESV_UNMAPPED 0
#define MMU_NOTIFY_UNMAP 0

#define WARN_ON(condition) ((void)0)
#define BUG_ON(condition) ((void)0)
#define unlikely(x) (x)

static inline void spin_unlock(spinlock_t *lock) {}
static inline void tlb_flush_pmd_range(struct mmu_gather *tlb, unsigned long addr, unsigned long size) {}
static inline void tlb_flush_mmu_tlbonly(struct mmu_gather *tlb) {}
static inline void tlb_remove_page_size(struct mmu_gather *tlb, struct page *page, unsigned long size) {}
static inline void tlb_remove_huge_tlb_entry(struct hstate *h, struct mmu_gather *tlb, pte_t *ptep, unsigned long address) {}
static inline void tlb_end_vma(struct mmu_gather *tlb, struct vm_area_struct *vma) {}
static inline void tlb_start_vma(struct mmu_gather *tlb, struct vm_area_struct *vma) {}
static inline void tlb_change_page_size(struct mmu_gather *tlb, unsigned long size) {}
static inline void mmu_notifier_invalidate_range_end(struct mmu_notifier_range *range) {}
static inline void mmu_notifier_invalidate_range_start(struct mmu_notifier_range *range) {}
static inline void adjust_range_if_pmd_sharing_possible(struct vm_area_struct *vma, unsigned long *start, unsigned long *end) {}
static inline void mmu_notifier_range_init(struct mmu_notifier_range *range, int type, int flags, struct vm_area_struct *vma, struct mm_struct *mm, unsigned long start, unsigned long end) {}
static inline void set_vma_resv_flags(struct vm_area_struct *vma, int flags) {}
static inline void page_remove_rmap(struct page *page, bool compound) {}
static inline void set_page_dirty(struct page *page) {}
static inline void hugetlb_count_sub(unsigned long count, struct mm_struct *mm) {}
static inline struct page *pte_page(pte_t pte) { return NULL; }
static inline void huge_pte_clear(struct mm_struct *mm, unsigned long addr, pte_t *ptep, unsigned long sz) {}
static inline bool pte_present(pte_t pte) { return false; }
static inline pte_t huge_ptep_get_and_clear(struct mm_struct *mm, unsigned long addr, pte_t *ptep) { pte_t pte; return pte; }
static inline bool huge_pte_none(pte_t pte) { return false; }
static inline pte_t huge_ptep_get(pte_t *ptep) { pte_t pte; return pte; }
static inline bool huge_pmd_unshare(struct mm_struct *mm, struct vm_area_struct *vma, unsigned long *addr, pte_t *ptep) { return false; }
static inline spinlock_t *huge_pte_lock(struct hstate *h, struct mm_struct *mm, pte_t *ptep) { return NULL; }
static inline pte_t *huge_pte_offset(struct mm_struct *mm, unsigned long addr, unsigned long sz) { return NULL; }
static inline unsigned long huge_page_size(struct hstate *h) { return 0; }
static inline unsigned long huge_page_mask(struct hstate *h) { return 0; }
static inline unsigned long pages_per_huge_page(struct hstate *h) { return 0; }
static inline bool huge_pte_dirty(pte_t pte) { return false; }
static inline bool is_vm_hugetlb_page(struct vm_area_struct *vma) { return false; }
static inline struct hstate *hstate_vma(struct vm_area_struct *vma) { return NULL; }