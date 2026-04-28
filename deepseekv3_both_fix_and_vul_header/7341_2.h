#include <stddef.h>

struct file {
    struct address_space *f_mapping;
};

struct address_space;

struct vm_area_struct {
    struct mm_struct *vm_mm;
    struct file *vm_file;
    unsigned long vm_start;
    unsigned long vm_end;
};

struct mm_struct;
struct hstate;

struct mmu_notifier_range {
    unsigned long start;
    unsigned long end;
};

typedef struct { } pte_t;

#define MMU_NOTIFY_CLEAR 0

static inline struct hstate *hstate_vma(struct vm_area_struct *vma) { return NULL; }
static inline unsigned long huge_page_size(struct hstate *h) { return 0; }
static inline void mmu_notifier_range_init(struct mmu_notifier_range *range,
    unsigned int type, unsigned long flags, struct vm_area_struct *vma,
    struct mm_struct *mm, unsigned long start, unsigned long end) {}
static inline void adjust_range_if_pmd_sharing_possible(struct vm_area_struct *vma,
    unsigned long *start, unsigned long *end) {}
static inline void mmu_notifier_invalidate_range_start(struct mmu_notifier_range *range) {}
static inline void i_mmap_lock_write(struct address_space *mapping) {}
static inline pte_t *huge_pte_offset(struct mm_struct *mm, unsigned long addr, unsigned long sz) { return NULL; }
static inline pte_t huge_ptep_get(pte_t *ptep) { return (pte_t){}; }
static inline int huge_pte_none(pte_t pte) { return 0; }
static inline int huge_pmd_unshare(struct mm_struct *mm, struct vm_area_struct *vma,
    unsigned long *addr, pte_t *ptep) { return 0; }
static inline pte_t *huge_pte_alloc(struct mm_struct *mm, struct vm_area_struct *vma,
    unsigned long addr, unsigned long sz) { return NULL; }
static inline void move_huge_pte(struct vm_area_struct *vma, unsigned long old_addr,
    unsigned long new_addr, pte_t *src_pte) {}
static inline void i_mmap_unlock_write(struct address_space *mapping) {}
static inline void flush_tlb_range(struct vm_area_struct *vma, unsigned long start,
    unsigned long end) {}
static inline void mmu_notifier_invalidate_range_end(struct mmu_notifier_range *range) {}